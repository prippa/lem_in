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
		ft_str_free(&(*links)->name);
		free(*links);
		*links = (*links)->next;
	}
}

static void	lem_node_free(t_node **room)
{
	while (*room)
	{
		ft_str_free(&(*room)->name);
		lem_link_free(&((*room)->links));
		free(*room);
		*room = (*room)->next;
	}
}

static void	lem_paths_free(t_path **path)
{
	while (*path)
	{
		lem_link_free(&((*path)->links));
		free(*path);
		*path = (*path)->next;
	}
}

void		lem_free(t_lem_in *lem)
{
	ft_str_free(&lem->buf);
	ft_arr_free(&lem->arr);
	if (lem->rooms)
		lem_node_free(&lem->rooms);
	if (lem->paths)
		lem_paths_free(&lem->paths);
	if (lem->black_list)
		lem_link_free(&lem->black_list);
}
