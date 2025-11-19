#include <stdio.h>
#include <stdlib.h>
#define n 9
int arr[n]={10,20,30,40,50,60,70,80,90} ;

void search(){
    int s,pos,i,flag=0;
    printf("enter the element to search: ");
    scanf("%d" ,&s);
    for(i=0;i<n;i++){
        if(arr[i]==s){
            printf("\nPosition: %d",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element not found");
}
 
void traverse(){
    int i;
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

int main(){
    int choice,s;
    printf("%d",n);
    printf("\n 1.search \n2.traverse");
    printf("\nenter your choice ");
    scanf("%d",&choice);
    switch(choice){
        case 1: search();
            break;
        case 2: traverse();
            break;
        default: printf("invalid input\n");
    }
  
  return 0;
}