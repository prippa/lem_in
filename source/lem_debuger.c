/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_debuger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:01:54 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 15:01:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_print_path(t_link *links)
{
	int flag;

	flag = 0;
	while (links)
	{
		if (flag)
			ft_putstr(" - ");
		ft_printf("[%s]", links->name);
		links = links->next;
		flag = 1;
	}
	ft_putchar('\n');
}

static void	lem_print_paths(t_lem_in *lem)
{
	t_path	*paths;
	int		i;

	ft_printf("\nAll paths from start [%s] to end [%s]\n",
		lem->start->name, lem->end->name);
	i = 0;
	paths = lem->paths;
	while (paths)
	{
		ft_printf("%d) ", ++i);
		lem_print_path(paths->links);
		paths = paths->next;
	}
}

void		lem_debuger(t_lem_in *lem)
{
	if (lem->flags[F_DEBUG_ALL_PATHS] || lem->flags[F_DEBUG_SHORT_PATH]
		|| lem->flags[F_DEBUG_COUNT_STEPS] || lem->flags[F_DEBUG_COUNT_NODE])
	{
		ft_putstr("-----------------Debug-----------------\n");
		if (lem->flags[F_DEBUG_COUNT_STEPS])
			ft_printf("\nSTEPS: %d\n", lem->count_steps);
		if (lem->flags[F_DEBUG_COUNT_NODE])
			ft_printf("\nROOMS: %d\n", lem->count_node);
		if (lem->flags[F_DEBUG_SHORT_PATH])
		{
			ft_putstr("\nShortest path:\n");
			lem_print_path(lem->paths->links);
		}
		if (lem->flags[F_DEBUG_ALL_PATHS])
			lem_print_paths(lem);
		ft_putstr("\n---------------------------------------\n");
	}
}
