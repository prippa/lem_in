/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:29:00 by prippa            #+#    #+#             */
/*   Updated: 2018/02/20 15:29:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lem_is_command(t_lem_in *lem)
{
	if ((lem->flag_stage == 1 && !ft_strcmp(lem->buf, "##start"))
		|| (lem->flag_stage == 1 && !ft_strcmp(lem->buf, "##end")))
		lem_free_exit("No ants", lem);
	if (!ft_strcmp(lem->buf, "##start"))
	{
		lem->flag_start = 1;
		return (1);
	}
	else if (!ft_strcmp(lem->buf, "##end"))
	{
		lem->flag_end = 1;
		return (1);
	}
	return (0);
}

int			lem_is_links_stage(t_lem_in *lem)
{
	char **arr;

	if (!(arr = ft_strsplit(lem->buf, '-')))
		lem_perror_exit("malloc error");
	if (ft_arrlen(arr) == 2)
	{
		lem->flag_stage = 3;
		ft_arr_free(&arr);
		return (1);
	}
	ft_arr_free(&arr);
	return (0);
}

void		lem_is_duplicate_node(t_lem_in *lem)
{
	t_node *tmp;
	t_node *new;

	new = lem->rooms;
	tmp = lem->rooms->next;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, new->name)
			|| (tmp->x == new->x && tmp->y == new->y))
			lem_free_exit("duplicate room name or point x y", lem);
		tmp = tmp->next;
	}
}

void		lem_is_duplicate_link(t_lem_in *lem, t_link *links, char *name)
{
	while (links)
	{
		if (!ft_strcmp(links->name, name))
			lem_free_exit("duplicate link", lem);
		links = links->next;
	}
}

int			lem_is_green_list(t_link *link, t_link *list)
{
	while (list)
	{
		if (!ft_strcmp(link->name, list->name))
			return (0);
		list = list->next;
	}
	return (1);
}
