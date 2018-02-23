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

void		lem_node_reverse(t_node **room)
{
	t_node *prev;
	t_node *current;
	t_node *next;

	prev = NULL;
	current = *room;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*room = prev;
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

t_link		*lem_get_close_link_to_end(t_node *end, t_link *links)
{
	t_link	*close_in;
	int		sum;
	int		tmp;

	close_in = links;
	sum = ABS(end->x - links->x) + ABS(end->y - links->y);
	links = links->next;
	while (links)
	{
		tmp = ABS(end->x - links->x) + ABS(end->y - links->y);
		if (tmp < sum)
		{
			sum = tmp;
			close_in = links;
		}
		links = links->next;
	}
	return (close_in);
}
