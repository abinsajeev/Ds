#include <stdio.h>
void main() {
    int a[10],b[20];
    int n,i,j;
    printf("Enter no. of bits: ");
    scanf("%d",&n);
    printf("Enter set1 in bits: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the set2 in bits: ");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    printf("Set1: { ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("}\n");
    printf("Set2: { ");
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("}\n");
    printf("Union: { ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]|b[i]);
    printf("}\n");
    printf("Intersection: { ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]&b[i]);
    printf("}\n");
    printf("Difference: { ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]&(~b[i]));
    printf("}\n");
}