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

static void	lem_get_ants(t_lem_in *lem)
{
	lem->ants_count = ft_atoi(lem->buf);
	if (!lem->ants_count)
		lem_free_exit("No ants", lem);
	lem->flag_stage = 2;
}

static void	lem_get_rooms(t_lem_in *lem)
{
	if (!(lem->arr = ft_strsplit(lem->buf, ' ')))
		lem_perror_exit("ERROR");
	if (ft_arrlen(lem->arr) != 3
		|| !ft_isdigit(lem->arr[1][0]) || !ft_isdigit(lem->arr[2][0])
		|| lem->arr[0][0] == 'L' || lem->arr[0][0] == '-')
		lem_free_exit("Invalid room", lem);
	lem_node_mem(&lem->rooms);
	if (!(lem->rooms->name = ft_strdup(lem->arr[0])))
		lem_perror_exit("ERROR");
	lem->rooms->x = ft_atoi(lem->arr[1]);
	lem->rooms->y = ft_atoi(lem->arr[2]);
	lem_is_duplicate_node(lem);
	lem_init_start_end(lem);
	ft_arr_free(&lem->arr);
}

static void	lem_get_links(t_lem_in *lem)
{
	t_node	*link1;
	t_node	*link2;

	if (!(lem->arr = ft_strsplit(lem->buf, '-')))
		lem_perror_exit("ERROR");
	if (ft_arrlen(lem->arr) != 2 || !ft_strcmp(lem->arr[0], lem->arr[1]))
		lem_free_exit("Invalid link", lem);
	link1 = lem_get_node_by_name(lem->rooms, lem->arr[0]);
	link2 = lem_get_node_by_name(lem->rooms, lem->arr[1]);
	if (!link1 || !link2)
		lem_free_exit("Invalid link (not exist room name)", lem);
	lem_is_duplicate_link(lem, link2->links, lem->arr[0]);
	lem_is_duplicate_link(lem, link1->links, lem->arr[1]);
	lem_link_add(&link1->links, link2->name, link2->x, link2->y);
	lem_link_add(&link2->links, link1->name, link1->x, link1->y);
	ft_arr_free(&lem->arr);
}

static int	lem_dispatcher(t_lem_in *lem)
{
	if (!ft_strcmp(lem->buf, ""))
		return (0);
	else if (lem->buf[0] == '#' && lem->buf[1] == '#')
		lem_is_command(lem);
	else if (lem->buf[0] == '#')
		return (1);
	else if (lem->flag_stage == 1)
		lem_get_ants(lem);
	else if (lem->flag_stage == 2 && !lem_is_links_stage(lem))
		lem_get_rooms(lem);
	else if (lem->flag_stage == 3)
		lem_get_links(lem);
	return (1);
}

void		lem_parser(t_lem_in *lem)
{
	int	is_error;

	while ((is_error = get_next_line(0, &lem->buf)) > 0)
	{
		if (!lem_dispatcher(lem))
			break ;
		lem->line_number++;
		ft_putendl(lem->buf);
		ft_str_free(&lem->buf);
	}
	if (is_error == -1)
		lem_perror_exit("ERROR");
	if (!lem->start)
		lem_free_noline_exit("No start", lem);
	if (!lem->end)
		lem_free_noline_exit("No end", lem);
	ft_putchar('\n');
}
