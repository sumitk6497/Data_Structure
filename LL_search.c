#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
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
int searchLL_iterative(NODE *head, int x)
{
	NODE *current = head;

	while(current != NULL)
	{
	    if(current->data == x)
	        return 1;
	    current = current->next;
	}
	return 0;
}

// Recursive
int searchLL_recursive(NODE *head, int x)
{
	if(head == NULL)
	    return 0;

	if(head->data == x)
	    return 1;

	return searchLL_recursive(head->next, x);

}

void deleteList(NODE **head)
{
	NODE *current = NULL;
	NODE *temp = NULL;

	current = *head;

	while(current != NULL)
	{
	    temp = current->next;
	    free(current);
	    current = temp;
	}
	*head = NULL;
}

int main()
{
	NODE *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	displayList(head);
	int search_ite = searchLL_iterative(head,2);
	search_ite ? printf("Node Found (Iterative).\n") :printf("Node not found(Iterative).\n");

	int search_rec = searchLL_recursive(head,4);
	search_rec ? printf("Node Found (Recursive).\n") :printf("Node not found(Recursive).\n");
	
	search_ite = searchLL_iterative(head,7);
	search_ite ? printf("Node Found (Iterative).\n") :printf("Node not found(Iterative).\n");

	search_rec = searchLL_recursive(head,0);
	search_rec ? printf("Node Found (Recursive).\n") :printf("Node not found(Recursive).\n");

	deleteList(&head);
	return 0;
}
