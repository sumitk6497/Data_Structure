#include <stdio.h>
#include <stdlib.h>

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

    for(i=0;i<n;i++)
    {
        if(a[i]==s){
            printf("Element found in %d location.\n",i);
            break;}
    }
    if(i==n)
        printf("Element not found.\n");
    return 0;
}
