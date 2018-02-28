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

# define FLAG_SIZE				6

# define F_VISUALIZE			0
# define F_DEBUG_ANT_STATUS 	1
# define F_DEBUG_ALL_PATHS 		2
# define F_DEBUG_SHORT_PATH 	3
# define F_DEBUG_COUNT_STEPS	4
# define F_DEBUG_COUNT_NODE		5

# define Y lem->vis.i
# define X lem->vis.j

typedef	struct		s_link
{
	char			*name;
	int				x;
	int				y;
	int				ant;
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

typedef	struct		s_visualizer
{
	char			**board;
	int				dy;
	int				dx;
	int				sy;
	int				sx;
	int				y;
	int				x;
	int				i;
	int				j;
}					t_visualizer;

typedef	struct		s_lem_in
{
	int				ants;
	int				ants_count;
	int				end_ants;
	int				way_ants;
	int				count_node;
	int				count_steps;
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
	char			flags[FLAG_SIZE];
	int				line_number;
	t_visualizer	vis;
}					t_lem_in;

void				lem_visu_draw_pipes(t_lem_in *lem);
int					lem_visualizer(t_lem_in *lem);
void				lem_debuger(t_lem_in *lem);

void				lem_get_paths(t_lem_in *lem);
void				lem_print_ants_travel(t_lem_in *lem);

void				lem_init(t_lem_in *lem);
void				lem_init_start_end(t_lem_in *lem);

int					lem_is_command(t_lem_in *lem);
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
t_link				*lem_get_static_links(t_path *paths, int size);
void				lem_link_add(t_link **links, char *name, int x, int y);

void				lem_push_ants(t_lem_in *lem);
void				lem_paths_sort(t_path **paths);
void				lem_links_reverse(t_link **links);
t_node				*lem_get_node_by_name(t_node *rooms, char *name);

#endif
