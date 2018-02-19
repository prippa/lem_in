/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_trash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:49:33 by prippa            #+#    #+#             */
/*   Updated: 2018/02/18 16:49:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_exit(char *error)
{
	ft_dprintf(2, "ERROR: %s\n", error);
	exit(0);
}

void		lem_perror_exit(char *error)
{
	perror(error);
	exit(0);
}

void		lem_free_exit(char *error, t_lem_in *lem)
{
	ft_dprintf(2, "ERROR: %s\n", error);
	lem_free(lem);
	exit(0);
}
