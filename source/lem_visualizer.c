/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:59:00 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 12:59:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define Y lem->vis.i
#define X lem->vis.j

void		lem_vis_fill_board(t_lem_in *lem)
{
	t_node	*node;
	t_path	*paths;
	t_link	*links;

	node = lem->rooms;
	while (node)
	{
		lem->vis.board[node->y][node->x] = node->name[0];
		node = node->next;
	}
	paths = lem->paths;
	while (paths)
	{
		links = paths->links;
		while (links)
		{
			if (links->ant)
			{
				lem->vis.board[links->y][links->x] = 'A';
				lem->flag_end = 1;
			}
			links = links->next;
		}
		paths = paths->next;
	}
}

void		lem_vis_print_board(t_lem_in *lem)
{
	Y = 0;
	while (lem->vis.board[Y])
	{
		X = 0;
		while (lem->vis.board[Y][X])
		{
			if (lem->vis.board[Y][X] == 'A')
			{
				if (Y == lem->end->y && X == lem->end->x)
					lem->end_ants++;
				ft_printf("%~c", F_RED, lem->vis.board[Y][X]);
			}
			else if (lem->vis.board[Y][X] == '.')
				ft_putchar(' ');
			else
				ft_printf("%~c", F_BLUE, lem->vis.board[Y][X]);
			X++;
		}
		ft_putchar('\n');
		//printf("%d\n", lem->end_ants);
		Y++;
	}
}

void		lem_vis_board_mem(t_lem_in *lem)
{
	t_node	*temp_node;

	lem->vis.y = lem->rooms->y;
	lem->vis.x = lem->rooms->x;
	temp_node = lem->rooms->next;
	while (temp_node)
	{
		if (temp_node->x > lem->vis.x)
			lem->vis.x = temp_node->x;
		if (temp_node->y > lem->vis.y)
			lem->vis.y = temp_node->y;
		temp_node = temp_node->next;
	}
	lem->vis.board = ft_arrnew(lem->vis.y + 1, lem->vis.x + 1, '.');
}

int			lem_visualizer(t_lem_in *lem)
{
	t_visualizer	vis;
	char			*line;

	ft_clear();
	lem->flag_end = 0;
	if (!lem->vis.board)
		lem_vis_board_mem(lem);
	lem_vis_fill_board(lem);
	lem_vis_print_board(lem);
	read(1, 0, 1);
	return (lem->flag_end);
}
