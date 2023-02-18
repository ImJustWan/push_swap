# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 12:33:02 by tgibier           #+#    #+#              #
#    Updated: 2023/02/15 12:37:04 by tgibier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

DIR_SRCS		=	srcs/mandatory

DIR_OBJS		=	objs

SRCS_NAMES =	ft_chunking.c \
				ft_fill_b.c \
				ft_fill_chunks.c \
				ft_get_around.c \
				ft_part_stuff.c \
				ft_small_list.c \
				ft_sort_stuff.c \
				ft_split.c \
				ft_turn_around.c \
				libft_functions.c \
				lst_functions.c \
				main.c \
				push_swap.c \
				push_swap_ft2.c \
				push_swap_ft.c \
				push_swap_utils.c \




OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Iincludes/

CC				=	cc

CFLAGS			=	-g3 # -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory

all				:	${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[34;5mpushswap\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

re:	fclean all

stop:
	rm ${NAME}

.PHONY:	all clean fclean re bonus