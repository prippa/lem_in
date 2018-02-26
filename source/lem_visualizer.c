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

void		lem_vis_fill_board2(t_lem_in *lem, t_path *paths, t_link *links)
{
	lem->way_ants = 0;
	while (paths)
	{
		links = paths->links;
		while (links)
		{
			if (links->ant)
			{
				if (links->x == lem->end->x && links->y == lem->end->y)
					lem->end_ants++;
				else
				{
					lem->way_ants++;
					lem->flag_end = 1;
				}
				lem->vis.board[links->y][links->x] = (links->ant - 1 % 26) + 65;
			}
			links = links->next;
		}
		paths = paths->next;
	}
}

void		lem_vis_fill_board(t_lem_in *lem)
{
	t_node	*node;

	node = lem->rooms;
	while (node)
	{
		lem->vis.board[node->y][node->x] = '*';
		node = node->next;
	}
	lem_vis_fill_board2(lem, lem->paths, NULL);
	lem->vis.board[lem->start->y][lem->start->x] = '!';
	lem->vis.board[lem->end->y][lem->end->x] = '?';
}

void		lem_vis_print_board(t_lem_in *lem)
{
	Y = 0;
	while (lem->vis.board[Y])
	{
		X = 0;
		while (lem->vis.board[Y][X])
		{
			if (ft_isuppercase(lem->vis.board[Y][X]))
				ft_printf("%~c", lem->vis.board[Y][X] % 5, lem->vis.board[Y][X]);
			else if (lem->vis.board[Y][X] == '.')
				ft_putchar(' ');
			else if (lem->vis.board[Y][X] == '!')
				ft_printf("%~c", F_YELLOW, lem->vis.board[Y][X]);
			else if (lem->vis.board[Y][X] == '?')
				ft_printf("%~c", F_RED, lem->vis.board[Y][X]);
			else
				ft_printf("%c", lem->vis.board[Y][X]);
			X++;
		}
		ft_putchar('\n');
		Y++;
	}
	if (lem->flags[F_DEBUG_ANT_STATUS])
		ft_printf("\nAnts location:\nstart [%d] - way [%d] - end [%d]\n",
		lem->ants_count - (lem->way_ants + lem->end_ants),
		lem->way_ants, lem->end_ants);
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
