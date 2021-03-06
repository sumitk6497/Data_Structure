#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


bool isPalindromeUntil(NODE **left, NODE *right)
{
	if(right == NULL)
	    return true;

	bool checkPalin = isPalindromeUntil(left, right->next);
	if(checkPalin == false)
	    return false;

	bool checkNodeData = (right->data == (*left)->data);

	*left = (*left)->next;

	return checkNodeData;

}

bool isPalindrome(NODE *head)
{
	isPalindromeUntil(&head, head);

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
	head->next->next->next = newNode(2);
	head->next->next->next->next = newNode(1);

	displayList(head);
	int LL_checkPalin = isPalindrome(head);
	
	printf("%d\n", LL_checkPalin);

	isPalindrome(head) ? printf("LL is Palindrome...!!!\n") : printf("LL is not Palindrome...!!!!\n");

	if(LL_checkPalin == 0)
	    printf("Linked list is not Palindrome.....!!!!!\n");
	else
	    printf("Linked list is Palindrome......!!!!!!!\n");

	deleteList(&head);
	return 0;
}
