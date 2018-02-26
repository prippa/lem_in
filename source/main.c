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

void		lem_get_bonus_flags(t_lem_in *lem, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-visu"))
			lem->flags[F_VISUALIZE] = '$';
		else if (!ft_strcmp(argv[i], "-paths"))
			lem->flags[F_DEBUG_ALL_PATHS] = '$';
		else if (!ft_strcmp(argv[i], "-loc"))
			lem->flags[F_DEBUG_ANT_STATUS] = '$';
		else if (!ft_strcmp(argv[i], "-step"))
			lem->flags[F_DEBUG_COUNT_STEPS] = '$';
		else if (!ft_strcmp(argv[i], "-rooms"))
			lem->flags[F_DEBUG_COUNT_NODE] = '$';
		else if (!ft_strcmp(argv[i], "-path"))
			lem->flags[F_DEBUG_SHORT_PATH] = '$';
		else
		{
			ft_putstr_fd("ERROR: Invalid flag\n", 2);
			ft_putstr_fd("usage: [-visu -paths -path -loc -step -rooms]\n", 2);
			exit(0);
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_lem_in lem;

	lem_init(&lem);
	if (argc > 1)
		lem_get_bonus_flags(&lem, argv + 1);
	lem_parser(&lem);
	lem_get_paths(&lem);
	lem_paths_sort(&lem.paths);
	lem_print_ants_travel(&lem);
	lem_free(&lem);
	system("leaks lem-in");
	return (0);
}
