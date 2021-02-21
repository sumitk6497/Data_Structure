#include <stdio.h>
#include <stdlib.h>

int binary(int a[], int l,int n,int x)
{
    if(n>=l) {
       int mid = l + (n-l)/2;

       if(a[mid]==x)
        return mid;

       if(a[mid]>x)
          return binary(a,l,mid-1,x);
       else
          return binary(a,mid+1,n,x);
    }
    return -1;
}

int main()
{
    int a[6]={6,7,3,9,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    int x;

    printf("Enter a no. you want to search : ");
    scanf("%d",&x);

    int p = binary(a,0,n-1,x);

    if (p == -1)
        printf("Element not found..!!!!!!");
    else
        printf("Element fount at %d locaton",p);

    return 0;
}
