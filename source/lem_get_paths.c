/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:02:25 by prippa            #+#    #+#             */
/*   Updated: 2018/02/23 13:02:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*lem_get_green_links(t_lem_in *lem, t_node *current_node)
{
	t_link *green_links;
	t_link *current_node_links;

	green_links = NULL;
	current_node_links = current_node->links;
	while (current_node_links)
	{
		if (lem_is_green_list(current_node_links, lem->black_list)
			&& lem_is_green_list(current_node_links, lem->path))
		{
			if (!lem->flag_end && lem->flag_start
				&& !ft_strcmp(current_node_links->name, lem->end->name))
			{
				current_node_links = current_node_links->next;
				continue ;
			}
			lem_link_add(&green_links, current_node_links->name,
				current_node_links->x, current_node_links->y);
			if (lem->flag_end && lem->flag_start
				&& !ft_strcmp(current_node_links->name, lem->end->name))
				lem->flag_end = 0;
		}
		current_node_links = current_node_links->next;
	}
	return (green_links);
}

static int		lem_dead_end(t_lem_in *lem, t_node **temp_node)
{
	if (!lem->paths && !ft_strcmp(lem->start->name, (*temp_node)->name))
		lem_free_noline_exit("no link from start to end", lem);
	else if (!ft_strcmp(lem->start->name, (*temp_node)->name))
		return (0);
	lem_link_add(&lem->black_list, (*temp_node)->name,
		(*temp_node)->x, (*temp_node)->y);
	lem->flag_start = 1;
	*temp_node = lem->start;
	lem_link_free(&lem->path);
	return (1);
}

static void		lem_paths_add(t_lem_in *lem, t_node **temp_node)
{
	t_link *temp_path;

	lem->flag_start = 1;
	*temp_node = lem->start;
	temp_path = lem->path;
	lem_path_mem(&lem->paths);
	while (temp_path)
	{
		if (ft_strcmp(temp_path->name, lem->start->name))
		{
			if (ft_strcmp(temp_path->name, lem->end->name))
				lem_link_add(&lem->black_list, temp_path->name,
					temp_path->x, temp_path->y);
			lem_link_add(&lem->paths->links, temp_path->name,
				temp_path->x, temp_path->y);
			lem->paths->count_steps++;
		}
		temp_path = temp_path->next;
	}
	lem_link_free(&lem->path);
	lem_link_add(&lem->path, lem->start->name,
		lem->start->x, lem->start->y);
}

static t_node	*lem_get_close_node_to_end(t_lem_in *lem, t_link *links)
{
	t_link	*close_in;
	int		sum;
	int		tmp;

	close_in = links;
	sum = ABS(lem->end->x - links->x) + ABS(lem->end->y - links->y);
	links = links->next;
	while (links)
	{
		tmp = ABS(lem->end->x - links->x) + ABS(lem->end->y - links->y);
		if ((sum && lem->end->y == links->y)
			|| (tmp < sum && close_in->y != lem->end->y))
		{
			sum = tmp;
			close_in = links;
		}
		links = links->next;
	}
	return (lem_get_node_by_name(lem->rooms, close_in->name));
}

void			lem_get_paths(t_lem_in *lem)
{
	t_node	*temp_node;
	t_link	*temp_links;

	lem->flag_end = 1;
	lem->flag_start = 1;
	temp_node = lem->start;
	while (1)
	{
		lem_link_add(&lem->path, temp_node->name, temp_node->x, temp_node->y);
		if (!ft_strcmp(lem->end->name, temp_node->name))
			lem_paths_add(lem, &temp_node);
		if (!(temp_links = lem_get_green_links(lem, temp_node)))
		{
			if (lem_dead_end(lem, &temp_node))
				continue ;
			else
				return ;
		}
		temp_node = lem_get_close_node_to_end(lem, temp_links);
		lem->flag_start = 0;
		lem_link_free(&temp_links);
	}
}
