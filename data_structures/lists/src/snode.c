#include "../include/snode.h"
#include "../include/ptr_func.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void snode_destroy(ptr_delete func, t_snode* node)
{
	if(func != NULL)
	{
		func(node->data);
	}
	bzero(node, sizeof(*node));
}

t_snode* snode_new(t_snode* next, void* data)
{
	t_snode* node;

	node = malloc(sizeof(*node));
	node->next = next;
	node->data = data;
	return node;
}

void snode_insert_after(t_snode* prev_node, void* data)
{
	assert(prev_node != NULL);
	t_snode* node;
	
	node = snode_new(prev_node->next, data);
	prev_node->next = node;
}
