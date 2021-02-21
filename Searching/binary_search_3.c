#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[30];
    int i,n,s;
    int beg,mid,end;

    printf("Enter No. of Elements in Array : ");
    scanf("%d",&n);

    printf("Enter %d Elements.\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the Element to be Search.");
    scanf("%d",&s);

    beg=0;
    end=n-1;
    mid=(beg+end)/2;

    while(beg<=end)
    {
        if(a[mid]<s)
            beg=mid+1;
        else if(a[mid]==s)
          {
            printf("Elements found at %d location\n",mid);
        break;
          }
        else
          end=mid-1;
          mid=(beg+end)/2;
    }
    if (beg>end)
        printf("Element not found.!!!\n");

    return 0;
}

