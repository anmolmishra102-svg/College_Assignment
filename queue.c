#include <stdio.h>
#include <stdlib.h>

// Full vs Empty is distinguished using a separate 'count' variable:
//   empty -> count == 0
//   full  -> count == capacity
typedef struct {
    int *arr;
    int front, rear, count, capacity;
} CircularQueue;

void init(CircularQueue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(CircularQueue *q) { return q->count == 0; }
int isFull(CircularQueue *q)  { return q->count == q->capacity; }

void enqueue(CircularQueue *q, int x) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot enqueue %d\n", x);
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->count++;
    printf("%d enqueued.\n", x);
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Nothing to dequeue.\n");
        return;
    }
    printf("%d dequeued.\n", q->arr[q->front]);
    q->front = (q->front + 1) % q->capacity;
    q->count--;
}

void frontElement(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY.\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY.\n");
        return;
    }
    printf("Queue (front -> rear): ");
    for (int i = 0; i < q->count; i++)
        printf("%d ", q->arr[(q->front + i) % q->capacity]);
    printf("\n");
}

int main() {
    CircularQueue q;
    int size, choice, x;

    printf("Enter queue size: ");
    scanf("%d", &size);
    init(&q, size);

    do {
        printf("\n1.ENQUEUE  2.DEQUEUE  3.FRONT  4.DISPLAY  5.EXIT\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); enqueue(&q, x); break;
            case 2: dequeue(&q); break;
            case 3: frontElement(&q); break;
            case 4: display(&q); break;
            case 5: printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free(q.arr);
    return 0;
}
