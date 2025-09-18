#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int elem) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", elem);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = elem;
    printf("Inserted %d\n", elem);
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int elem = queue[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
    return elem;
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
        if (i == rear) break;
    }
    printf("\n");
}


int main()
{
   int choice,elem;
   char ch;
  
   do
   {
   printf("select the operation:");
   printf("\n1.enqueue \n2.dequeue \n3.display\n4.exit\n");
   scanf("%d",&choice);
        switch (choice)
         {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &elem);
                enqueue(elem);
                break;
            case 2:
                elem= dequeue();
                if (elem != -1)
                    printf("Dequeued: %d\n", elem);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    printf("\nDo you want to continue? Y / N");
    scanf(" %c",&ch);
}while(ch=='Y' || ch=='y');
return 0;
}

