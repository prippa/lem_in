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
	t_link 	*close_in;

	tmp = lem->rooms;
	while (tmp)
	{
		ft_printf("%s (x = %d y = %d)\n", tmp->name, tmp->x, tmp->y);
		links = tmp->links;
		// while (links)
		// {
			close_in = lem_get_close_link_to_end(lem->end, links);
			ft_printf("  close_in = %s (x = %d y = %d)\n", close_in->name, close_in->x, close_in->y);
		// 	links = links->next;
		// }
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
	lem_get_paths(&lem);
	lem_push_ants(&lem);
	lem_print_nodes(&lem);
	lem_free(&lem);
	system("leaks lem-in");
	return (0);
}
