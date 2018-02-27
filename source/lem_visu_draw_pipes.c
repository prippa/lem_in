#include "lem_in.h"

static char	lem_visu_get_right_pipe(int old_x, int old_y, int new_x, int new_y)
{
	char c;

	if ((new_y < old_y && new_x > old_x)
		|| (new_y > old_y && new_x < old_x))
		c = '/';
	else if ((new_y < old_y && new_x < old_x)
		|| (new_y > old_y && new_x > old_x))
		c = '\\';
	else if (new_y == old_y)
		c = ' ';
	else
		c = '|';
	return (c);
}

static void		lem_visu_op(t_lem_in *lem, int e2, int *err)
{
	if (e2 > -lem->vis.dx)
	{ 
		*err -= lem->vis.dy;
		X += lem->vis.sx;
	}
	if (e2 < lem->vis.dy)
	{
		*err += lem->vis.dx;
		Y += lem->vis.sy;
	}
}

static void		lem_visu_draw_pipe(t_lem_in *lem, t_node *from, t_link *to)
{
	int		err;
	int		e2;
	char	c;

	X = from->x;
	Y = from->y;
	lem->vis.dx = ABS(to->x - from->x);
	lem->vis.dy = ABS(to->y - from->y);
	lem->vis.sx = from->x < to->x ? 1 : -1;
	lem->vis.sy = from->y < to->y ? 1 : -1;
	err = (lem->vis.dx > lem->vis.dy ? lem->vis.dx : -lem->vis.dy) / 2;
	while (X != to->x || Y != to->y)
	{
		lem->vis.x = X;
		lem->vis.y = Y;
		e2 = err;
		lem_visu_op(lem, e2, &err);
		c = lem_visu_get_right_pipe(lem->vis.x, lem->vis.y, X, Y);
		if (Y == to->y)
			c = '-';
		lem->vis.board[Y][X] = c;
	}
}

void		lem_visu_draw_pipes(t_lem_in *lem)
{
	t_node	*node;
	t_link	*links;
	t_link	*black_list;

	black_list = NULL;
	node = lem->rooms;
	while (node)
	{
		lem_link_add(&black_list, node->name, node->x, node->y);
		links = node->links;
		while (links)
		{
			if (lem_is_green_list(links, black_list))
				lem_visu_draw_pipe(lem, node, links);
			links = links->next;
		}
		node = node->next;
	}
	lem_link_free(&black_list);
}
