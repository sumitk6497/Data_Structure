/****************************************************************************
*		FILE NAME	:  func_ptr.c
*		DESCRIPTION	:  This files contains functions definations.
*		DATE			NAME			
*		19-12-2019		SUMIT KUMAR		
*
****************************************************************************/

/* Header File */
#include <linear_search.h>


/******************************************************************************
*       Function Name   : linear_search
*       Description     : Comparision between two string.
*       Returns         : Return 1 if string 1 is greater than string 2 and 
			  return -1 if string 1 is less than string 1.
*
*******************************************************************************/
int linear_search(int arr[], int n, int item)
{
	int i = 0;
	for(i=0; i<n; i++)
    {
        if(arr[i]==item)
		{
            return i;
            break;
		}
    }
    if(i==n)
    {
		return FAILURE;
	}
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
