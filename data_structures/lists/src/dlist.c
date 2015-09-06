#include "../include/dlist.h"
#include "../include/dnode.h"
#include "../include/ptr_func.h"
#include <string.h>
#include <stdlib.h>

void	dlist_create(t_dlist* list, ptr_delete func)
{
	bzero(list, sizeof(*list));
	list->func = func;
}

void	dlist_destroy(t_dlist* list)
{
	t_dnode* node;
	t_dnode* temp;

	node = list->first;
	while(node != NULL)
	{
		temp = node->next;
		dnode_destroy(list->func, node);
		free(node);
		node = temp;
	}
	bzero(list, sizeof(*list));
}

void	dlist_clear(t_dlist* list)
{
	dlist_destroy(list);
}

void	dlist_push_front(t_dlist* list, void* data)
{
	t_dnode* node;

	node = dnode_new(NULL, list->first, data);
	if(list->first != NULL)
	{
		list->first->prev = node;
	}
	list->first = node;
	if(list->last == NULL)
	{
		list->last = node;
	}
	else if(list->last->prev == NULL)
	{
		list->last->prev = node;
	}
	list->size += 1;
}

void	dlist_push_back(t_dlist* list, void* data)
{
	t_dnode* node;

	node = dnode_new(list->last, NULL, data);
	if(list->last != NULL)
	{
		list->last->next = node;
	}
	list->last = node;
	if(list->first == NULL)
	{
		list->first = node;
	}
	else if(list->first->next == NULL)
	{
		list->first->next = node;
	}
	list->size += 1;
}

void	dlist_pop_front(t_dlist* list)
{
	t_dnode* new_first;

	if(list->first != NULL)
	{
		new_first = list->first->next;
		if(list->first == list->last)
		{
			list->last = NULL;
		}
		dnode_destroy(list->func, list->first);
		free(list->first);
		list->first = new_first;
		if(list->first != NULL)
		{
			list->first->prev = NULL;
		}
		list->size -= 1;
	}
}

void	dlist_pop_back(t_dlist* list)
{
	t_dnode* new_last;

	if(list->last != NULL)
	{
		new_last = list->last->prev;
		if(list->last == list->first)
		{
			list->first = NULL;
		}
		dnode_destroy(list->func, list->last);
		free(list->last);
		list->last = new_last;
		if(list->last != NULL)
		{		
			list->last->next = NULL;
		}
		list->size -= 1;
	}
}

int		dlist_empty(t_dlist const* list)
{
	return (list->last == NULL);
}

int		dlist_size(t_dlist const* list)
{
	return (list->size);
}

void*	dlist_front(t_dlist* list)
{
	void*	res;

	res = NULL;
	if(list->first != NULL)
	{
		res = list->first->data;
	}
	return res;
}

void*	dlist_back(t_dlist* list)
{
	void*	res;

	res = NULL;
	if(list->last != NULL)
	{
		res = list->last->data;
	}
	return res;
}

t_dnode*	dlist_insert_after(t_dlist* list, t_dnode* prev, void* data)
{
	t_dnode* node;

	node = dnode_insert_after(prev, data);
	if(prev == list->last)
	{
		list->last = node;
	}
	list->size += 1;
	return node;
}

t_dnode*	dlist_insert_before(t_dlist* list, t_dnode* next, void* data)
{
	t_dnode* node;

	node = dnode_insert_before(next, data);
	if(next == list->first)
	{
		list->first = node;
	}
	list->size += 1;
	return node;
}
