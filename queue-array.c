#include <stdio.h>
#define max 10
int front=-1, rear=-1;
int QUEUE[max];

void insert() {
    int n;
    if(rear==max-1)
        printf("Queue Overflow");
    else
    {
        printf("Enter the number: ");
        scanf("%d", &n);
        if(front==-1)
            front=front+1;
        rear=rear+1;
        QUEUE[rear]=n;
        printf("Insertion Successfull");
    }
}

void delete() {
    int n;
    if(front==-1)
        printf("Queue Underflow");
    else
    {
        n=QUEUE[front];
        front=front+1;
        printf("%d is deleted", n);
    }
}
 
void display() {
    int i;
    if (front==1 && rear==-1)
        printf("Queue is empty");
    else
    {
        printf("Queue elements are:\n");
        for(i=front;i<=rear;i++) {
            printf("%d ", QUEUE[i]);
        }
    }
    
}

void main() 
{
    int ch;
    printf("QUEUE IMPLEMENTATION USING ARRAY\n");
    while(ch!=4) {
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
        }
    }
}
