/********************************************************

	FILENAME    :  linked_list.c

*********************************************************/

#include <linked_list.h>

/*****************************************************************
*     FUNCTION NAME   : isempty
*     DESCRIPTION     : This function checks whether the list is     
*                       empty or not.
*     RETURNS         : 1 if it is empty and 0 if not.
******************************************************************/
int isempty(NODE *head)
{
	if(head == NULL)
	{
	   return 1;	
	}
	else
	    return 0;
}


/*******************************************************************
*	FUNCTION NAME   : display
*	DESCRIPTION     : This function display the data of list.
*******************************************************************/
int display(NODE *head)
{
	int i=1;
	NODE *temp = NULL;
	temp = head;

	/* Check if the list is empty */
	if(isempty(temp))
	{
	   printf("List is empty.....!!!!\n");
	   return 0;
	}
	else
	{
	    while(temp != NULL)
	    {
			printf("Node %d content -----\n",i);   
			printf("Name : %s\n",temp->name);
			printf("Character : %c\n",temp->ch);
			printf("ID : %d\n",temp->ID);
			temp = temp->next;
			i++;
	    }
	    return 1;
	}
}


/***********************************************************************
*	FUNCTION NAME    : insert_fisrt
*	DESCRIPTION      : This function insert new node at the begining
			   of the list.
***********************************************************************/
NODE * insert_first(NODE **head)
{
	int n;
	int ID;
	char ch;
	char buff[MAX_SIZE];
	NODE *new_node = NULL;
	//new_node = memset(new_node, 0, sizeof(NODE));
	new_node = (NODE *)malloc(sizeof(NODE));


	/* Check if the list is empty */
	if(NULL == new_node)
	{
	   printf("Memory is not available...!!!!\n");
	   exit(0);
	}
	else
	{
	    printf("Enter name : ");
	    scanf("%s",buff);
	    n = strlen(buff);
	    new_node->name = (char *)malloc(sizeof(char) * n + 1);
	    new_node->name = strcpy(new_node->name,buff);
	    
	    printf("Enter character : ");
	    scanf(" %c", &ch);
	    new_node->ch = ch;
	    
	    printf("Enter ID : ");
	    scanf("%d",&ID);
	    new_node->ID = ID;

	    new_node->next = *head;
	    *head = new_node;
	    return head;
	}
}


/***********************************************************************
*	FUNCTION NAME    : insert_last
*	DESCRIPTION      : This function insert new node at the end
			   of the list.
***********************************************************************/
NODE * insert_last(NODE **head)
{
	int n;
	int ID;
	char ch;
	char buff[MAX_SIZE];
	NODE *new_node =  NULL;
	NODE *temp = NULL;

	//new_node = memset(new_node, 0, sizeof(NODE ));
	new_node = (NODE *)malloc(sizeof(NODE));

	/* Check if the list is empty */
	if(NULL == new_node)
	{
	   printf("Memory is not available...!!!!\n");
	   exit(0);
	}
	else
	{
	    printf("Enter name : ");
	    scanf("%s",buff);
	    n = strlen(buff);
	    new_node->name = (char *)malloc(sizeof(char) * n + 1);
	    new_node->name = strcpy(new_node->name,buff);
	    
	    printf("Enter character : ");
	    scanf(" %c", &ch);
	    new_node->ch = ch;
	    
	    printf("Enter ID : ");
	    scanf("%d",&ID);
	    new_node->ID = ID;

	    if(head == NULL)
	    {
	       head = new_node;
	    }
	    else
	    {
		temp = *head;
		while(temp->next != NULL)
		{
		    temp = temp->next;
		}
		temp->next = new_node;
		new_node->next = NULL;
	    }
	    return head;
	}
}


/***********************************************************************
*	FUNCTION NAME    : insert_after
*	DESCRIPTION      : This function insert new node at the given
			   position of the list.
***********************************************************************/
NODE * insert_after(NODE **head, int position)
{
	int n,
	    count=1;
	int ID;
	char ch;
	char buff[MAX_SIZE];
	NODE *new_node = NULL;
	NODE *temp = NULL;
	

	//new_node = memset(new_node, 0, sizeof(NODE ));
	new_node = (NODE *)malloc(sizeof(NODE));

	/* Check if the list is empty */
	if(NULL == new_node)
	{
	   printf("Memory is not available...!!!!\n");
	   exit(0);
	}
	else
	{
	    printf("Enter name : ");
	    scanf("%s",buff);
	    n = strlen(buff);
	    new_node->name = (char *)malloc(sizeof(char) * n + 1);
	    new_node->name = strcpy(new_node -> name,buff);
	    
	    printf("Enter character : ");
	    scanf(" %c", &ch);
	    new_node->ch = ch;
	    
	    printf("Enter ID : ");
	    scanf("%d",&ID);
	    new_node->ID = ID;

	    if(head == NULL || position == 0)
	    {
	       head = new_node;
	    }
	    else
	    {
		temp = *head;
		while(temp->next != NULL)
		{
		   if(count == position)
		   {
		      new_node->next = temp->next;
		      temp->next = new_node;
		   }
		   temp = temp->next;
		   count++;
		}
		
		return head;
	     }
	   }
}


/***********************************************************************
*	FUNCTION NAME    : delete_fisrt
*	DESCRIPTION      : This function delete a node at the begining
			   of the list.
***********************************************************************/
NODE * delete_first(NODE **head)
{
	NODE *temp = NULL; /* Temporary node pointer to traverse the list */
	temp = *head;

	/* Check if the list is empty */
	if (NULL == *head)
	{
	   printf("List is empty.....!!!!\n");
           return head;
	}

	if (temp->next == NULL)
	{
	    free(temp->name);
            *head = NULL;
	}
	else
	{
	    free(temp->name);
            *head = temp->next;
	}

	free(temp);
	return head;

}


/***********************************************************************
*	FUNCTION NAME    : delete_last
*	DESCRIPTION      : This function delete a node at the end
			   of the list.
***********************************************************************/
NODE * delete_last(NODE **head) 
{
	NODE *current = NULL; /* Temporary node pointer to traverse the list */
	NODE *temp = NULL; /* Temporary node pointer to traverse the list */
	current = *head;

	if(isempty(*head))
	{
	   printf("List is empty.....!!!!\n");
           return 0;
	}
	else if (current->next == NULL)
	{
           *head = NULL;
           free(current->name);
           free(current);
           return head;
	}
	else
	{
           while(current->next->next != NULL)
           {
                current = current->next;
           }
           temp = current->next;
           current->next = NULL;
           free(temp->name);
           free(temp);
           return head;
	}
}


/***********************************************************************
*	FUNCTION NAME    : delete_after
*	DESCRIPTION      : This function delete a node at the given
			   position of the list.
***********************************************************************/
NODE * delete_after(NODE **head, int position) 
{ 
	int i = 0;
	NODE* temp = *head; 
	// If linked list is empty 
	if (*head == NULL) 
    {   
	  return; 
	}
	
	if (position == 0) 
	{ 
	      *head = temp->next;   // Change head 
	      free(temp->name);               // free old head 
	      free(temp);               // free old head 
	      return; 
	} 
	
	// Find previous node of the node to be deleted 
	for (i=0; temp!=NULL && i<position; i++) 
	{
	  temp = temp->next; 
	}

	// If position is more than number of ndoes 
	if (temp == NULL || temp->next == NULL) 
	{
	   return; 
	}

	NODE *next = temp->next->next; 
																												    
	free(temp->name);               // free old head 
	// Unlink the node from linked list 
	free(temp->next);  // Free memory 
																															  
	temp->next = next;  // Unlink the deleted node from list 
} 
