#include "../include/slist.h"
#include "../include/snode.h"
#include "../include/ptr_func.h"
#include <string.h>
#include <stdlib.h>

void list_create(t_slist* list, ptr_delete func)
{
	bzero(list, sizeof(*list));
	list->func = func;
}

void list_destroy(t_slist* list)
{
	t_snode* 			node;
	t_snode* 			temp;

	node = list->origin;
	while(node != NULL)
	{
		temp = node->next;
		snode_destroy(list->func, node);
		free(node);
		node = temp;
	}
	bzero(list, sizeof(*list));
}

void list_clear(t_slist* list)
{
	list_destroy(list);
}

void list_push_front(t_slist* list, void* data)
{
	t_snode* node;

	node = snode_new(list->origin, data);
	list->origin = node;
	list->size += 1;
}

int list_empty(t_slist const* list)
{
	return (list->size == 0);
}

int list_size(t_slist const* list)
{
	return list->size;
}

void list_pop_front(t_slist* list)
{
	t_snode* new_origin;

	if(list->origin != NULL)
	{
		new_origin = list->origin->next;
		snode_destroy(list->func, list->origin);
		free(list->origin);
		list->origin = new_origin;
		list->size -= 1;
	}
}

void* list_front(t_slist const* list)
{
	void*	res;

	res = NULL;
	if(list->origin != NULL)
	{
		res =  list->origin->data;
	}
	return res;
}

void list_insert_after(t_slist* list, t_snode* prev_node, void* data)
{
	snode_insert_after(prev_node, data);
	list->size += 1;
}
