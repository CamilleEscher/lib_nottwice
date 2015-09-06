#include "../include/dnode.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void	dnode_destroy(ptr_delete func, t_dnode* node)
{
	if(func != NULL)
	{
		func(node->data);
	}
	bzero(node, sizeof(*node));
}

t_dnode* dnode_new(t_dnode* prev, t_dnode* next, void* data)
{
	t_dnode* node;

	node = NULL;
	node = malloc(sizeof(*node));
	node->data = data;
	node->prev = prev;
	node->next = next;
	return node;
}

t_dnode* dnode_insert_after(t_dnode* prev, void* data)
{
	assert(prev != NULL);
	t_dnode* node;

	node = dnode_new(prev, prev->next, data);
	if(prev->next != NULL)
	{
		prev->next->prev = node;
	}
	prev->next = node;
	return node;
}

t_dnode*	dnode_insert_before(t_dnode* next, void* data)
{
	assert(next != NULL);
	t_dnode* node;

	node = dnode_new(next->prev, next, data);
	if(next->prev != NULL)
	{
		next->prev->next = node;
	}
	next->prev = node;
	return node;
}
