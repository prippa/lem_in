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

// static void	lem_print_nodes(t_lem_in *lem)
// {
// 	t_node	*tmp;
// 	t_link 	*links;
// 	t_link 	*close_in;

// 	tmp = lem->rooms;
// 	while (tmp)
// 	{
// 		ft_printf("%s (x = %d y = %d)\n", tmp->name, tmp->x, tmp->y);
// 		links = tmp->links;
// 		while (links)
// 		{
// 			ft_printf("  %s", links->name);
// 			links = links->next;
// 		}
// 		ft_printf("\n");
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n\n");
// 	ft_printf("##start\n  %s\n", lem->start->name);
// 	ft_printf("##end\n  %s\n", lem->end->name);
// 	ft_printf("\n\n");
// }

static void	lem_print_nodes(t_lem_in *lem)
{
	t_path 	*paths;
	t_link 	*temp_links;

	paths = lem->paths;
	while (paths)
	{
		temp_links = paths->links;
		ft_printf("%d\n", paths->count_steps);
		while (temp_links)
		{
			ft_printf("%s - ", temp_links->name);
			temp_links = temp_links->next;
		}
		ft_putchar('\n');
		paths = paths->next;
	}
	// ft_printf("\n\n");
	// ft_printf("##start\n  %s\n", lem->start->name);
	// ft_printf("##end\n  %s\n", lem->end->name);
	// ft_printf("\n\n");
}

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	lem_parser(&lem);
	lem_get_paths(&lem);
	//lem_paths_sort(&lem.paths);
	lem_push_ants(&lem);
	printf("\n****************\n");
	lem_print_nodes(&lem);
	// while (lem.black_list)
	// {
	// 	ft_printf("\n\n%s - ", lem.black_list->name);
	// 	lem.black_list = lem.black_list->next;
	// }
	lem_free(&lem);
	system("leaks lem-in");
	return (0);
}
