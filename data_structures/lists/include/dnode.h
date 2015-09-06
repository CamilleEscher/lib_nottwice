#ifndef DNODE_H
#define DNODE_H
#include "ptr_func.h"

typedef struct	s_dnode
{	
	struct s_dnode*	prev;
	struct s_dnode*	next;
	void*			data;
}				t_dnode;

void		dnode_destroy(ptr_delete func, t_dnode* node);
t_dnode*	dnode_new(t_dnode* prev, t_dnode* next, void* data);
t_dnode*	dnode_insert_after(t_dnode* prev, void* data);
t_dnode*	dnode_insert_before(t_dnode* next, void* data);

#endif
