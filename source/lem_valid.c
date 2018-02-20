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

void		lem_is_same_name(t_lem_in *lem, char *name)
{
	t_node *tmp;

	tmp = lem->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			lem_free_exit("duplicate name", lem);
		tmp = tmp->next;
	}
}
