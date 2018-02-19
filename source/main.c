/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:19:59 by prippa            #+#    #+#             */
/*   Updated: 2018/02/18 14:20:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_init(t_lem_in *lem)
{
	lem->rooms = NULL;
	lem->start = NULL;
	lem->end = NULL;
}

static void	lem_print_nodes(t_node room)
{
	t_node tmp;

	tmp = room;
	//ft_printf("%s\n", tmp.name);
	while (tmp.links)
	{
		ft_printf("\t%s\n", tmp.links->name);
		tmp.links = tmp.links->next;
	}
	tmp = *tmp.next;
	while (tmp.next)
	{
		tmp = *tmp.next;
		//ft_printf("%s\n", tmp.name);
		while (tmp.links)
		{
			ft_printf("\t%s\n", tmp.links->name);
			tmp.links = tmp.links->next;
		}
	}
}

int			main(int argc, char **argv)
{
	t_lem_in lem;
	t_node tmp;

	lem_init(&lem);
	lem_parser(&lem);
	lem_print_nodes(*lem.rooms);
	lem_free(&lem);
	system("leaks lem-in");
	return (0);
}
