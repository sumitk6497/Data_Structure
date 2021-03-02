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


NODE *reverseLL(NODE *head)
{
	NODE *prev = NULL;
	NODE *current = head;
	NODE *Next;

	while(current != NULL)
	{
	    Next = current->next;
	    current->next = prev;
	    prev = current;
	    current = Next;
	}
	return prev;
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
	head = reverseLL(head);
	displayList(head);

	deleteList(&head);
	return 0;
}
