#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check whether queue is empty
int isEmpty()
{
    return front == -1;
}

// Check whether queue is full
int isFull()
{
    return (rear + 1) % MAX == front;
}

// ENQUEUE operation
void ENQUEUE(int x)
{
    if (isFull())
    {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("%d inserted into queue.\n", x);
}

// DEQUEUE operation
void DEQUEUE()
{
    if (isEmpty())
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    // Only one element was present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// FRONT operation
void FRONT()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

// DISPLAY operation
void DISPLAY()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                ENQUEUE(value);
                break;

            case 2:
                DEQUEUE();
                break;

            case 3:
                FRONT();
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
