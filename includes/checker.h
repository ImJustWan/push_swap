/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:00:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 14:20:56 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	char			*text;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		main(int argc, char **argv);

t_list	*creating_list(t_list *pile_a, char **argv);
int		ft_verif_unique(t_list *params);
int		ft_magic(t_list **params, char *content);
void	ft_clear(t_list **save, int error);
int		is_in_order(t_list **pile_a);

char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

int		checker(t_list **pile_a, t_list **pile_b, char *line);
void	results(t_list **pile_a, t_list **pile_b, int result);

t_list	*ft_lst_last(t_list	*node);
char	*get_next_line(int fd, int bop);
int		ft_new_line(t_list *save);
void	ft_read(int fd, t_list **save);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_swap(t_list **pile, int boool);
void	ft_rotate(t_list **pile, int boool);
void	ft_rev_rotate(t_list **pile, int boool);
void	ft_push(t_list **pile_from, t_list **pile_to, int boool);
void	ft_both(t_list **pile_a, t_list **pile_b, int boool);

#endif
