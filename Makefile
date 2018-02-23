# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

#FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

DIR_LIB		=	./libft/
LIBFT		=	$(DIR_LIB)libft.a
DIR_LIB_INC	=	$(DIR_LIB)includes/
DIR_LEM_INC	=	./includes/
DIR_LEM		=	./source/
DIR_OBJ		= 	./obj/

HEAD_LEM	=	lem_in.h

C_LEM		=	main.c lem_init.c lem_parser.c\
				lem_get_paths.c lem_push_ants.c\
				lem_valid.c\
				lem_trash.c lem_free.c\
				lem_list_mem.c lem_list_operations.c


OBJ_LEM 	= 	$(C_LEM:.c=.o)
OBJ 		= 	$(addprefix $(DIR_OBJ), $(OBJ_LEM))
INC 		= 	$(addprefix -I, $(DIR_LEM_INC) $(DIR_LIB_INC))
INC_LEM 	= 	$(addprefix $(DIR_LEM_INC), $(HEAD_LEM))


all: lib obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

lib:
	@make -C $(DIR_LIB)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_LEM)%.c $(INC_LEM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files lem_in ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files lem_in ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re 
