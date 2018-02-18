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

static void	lem_init(t_lem_in *lem)
{
	lem->rooms = NULL;
	lem->start = NULL;
	lem->end = NULL;
}

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	lem_parser(&lem);
	return (0);
}
