/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:56:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/20 18:56:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_node_mem(t_node **room)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		lem_perror_exit("ERROR");
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
		lem_perror_exit("ERROR");
	new->name = NULL;
	new->next = *link;
	*link = new;
}

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
