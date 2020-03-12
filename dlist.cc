/* dlsit.cc */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dlist.h"

DList::DList()
{
    head = NULL;
    tail = NULL;
}

DList::~DList()
{
    assert(head);
    while(head)
    {
		remove(head);
    }
}

void DList::add_to_front(int value)
{
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
	a->val = value;
    if(head == NULL && tail == NULL)
    {
		head = a;
		tail = a;
		a->next = NULL;
		a->prev = NULL;	
    }
    else
    {   
   		a->next = head;
   		a->prev = NULL;
   		head->prev = a;
   		head = a; 
    }
}

void DList::add_to_back(int value)
{
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
    a->val = value;
    if(head == NULL && tail == NULL)
    {
 	  	head = a;
		tail = a;
		a->next = NULL;
		a->prev = NULL;	
    }
	else
    {
    	a->next = NULL;
    	a->prev = tail;
    	tail->next = a;
    	tail = a;
    }
}

int DList::first()
{
    return head->val;
}

int DList::last()
{
    return tail->val;
}

void DList::remove(ListNode* node)
{
    assert(node);
    if(node == head && node == tail)
	{
		head = NULL;
		tail = NULL;
		node->next = NULL;
		node->prev = NULL;
        delete node;
	}
    else if(node == head)
    {
		head = node->next;
    	node->next->prev = NULL;
        node->next = NULL;
        delete node;
    }
    else if(node == tail)
    {
		tail = node->prev;
		node->prev->next = NULL;
		node->prev = NULL;
		delete node;
    }
	else
    {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = NULL;
		node->prev = NULL;
		delete node;
    }
}

ListNode* DList::previous(ListNode* node)
{
    assert(node);
    assert(node->prev);
    return node->prev;
}

ListNode* DList::next(ListNode* node)
{
    assert(node);
    assert(node->next);
    return node->next;
}

ListNode* DList::search_value(int value)
{
    ListNode* x = head;
    while(x->next != NULL)
    {
		if(x->val == value)
			break;
		x = x->next;
    }
    return x;
}

void DList::printList()
{
	ListNode* temp = head;
	printf("{ ");
	while(temp != NULL)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	//printf("%d ", tail->val);
	printf("}\n");
}
/* eof */
