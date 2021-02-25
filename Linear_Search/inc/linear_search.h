/****************************************************************************
*		FILE NAME	:  linear_search.h
*		DESCRIPTION	:  This files contains functions prototypes
				   standard header files and macros.
*		DATE			NAME			
*		03-01-2019		SUMIT KUMAR		
*
****************************************************************************/

#ifndef __LINEAR_SEARCH_H_
#define __LINEAR_SEARCH_H_

/*******************************************************************************
*                       STANDARD HEADER FILES
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>


/******************************************************************************
				MACROS
*******************************************************************************/
#define SUCCESS 1
#define FAILURE 0
#define MAX_LENGTH 30


/*******************************************************************************
*                       FUNCTION PROTOTYPES
*******************************************************************************/
extern int linear_search(int arr[], int n, int item);
extern int display(int arr[], int n);


#endif
