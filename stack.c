#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;        // index of top element, -1 when empty
    int capacity;
} Stack;

void init(Stack *s, int size) {
    s->arr = (int *)malloc(size * sizeof(int));
    s->capacity = size;
    s->top = -1;
}

int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s)  { return s->top == s->capacity - 1; }

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", x);
        return;
    }
    s->arr[++(s->top)] = x;
    printf("%d pushed.\n", x);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    printf("%d popped.\n", s->arr[(s->top)--]);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int main() {
    Stack s;
    int size, choice, x;

    printf("Enter stack size: ");
    scanf("%d", &size);
    init(&s, size);

    do {
        printf("\n1.PUSH  2.POP  3.PEEK  4.DISPLAY  5.EXIT\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); push(&s, x); break;
            case 2: pop(&s); break;
            case 3: peek(&s); break;
            case 4: display(&s); break;
            case 5: printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free(s.arr);
    return 0;
}
