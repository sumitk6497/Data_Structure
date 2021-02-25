/****************************************************************************
*		FILE NAME	:  main.c
*		DESCRIPTION	:  This files contains functions definitions.
*		DATE			NAME			
*		19-12-2019		SUMIT KUMAR		
*
****************************************************************************/

/* Header File */
#include<linear_search.h>

/******************************************************************************
*
*       FUNCTION NAME   : main
*       DESCRIPTION     : read a  input file name  as  command line argument.
*
*******************************************************************************/
int main()
{
    int arr[MAX_LENGTH];
    int i = 0,
	    n = 0,
		item = -1,
		return_value = 0;

    printf("Enter No. of Elements in Array is : ");
    scanf("%d",&n);

    printf("\nEnter %d Elements.\n", n);
    
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

	return_value = display(arr, n);
    
	printf("\n\nEnter the Element to be Search.");
    scanf("%d",&item);
    
	return_value = linear_search(arr, n, item);

    if(0 == return_value)
	{
        printf("Element not found.");
	}
	else
		printf("Element found at %d index.", return_value);

    return 0;
}
