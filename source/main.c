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
		if (!ft_strcmp(argv[i], "-v"))
			lem->flags[F_VISUALIZE] = 'v';
		else if (!ft_strcmp(argv[i], "-p"))
			lem->flags[F_DEBUG_ALL_PATHS] = 'p';
		else if (!ft_strcmp(argv[i], "-d"))
			lem->flags[F_DEBUG_ANT_STATUS] = 'd';
		else if (!ft_strcmp(argv[i], "-s"))
			lem->flags[F_DEBUG_COUNT_STEPS] = 's';
		else if (!ft_strcmp(argv[i], "-n"))
			lem->flags[F_DEBUG_COUNT_NODE] = 'n';
		else
		{
			ft_putstr_fd("ERROR: Invalid flag\nUsage: [-v -p -d -s -n]\n", 2);
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
