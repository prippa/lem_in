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

static void	lem_print_nodes(t_lem_in *lem)
{
	t_node	*tmp;
	t_link 	*links;

	tmp = lem->rooms;
	while (tmp)
	{
		ft_printf("%s (x = %d y = %d)\n", tmp->name, tmp->x, tmp->y);
		links = tmp->links;
		while (links)
		{
			ft_printf("  %s\n", links->name);
			links = links->next;
		}
		tmp = tmp->next;
	}
	ft_printf("\n\n");
	ft_printf("##start\n  %s\n", lem->start->name);
	ft_printf("##end\n  %s\n", lem->end->name);
	ft_printf("\n\n");
}

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	lem_parser(&lem);
	lem_print_nodes(&lem);
	system("leaks lem-in");
	lem_free(&lem);
	return (0);
}
