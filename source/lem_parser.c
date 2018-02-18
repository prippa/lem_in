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

static void	lem_sharp_valid(t_lem_in *lem)
{
	
}

void		lem_parser(t_lem_in *lem)
{
	int		stage;
	int		is_error;

	lem->buf = NULL;
	stage = 1;
	while ((is_error = get_next_line(0, &lem->buf)) > 0)
	{
		if (lem->buf[0] == '#')
			lem_sharp_valid(lem);
		else if (stage == 1)
		{

		}
		else if (stage == 2)
		{

		}
		else if (stage == 3)
		{

		}
		free(lem->buf);
	}
	if (is_error == -1)
		lem_print_error("gnl returned -1", lem);
}
