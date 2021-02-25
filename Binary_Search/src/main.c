/****************************************************************************
*		FILE NAME	:  main.c
*		DESCRIPTION	:  This files contains functions definitions.
*		DATE			NAME			
*		03-01-2019		SUMIT KUMAR		
*
****************************************************************************/

/* Header File */
#include <binary_search.h>

/******************************************************************************
*
*       FUNCTION NAME   : main
*       DESCRIPTION     : Read input from user for array's elements and search.
*
*******************************************************************************/
int main()
{
    int arr[MAX_LENGTH];
    int i = 0,
	    n = 0,
		item = -1,
		beg = -1,
		end = -1,
		return_value = 0;

    printf("Enter No. of Elements in Array is : ");
    scanf("%d",&n);

    printf("\nEnter %d Elements.\n", n);
    
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

	return_value = display(arr, n);
    
	printf("\n\nEnter the Element to be Search.");
    scanf("%d",&item);
    
	beg = 0;
	end = n - 1;

	return_value = binary_search(arr, beg, end, item);

    if(0 == return_value)
	{
        printf("Element not found.\n");
	}
	else
		printf("Element found at %d index.\n", return_value);

    return 0;
}
