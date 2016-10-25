#ifndef LIST_H_29092016
#define LIST_H_29092016

// contains c++ code

#include "types.h"
#include "utility.h"
#include "memory.h"

template<class T>
struct list_node
{
	T data;
	list_node* next;
};

template<class T>
struct list
{
	list_node<T>* head;
	list_node<T>* tail;
	uint32 count;		// items in list
};

template<class T>
void list_init(list<T>* l)
{
	l->count = 0;
	l->head = l->tail = 0;
}

template<class T>
void list_remove(list<T>* l, list_node<T>* prev)
{
	if (l->count == 0)
		return;

	if (l->count == 1)		// prev == head
	{
		l->count--;
		delete prev;
		l->head = l->tail = 0;
		return;
	}

	list_node<T>* temp = prev->next;

	prev->next = temp->next;

	delete temp;
	l->count--;

	if (l->count == 0)
		l->head = l->tail = 0;
}

template<class T>
void list_remove_front(list<T>* l)
{
	if (l->count == 0)
		return;

	list_node<T>* temp = l->head;
	l->head = l->head->next;
	l->count--;
	delete temp;

	if (l->count == 0)
		l->head = l->tail = 0;
}

template<class T>
void list_insert_front(list<T>* l, const T& element)
{
	list_node<T>* node = new list_node<T>;
	node->next = 0;
	node->data = element;

	if (l->count == 0)
		l->head = l->tail = node;
	else
	{
		node->next = l->head;
		l->head = node;
	}

	l->count++;
}

template<class T>
void list_insert_back(list<T>* l, const T& element)
{
	list_node<T>* node = new list_node<T>;
	node->next = 0;
	node->data = element;

	if (l->count == 0)
		l->head = l->tail = node;
	else
	{
		l->tail->next = node;
		l->tail = node;
	}

	l->count++;
}

// combines the two lists and stores them in l1. l2 is shallow destroyed.
template<class T>
void list_merge_back(list<T>* l1, list<T>* l2)
{
	l1->count += l2->count;

	l1->tail->next = l2->head;
	l1->tail = l2->tail;

	l2->count = 0;
	l2->head = l2->tail = 0;
}

#endif
