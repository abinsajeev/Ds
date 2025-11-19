#include <stdio.h>
int is_member(int set[],int size, int ele) {
    int i;
    for(i=0;i<size;i++) {
        if(set[i]==ele)
            return 1;
    }
    return 0;
}
void input(int set[],int size) {
    int i,ele;
    for(i=0;i<size;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d",&ele);
        if(is_member(set,size,ele)==0) {
            set[i]=ele;
        }
        else{
            printf("Duplicate element; not added\n");
            i--;
        }  
            
    }
}
void display(int set[], int size) {
    printf("{ ");
    for (int i=0;i<size;i++) {
        printf("%d ",set[i]);
    }
    printf("}\n");
}
void UNION(int res[],int set1[],int set2[],int size1,int size2) {
    int i;
    int n=size1;
    for(i=0;i<size1;i++)
        res[i]=set1[i];
    for(i=0;i<size2;i++) {
        if(is_member(res,size1,set2[i])==0)
            res[n++]=set2[i];
    }
    display(res,n);
}
void INTERSECTION(int res[],int set1[],int set2[],int size1,int size2) {
    int i,n=0;
    for(i=0;i<size2;i++) {
        if(is_member(set1,size1,set2[i])==1){
            res[n]=set2[i];
            n++;
        }
    }
    display(res,n);
}

void main(){
    int ch,set1[20],set2[20],result[20],ele,n1,n2;

    while(ch!=5)
    {   
        printf("\n1. INSERT\n2. DISPLAY\n3. UNION\n4.INTERSECTION\n5.EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter size of set1: ");
            scanf("%d",&n1);
            input(set1,n1);
            printf("Enter size of set2: ");
            scanf("%d",&n2);
            input(set2,n2);
            break;
        case 2: 
            display(set1,n1);
            display(set2,n2);
            break;
        case 3: UNION(result,set1,set2,n1,n2);
            break;
        case 4: INTERSECTION(result,set1,set2,n1,n2);
            break;
        }
    }
}