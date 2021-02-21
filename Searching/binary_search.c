#include <stdio.h>
#include <stdlib.h>

int binary(int a[], int l,int n,int s)
{
    if(n>=l) 
    {
       int mid = l + (n-l)/2;

       if(a[mid]==s)
          return mid;

       if(a[mid]>s)
          return binary(a,l,mid-1,s);
       else
          return binary(a,mid+1,n,s);
    }
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

    int p = binary(a,0,n-1,s);
    if (p == -1)
        printf("Element not found..!!!!!!\n");
    else
        printf("Element fount at %d locaton..!!!!!\n",p);
    return 0;
}


