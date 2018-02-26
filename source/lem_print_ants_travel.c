/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print_ants_travel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:30:48 by prippa            #+#    #+#             */
/*   Updated: 2018/02/22 15:30:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_sort_static_links(t_link **static_links, int len)
{
	t_link	tmp;
	t_link	*temp_links;
	int		i;
	int		j;

	temp_links = *static_links;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1))
		{
			if (temp_links[j].ant >= temp_links[j + 1].ant)
			{
				tmp = temp_links[j];
				temp_links[j] = temp_links[j + 1];
				temp_links[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	lem_print_ants(t_lem_in *lem, int len)
{
	t_link	*static_links;
	int		i;

	static_links = lem_get_static_links(lem->paths, len);
	lem_sort_static_links(&static_links, len);
	i = 0;
	while (i < len)
	{
		if (lem->flag_start)
			ft_putchar(' ');
		ft_printf("L%d-%s",
			(static_links[i]).ant, (static_links[i]).name);
		lem->flag_start = 1;
		i++;
	}
	if (lem->flag_start)
		ft_putchar('\n');
	free(static_links);
}

static int	lem_print_step(t_lem_in *lem)
{
	t_path	*temp_paths;
	t_link	*temp_links;
	int		len;

	temp_paths = lem->paths;
	lem->flag_start = 0;
	len = 0;
	while (temp_paths)
	{
		temp_links = temp_paths->links;
		while (temp_links)
		{
			if (temp_links->ant)
				len++;
			temp_links = temp_links->next;
		}
		temp_paths = temp_paths->next;
	}
	lem_print_ants(lem, len);
	return (lem->flag_start);
}

void		lem_print_ants_travel(t_lem_in *lem)
{
	while (1)
	{
		lem_push_ants(lem);
		if (lem->flags[F_VISUALIZE])
		{
			if (!(lem_visualizer(lem)))
				break ;
		}
		else if (!(lem_print_step(lem)))
			break ;
		lem->count_steps++;
	}
	lem_debuger(lem);
}
