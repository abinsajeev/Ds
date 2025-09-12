#include<stdio.h>
#define max 5
char STACK[max], top=-1;

void main()
{
    int i;
    char n;
    printf("Enter the size of string: ");
    scanf("%d", &n);
    printf("Enter the string: ");
    for (i = 0; i<n; i++)
    {
        if (top==max-1) {
            printf("Stack Overflow");
            break;
        }
        
        else {
            
            scanf("%c",&STACK[i]);
            top=top+1;
        }
    }
    for(i=0;i<=n;i++)
        printf("%c",STACK[i]);
    
}