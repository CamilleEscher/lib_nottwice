#ifndef SLIST_H
#define SLIST_H
#include "snode.h"
#include "ptr_func.h"

typedef struct	s_slist
{
	t_snode*		origin;
	int			size;
	ptr_delete	func;
}				t_slist;

void	list_create(t_slist* list, ptr_delete func);
void	list_destroy(t_slist* list);
void	list_clear(t_slist* list);
void	list_push_front(t_slist* list, void* data);
int		list_empty(t_slist const* list);
int		list_size(t_slist const* list);
void	list_pop_front(t_slist* list);
void*	list_front(t_slist const* list);
void	list_insert_after(t_slist* list, t_snode* prev_node, void* data);

#endif
