#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}NODE;


int detectLoop(NODE *head);
void removeLoop(NODE *fast, NODE *head);

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
int detectLoop(NODE *head)
{
	NODE *slow = head;
	NODE *fast = head;

	while(slow && fast &&fast->next)
	{
	    slow = slow->next;
	    fast = fast->next->next;
	    if(slow == fast)
	    {
	        removeLoop(slow, head);
	        return 1;
	    }
	}
	return 0;
}

void removeLoop(NODE *slow, NODE *head)
{
	NODE *loopNode = NULL;
	NODE *temp = NULL;

	temp = head;
	while(1)
	{
	    loopNode = slow;
	    while(loopNode->next != slow && loopNode->next != temp)
	        loopNode = loopNode->next;
	
	    if(loopNode->next == temp)
	        break;

	    temp = temp->next;
	}
	loopNode->next = NULL;
}

int main()
{
	NODE *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	displayList(head);

	head->next->next->next->next = head->next;
	int detect = detectLoop(head);
	detect ? printf("Loop Found.\n") :printf("Loop not found.\n");

	int detect1 = detectLoop(head);
	detect1 ? printf("Loop Found.\n") :printf("Loop not found.\n");
	return 0;
}
