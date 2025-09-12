#include <stdio.h>
#define max 10
int STACK [max], top=-1;

void push()
{
    int n;
    if (top==max-1)
        printf("Stack Overflow");
    else {
        printf("Enter the number: ");
        scanf("%d",&n);
        top=top+1;
        STACK[top]=n;
        printf("Push successfull\n");
    }
}

void pop()
{
    int n;
    if (top==-1)
        printf("Stack Underflow");
    else {
        n=STACK[top];
        top=top-1;
        printf("%d has been popped\n", n);
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("Stack is empty");
    else
    {
        printf("\nStack elements are: \n");
        for(i=0;i<=top;i++) {
            printf("%d ",STACK[i]);
        }
        printf("\n");
    }
}
void main()
{
    int ch;
    printf("STACK IMPLEMENTATION USING ARRAY\n");
    while(ch!=4) {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
        }
    }
}