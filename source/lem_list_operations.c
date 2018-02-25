/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:56:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/20 18:56:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	len_paths_swap(t_path **left, t_path **right)
{
	t_link	*temp_links;
	int		tmp;

	tmp = (*left)->count_steps;
	temp_links = (*left)->links;
	(*left)->count_steps = (*right)->count_steps;
	(*left)->links = (*right)->links;
	(*right)->count_steps = tmp;
	(*right)->links = temp_links;
}

void		lem_paths_sort(t_path **paths)
{
	int		len;
	t_path	*temp_paths;
	t_path	*temp_paths_next;

	len = 0;
	temp_paths = *paths;
	while (temp_paths)
	{
		temp_paths = temp_paths->next;
		len++;
	}
	while (--len <= 0)
	{
		temp_paths = *paths;
		temp_paths_next = temp_paths->next;
		while (temp_paths_next)
		{
			if (temp_paths_next->count_steps > temp_paths->count_steps)
				len_paths_swap(&temp_paths, &temp_paths_next);
			temp_paths = temp_paths->next;
			temp_paths_next = temp_paths_next->next;
		}
	}
}

void		lem_links_reverse(t_link **links)
{
	t_link *prev;
	t_link *current;
	t_link *next;

	prev = NULL;
	current = *links;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*links = prev;
}

t_node		*lem_get_node_by_name(t_node *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_node		*lem_get_close_node_to_end(t_lem_in *lem, t_link *links)
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
