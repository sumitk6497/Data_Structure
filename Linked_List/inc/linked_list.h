/***********************************************************

	FILENAME : linked_list.h

************************************************************/

#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAX_SIZE 255

#define DISPLAY 1
#define INSERT_FIRST 2
#define INSERT_END 3
#define INSERT_POS 4
#define DELETE_FIRST 5
#define DELETE_END 6
#define DELETE_POS 7
#define EXIT 8 

/**** Structure Definations  ****/
typedef struct node_list
{
	char *name;
	char ch;
	int ID;
	struct node_list *next;
}NODE;

/**** Function Declarrations  ****/
extern int isempty(NODE *head);
extern NODE *insert_first(NODE **head);
extern NODE *insert_last(NODE **head);
extern NODE *insert_after(NODE **head, int position);
extern NODE *delete_first(NODE **head);
extern NODE *delete_first(NODE **head);
extern NODE *delete_after(NODE **head, int position);
extern int display(NODE *head);

#endif
