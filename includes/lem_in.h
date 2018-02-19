#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define Y lem->i
# define X lem->j

typedef	struct		s_link
{
	char 			*name;
	struct s_link	*next;
}					t_link;

typedef	struct		s_node
{
	char 			*name;
	t_link 			*links;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef	struct		s_lem_in
{
	int				ants;
	t_node			*rooms;
	t_node			*start;
	t_node			*end;
	int				flag_start;
	int				flag_end;
	char			*buf;
	int				i;
	int				j;
}					t_lem_in;

void				lem_parser(t_lem_in *lem);

void				lem_free(t_lem_in *lem);

void				lem_exit(char *error);
void				lem_perror_exit(char *error);
void				lem_free_exit(char *error, t_lem_in *lem);

void				lem_node_mem(t_node **room);
void				lem_link_mem(t_link **link);

#endif
