#include "lem_in.h"

void	lem_node_mem(t_node **room)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		lem_perror_exit("t_node");
	new->name = NULL;
	new->links = NULL;
	new->x = 0;
	new->y = 0;
	new->next = *room;
	*room = new;
}

void		lem_link_mem(t_link **link)
{
	t_link *new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		lem_perror_exit("t_link");
	new->name = NULL;
	new->next = *link;
	*link = new;
}
