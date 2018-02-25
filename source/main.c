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

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	lem_parser(&lem);
	lem_get_paths(&lem);
	lem_paths_sort(&lem.paths);
	lem_print_ants_travel(&lem);
	lem_free(&lem);
	//system("leaks lem-in");
	return (0);
}
