/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:59:25 by prippa            #+#    #+#             */
/*   Updated: 2018/02/20 18:59:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define			Y lem->i
# define			X lem->j

typedef	struct		s_link
{
	char			*name;
	int				x;
	int				y;
	struct s_link	*next;
}					t_link;

typedef	struct		s_path
{
	int				count_steps;
	t_link			*links;
	struct s_path	*next;
}					t_path;

typedef	struct		s_node
{
	char			*name;
	int				x;
	int				y;
	t_link			*links;
	struct s_node	*next;
}					t_node;

typedef	struct		s_lem_in
{
	int				ants;
	t_node			*rooms;
	t_node			*start;
	t_node			*end;
	t_path			*paths;
	t_link			*path;
	t_link			*black_list;
	int				flag_start;
	int				flag_end;
	int				flag_stage;
	char			**arr;
	char			*buf;
	int				line_number;
	int				i;
	int				j;
}					t_lem_in;

void				lem_get_paths(t_lem_in *lem);
void				lem_push_ants(t_lem_in *lem);

void				lem_init(t_lem_in *lem);
void				lem_init_start_end(t_lem_in *lem);

void				lem_is_command(t_lem_in *lem);
int					lem_is_links_stage(t_lem_in *lem);
void				lem_is_duplicate_node(t_lem_in *lem);
void				lem_is_duplicate_link(t_lem_in *lem,
					t_link *links, char *name);
int					lem_is_green_list(t_link *link, t_link *list);

void				lem_parser(t_lem_in *lem);

void				lem_free(t_lem_in *lem);
void				lem_link_free(t_link **links);

void				lem_perror_exit(char *error);
void				lem_free_exit(char *error, t_lem_in *lem);
void				lem_free_noline_exit(char *error, t_lem_in *lem);

void				lem_node_mem(t_node **room);
void				lem_link_mem(t_link **link);
void				lem_path_mem(t_path **path);
void				lem_link_add(t_link **links, char *name, int x, int y);

void				lem_paths_sort(t_path **paths);
void				lem_links_reverse(t_link **links);
t_node				*lem_get_node_by_name(t_node *rooms, char *name);
t_node				*lem_get_close_node_to_end(t_lem_in *lem, t_link *links);

#endif
