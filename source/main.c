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

static void	lem_print_nodes(t_node *tmp)
{
	t_link *links;

	while (tmp)
	{
		ft_printf("name (%s), x (%d), y (%d)\n", tmp->name, tmp->x, tmp->y);
		links = tmp->links;
		while (links)
		{
			ft_printf("\t%s\n", links->name);
			links = links->next;
		}
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	lem_parser(&lem);
	lem_node_reverse(&lem.rooms);
	lem_print_nodes(lem.rooms);
	lem_free(&lem);
	system("leaks lem-in");
	return (0);
}
