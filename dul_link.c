#include <stdio.h>
#include <stdlib.h>

struct _node{
	struct _node *prior;
	struct _node *next;
	int element;
};

struct _list{
	struct _node *FirstNode;
	struct _node *LastNode;
	int len;
};

void Insert_tail(struct _list *list, int data);
void Display(struct _list *list);
void Insert_head(struct _list *list, int data);
void Change(struct _list *list, int pos, int data);
void Delete(struct _list *list, int pos);
void Insert(struct _list *list, int pos, int data);




void Insert_tail(struct _list *list, int data)
{
	struct _node *node = (struct _node *)malloc(sizeof(struct _node));
	node->element = data;
	node->prior = NULL;
	node->next = NULL;
	
	node->prior = list->LastNode;
	if(NULL != list->FirstNode)
	{
		list->LastNode->next = node;
	}
	list->LastNode = node;
	if(0 == list->len)
	{
		list->FirstNode =node;
	}
	list->len++;
	
	return;
}

void Insert_head(struct _list *list, int data)
{
	struct _node *node = (struct _node *)malloc(sizeof(struct _node));
	node->element = data;
	node->prior = NULL;
	node->next = NULL;
	
	node->next = list->FirstNode;
	if(NULL != list->FirstNode)
	{
		list->FirstNode->prior = node;
	}
	list->FirstNode = node;
	if(0 == list->len)
	{
		list->LastNode =node;
	}
	list->len++;
	
	return;
}

void Insert(struct _list *list, int pos, int data)
{
	struct _node *node = (struct _node *)malloc(sizeof(struct _node));
	node->element = data;
	node->prior = NULL;
	node->next = NULL;
	
	struct _node *temp = list->FirstNode;
	for(int i = 1; i < pos; i++)
	{
		temp = temp->next;
	}
	node->prior = temp;
	node->next = temp->next->next;
	
	list->len++;
	return;
}

void Display(struct _list *list)
{
	struct _node *node = list->LastNode;
	int i = list->len;
	printf("******* list->len:%d ********\n", list->len);
	while(node)
	{
		printf("list[%d] = %d\n", i, node->element);
		node = node->prior;
		i--;
	}
	return;
}

void Change(struct _list *list, int pos, int data)
{	
	struct _node *node = list->FirstNode;
	for(int i = 1; i < pos; i++)
	{
		node = node->next;
	}
	printf("***** you want change list[%d]=%d ******\n", pos, data);
	node->element = data;
	
	return;
}

void Delete(struct _list *list, int pos)
{
	struct _node *node = list->FirstNode;
	for(int i = 1; i < pos; i++)
	{
		node = node->next;
	}
	struct _node *del = node;
	del->next->prior = del->prior;
	del->prior->next = del->next;
	
	printf("***** you want delete list[%d] ******\n", pos);
	list->len--;
	free(del);
	
	return;
}

int main()
{
	struct _list list = {NULL,NULL,0};
	Insert_tail(&list, 1);
	Insert_tail(&list, 2);
	Insert_tail(&list, 3);
	Insert_head(&list, 4);
	Insert_head(&list, 5);
	Insert_head(&list, 6);
	Display(&list);
	Change(&list , 2, 100);
	Display(&list);
	Delete(&list, 3);
	Display(&list);
	Insert(&list, 4, 1000);
	Display(&list);
	
	return;
}
