#include <stdio.h>
#include <stdlib.h>

int linear(int a[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==x)
          return i;
    return -1;
} 


int main()
{
    int a[6]={6,7,3,9,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    int x;
    printf("Enter a no. you want to search : ");
    scanf("%d",&x);

    int p = linear(a,n,x);
    if (p == -1)
        printf("Element not found..!!!!!!\n");
    else
        printf("Element fount at %d locaton..!!!!\n",p);

    return 0;
}
