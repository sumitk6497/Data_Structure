/*******************************************************************************
*
*     FILENAME       :    main.c
*     DESCRIPTION    :    This file contains the various operations of
			  single linked list.
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linked_list.h>

int main()
{
	int a = 0,
	    ret_val = 0,
	    position = 0;
	char b;
	NODE *head = NULL;

	printf("****Linked List Operations****\n");

	do
	{
	    printf("\n#1.Display.\n#2.Insertion in begining.\n#3.Insertion at last.\n#4.Insertion at position.\n#5.Deletion at begining.\n#6.Deletion at last.\n#7.Deletion at position.\n#8.Exit\n");

	    printf("\nEnter Your choice->");
	    scanf("%d",&a);
	    switch(a)
	     {
	        case DISPLAY:
	           ret_val = display(head);
	           break;
	        case INSERT_FIRST:
	           insert_first(&head);
	           break;
	        case INSERT_END:
	           insert_last(&head);
	           break;
	        case INSERT_POS:
		   printf("Enter position : ");
		   scanf("%d",&position);
	           insert_after(&head,position);
	           break;
	        case DELETE_FIRST:
	           delete_first(&head);
	           break;
	        case DELETE_END:
	           delete_last(&head);
	           break;
	        case DELETE_POS:
	 		   printf("Enter position : ");
			   scanf("%d",&position);
	           delete_after(&head,position);
	           break;
	        case EXIT:
	           exit(0);
	           break;

	        default :
	            printf("Wrong Choice!!");
	     }
	     printf("\nPress 0 to exit........\n\n");
	  }
	   while (b !='0');
    return 0;
}

