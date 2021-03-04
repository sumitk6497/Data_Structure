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

int countNode(NODE *node)
{
	int count = 1;
	NODE *current = node;

	while(current->next != node)
	{
	    count++;
	    current = current->next;
	}
	return count;
}

int countNodesInLoop(NODE *head)
{
	NODE *slow = head;
	NODE *fast = head;

	while(slow && fast && fast->next)
	{
	    slow = slow->next;
	    fast = fast->next->next;
	    if(slow == fast)
	        return countNode(slow);
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

	head->next->next->next->next = head->next;

	int countNode = countNodesInLoop(head);
	if(countNode == 0)
	    printf("Loop not found.\n");
	else
	    printf("Total no. of Nodes in Loop : %d\n", countNode);

	return 0;
}
