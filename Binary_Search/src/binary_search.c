/****************************************************************************
*		FILE NAME	:  binary_search.c
*		DESCRIPTION	:  This files contains functions definations.
*		DATE			NAME			
*		03-01-2019		SUMIT KUMAR		
*
****************************************************************************/

/* Header File */
#include <binary_search.h>


/******************************************************************************
*       Function Name   : binary_search
*       Description     : This function search the elements in given array.
*       Returns         : Return element index if element found else FAILURE
*
*******************************************************************************/
int binary_search(int arr[], int beg, int end, int item)
{
	int mid = -1; 
	mid = (beg + end)/2;

	while(beg <= end)
	{
		if(arr[mid]<item)
        {
			beg=mid+1;
		}
		else if(arr[mid]==item)
		{
			return mid;
			break;
		}
		else
			end=mid-1;
			
		mid=(beg+end)/2;
    }

    if (beg > end)
		return FAILURE;
	
}

/*******************************************************************
*	FUNCTION NAME   : display
*	DESCRIPTION     : This function display the elements of array.
*******************************************************************/
int display(int arr[], int n)
{
	int i = 0;
	
	for(i=0; i<n; i++)
    {
        printf("Element at index %d : %d\n", i, arr[i]);
	}

	return SUCCESS;
}
