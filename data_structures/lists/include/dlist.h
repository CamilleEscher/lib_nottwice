#ifndef DLIST_H
#define DLIST_H
#include "dnode.h"
#include "ptr_func.h"

typedef struct	s_dlist
{
	t_dnode*	first;
	t_dnode*	last;
	ptr_delete	func;
	int			size;
}				t_dlist;

void		dlist_create(t_dlist* list, ptr_delete func);
void		dlist_destroy(t_dlist* list);
void		dlist_clear(t_dlist* list);
void		dlist_push_front(t_dlist* dlist, void* data);
void		dlist_push_back(t_dlist* list, void* data);
void		dlist_pop_front(t_dlist* list);
void		dlist_pop_back(t_dlist* list);
int			dlist_empty(t_dlist const* list);
int			dlist_size(t_dlist const* list);
void*		dlist_front(t_dlist* list);
void*		dlist_back(t_dlist* list);
t_dnode*	dlist_insert_after(t_dlist* list, t_dnode* prev, void* data);
t_dnode*	dlist_insert_before(t_dlist* list, t_dnode* next, void* data);

#endif
