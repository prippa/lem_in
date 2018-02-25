/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:17:52 by prippa            #+#    #+#             */
/*   Updated: 2018/02/22 18:18:10 by prippa           ###   ########.fr       */
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
	new->x = 0;
	new->y = 0;
	new->next = *link;
	*link = new;
}

void		lem_path_mem(t_path **path)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		lem_perror_exit("ERROR");
	new->count_steps = 0;
	new->links = NULL;
	new->next = *path;
	*path = new;
}

void		lem_link_add(t_link **links, char *name, int x, int y)
{
	lem_link_mem(&(*links));
	if (!((*links)->name = ft_strdup(name)))
		lem_perror_exit("ERROR");
	(*links)->x = x;
	(*links)->y = y;
}
