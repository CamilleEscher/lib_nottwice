#ifndef SNODE_H
#define SNODE_H
#include "ptr_func.h"

typedef struct	s_snode
{
	struct s_snode*	next;
	void*			data;
}				t_snode;

void		snode_destroy(ptr_delete func, t_snode* node);
t_snode*	snode_new(t_snode* node, void* data);
/* insert node after prev_node
 * param prev_node must be != NULL
*/
void 		snode_insert_after(t_snode* prev_node, void* data);

#endif
