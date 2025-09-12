#include <stdio.h>
#include <stdlib.h>
#define max 5
int front=-1, rear=-1;
int QUEUE[max];
void insert() {
    int n;
    if(rear==max-1) {
        printf("Queue Overflow");
        exit(0);
    }
    else
    {
        scanf("%d", &n);
        if(front==-1)
            front=front+1;
        rear=rear+1;
        QUEUE[rear]=n;
    }
}
void main()
{
    int i,n,rev=0,curr=0;
    printf("Enter the no. of digtis: ");
    scanf("%d",&n);
    printf("Enter the number: ");
    for(i=0;i<n;i++)
    {
        insert();
        curr=curr*10+QUEUE[i];
    }
    for(i=n;i>=0;i--)
        rev=rev*10+QUEUE[i];

    if(curr==rev)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    
}