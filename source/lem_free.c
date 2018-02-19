/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:36:56 by prippa            #+#    #+#             */
/*   Updated: 2018/02/18 15:37:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_link_free(t_link **links)
{
	while (*links)
	{
		free((*links)->name);
		free(*links);
		*links = (*links)->next;
	}
}

static void	lem_node_free(t_node **room)
{
	while (*room)
	{
		free((*room)->name);
		lem_link_free(&((*room)->links));
		free(*room);
		*room = (*room)->next;
	}
}

void		lem_free(t_lem_in *lem)
{
	if (lem->rooms)
		lem_node_free(&lem->rooms);
	if (lem->start)
		lem_node_free(&lem->start);
	if (lem->end)
		lem_node_free(&lem->end);
}
