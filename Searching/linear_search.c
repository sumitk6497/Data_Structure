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
    int a[30];
    int i,n,s;

    printf("Enter No. of Elements in Array : ");
    scanf("%d",&n);

    printf("Enter %d Elements.\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the Element to be Search : ");
    scanf("%d",&s);

    int p = linear(a,n,s);
    if (p == -1)
        printf("Element not found..!!!!!!\n");
    else
        printf("Element fount at %d locaton..!!!!!\n",p);
    return 0;
}


