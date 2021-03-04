#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
	int flag;
}NODE;

NODE *newNode(int data)
{
	NODE *new_node = NULL;
	new_node = (NODE *)malloc(sizeof(NODE));
	if(NULL == new_node)
	{
	    printf("Memory is not available...!!!!\n");
	    exit(0);
	}
	else
	{
	    new_node->data = data;
	    new_node->flag = 0;
	    new_node->next = NULL;
	    return new_node;
	}
}

void displayList(NODE *head)
{
	NODE *temp = NULL;
	temp = head;

	if(temp == NULL)
	{
	    printf("List is empty.....!!!!\n");
	}
	else
	{
	    while(temp != NULL)
	    {
	        printf("%d\t",temp->data);
		temp = temp->next;
	    }
	    printf("\n");
	}
}


// Iterative
int detectLoop(NODE *head)
{
	NODE *temp = head;

	while(temp != NULL)
	{
	    if(temp->flag == 1)
	        return 1;

	    temp->flag = 1;
	    temp = temp->next;
	}
	return 0;
}


int main()
{
	NODE *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	displayList(head);

	head->next->next->next->next = head;
	int detect = detectLoop(head);
	detect ? printf("Loop Found.\n") :printf("Loop not found.\n");

	return 0;
}
