# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:08:34 by tgibier           #+#    #+#              #
#    Updated: 2023/06/10 22:55:12 by tiffany.gib      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

DIR_SRCS		=	srcs/mandatory

DIR_SRCS_BONUS	=	srcs/bonus

DIR_OBJS		=	objs

SRCS_NAMES =		main.c \
					creating_list.c \
					libft_functions.c \
					ft_split.c \
					lst_functions.c \
					push_swap.c \
					index.c \
					small_list.c \
					push_swap_ft.c \
					push_swap_utils.c \
					parting_stuff.c \
					fill_a.c \
					fill_a_utils.c \

BONUS_NAMES =		main_bonus.c \
					checker.c \
					result.c \
					creating_list.c \
					lst_functions.c \
					libft_functions.c \
					gnl.c \
					gnl_utils.c \
					push_swap_ft.c \
					


OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_BONUS_NAMES	=	${BONUS_NAMES:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

BONUS			=	$(addprefix $(DIR_SRCS_BONUS)/,$(BONUS_NAMES))

OBJS_BONUS		=	$(addprefix $(DIR_OBJS)/,$(OBJS_BONUS_NAMES))

HEAD			=	-Iincludes/

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

# -fsanitize=address

MAKEFLAGS		=	--no-print-directory

all	:	${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[34;5mpushswap\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

bonus	:	all $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(DIR_OBJS)/%.o: $(DIR_SRCS_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

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