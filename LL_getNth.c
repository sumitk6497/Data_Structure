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
int GetNth_iterative(NODE *head, int index)
{
	int count = 0;
	NODE *current = head;

	while(current != NULL)
	{
	    if(count == index)
	        return current->data;

	    count++;
	    current = current->next;
	}
	return -1;
}

// Recursive
int GetNth_recursive(NODE *head, int index)
{
	if(head == NULL)
	    return -1;

	if(index == 0)
	    return head->data;

	return GetNth_recursive(head->next, index - 1);

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

	int getNth_ite = GetNth_iterative(head,1);
	printf("Node Data (Iterative) : %d\n", getNth_ite);

	int getNth_rec = GetNth_recursive(head,3);
	printf("Node Data (Recurive)  : %d\n", getNth_rec);
	
	getNth_ite = GetNth_iterative(head,7);
	printf("Node Data (Iterative) : %d\n", getNth_ite);

	getNth_rec = GetNth_recursive(head,6);
	printf("Node Data (Recurive)  : %d\n", getNth_rec);

	deleteList(&head);
	return 0;
}
