/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:58:04 by prippa            #+#    #+#             */
/*   Updated: 2018/02/20 14:58:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_init(t_lem_in *lem)
{
	lem->ants = 0;
	lem->rooms = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->paths = NULL;
	lem->black_list = NULL;
	lem->flag_start = 0;
	lem->flag_end = 0;
	lem->flag_stage = 1;
	lem->arr = NULL;
	lem->buf = NULL;
	lem->line_number = 1;
}

void	lem_init_start_end(t_lem_in *lem)
{
	if (lem->flag_start)
	{
		if (lem->start)
			lem_free_exit("double start", lem);
		lem->start = lem->rooms;
		lem->flag_start = 0;
	}
	else if (lem->flag_end)
	{
		if (lem->end)
			lem_free_exit("double end", lem);
		lem->end = lem->rooms;
		lem->flag_end = 0;
	}
}
