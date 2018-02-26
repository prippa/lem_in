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

void		lem_push_ants(t_lem_in *lem)
{
	t_path	*temp_paths;
	t_link	*temp_links;
	int		pull;
	int		tmp;

	temp_paths = lem->paths;
	while (temp_paths)
	{
		temp_links = temp_paths->links;
		pull = lem->ants;
		while (temp_links)
		{
			tmp = temp_links->ant;
			temp_links->ant = pull;
			pull = tmp;
			temp_links = temp_links->next;
		}
		temp_paths = temp_paths->next;
		if (lem->ants == lem->ants_count)
			lem->ants = 0;
		else if (lem->ants)
			lem->ants++;
	}
}

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
	while (--len >= 0)
	{
		temp_paths = *paths;
		temp_paths_next = temp_paths->next;
		while (temp_paths_next)
		{
			if (temp_paths_next->count_steps < temp_paths->count_steps)
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
