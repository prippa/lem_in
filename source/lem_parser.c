/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:21:59 by prippa            #+#    #+#             */
/*   Updated: 2018/02/18 14:22:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_get_links(t_lem_in *lem)
{
	
}

static void	lem_get_rooms(t_lem_in *lem)
{
	char **arr;

	if (!(arr = ft_strsplit(lem->buf, ' ')))
		lem_perror_exit("malloc error");
	if (ft_arrlen(arr) != 3 || !ft_isdigit(arr[1][0]) || !ft_isdigit(arr[2][0]))
		lem_free_exit("Invalid room", lem);
	lem_is_same_name(lem, arr[0]);
	lem_node_mem(&lem->rooms);
	if (!(lem->rooms->name = ft_strdup(arr[0])))
		lem_perror_exit("malloc error");
	lem->rooms->x = ft_atoi(arr[1]);
	lem->rooms->y = ft_atoi(arr[2]);
	lem_init_start_end(lem);
	ft_arr_free(&arr);
}

static void	lem_is_start_end(t_lem_in *lem)
{
	if ((lem->flag_stage == 1 && !ft_strcmp(lem->buf, "##start"))
		|| (lem->flag_stage == 1 && !ft_strcmp(lem->buf, "##end")))
		lem_free_exit("No ants", lem);
	if (!ft_strcmp(lem->buf, "##start"))
		lem->flag_start = 1;
	else if (!ft_strcmp(lem->buf, "##end"))
		lem->flag_end = 1;
}

static void	lem_get_ants(t_lem_in *lem)
{
	lem->ants = ft_atoi(lem->buf);
	if (!lem->ants)
		lem_free_exit("No ants", lem);
	lem->flag_stage = 2;
}

void		lem_parser(t_lem_in *lem)
{
	int	is_error;

	lem->buf = NULL;
	lem->flag_stage = 1;
	while ((is_error = get_next_line(0, &lem->buf)) > 0)
	{
		if (lem->buf[0] == '#')
			lem_is_start_end(lem);
		else if (lem->flag_stage == 1)
			lem_get_ants(lem);
		else if (lem->flag_stage == 2 && !lem_is_links_stage(lem))
			lem_get_rooms(lem);
		else if (lem->flag_stage == 3)
			lem_get_links(lem);
		ft_putendl(lem->buf);
		free(lem->buf);
	}
	if (is_error == -1)
		lem_perror_exit("gnl return (-1)");
}
