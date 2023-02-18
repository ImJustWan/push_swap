/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:09:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/11 22:00:58 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		main(int argc, char **argv);

int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *nptr);
int		ft_check_params(char *param);
int		ft_find_bf_last(t_list **pile);
int		ft_verif_unique(t_list *params);
int		ft_is_in_order_a(t_list **pile_a);
int		ft_is_in_order_b(t_list **pile_b);
int		ft_find_median(t_list **pile);
int		ft_around(t_list **pile, int value);
int 	at_the_end(t_list **pile, int median);
int		at_the_beginning(t_list **pile, int median);
int		ft_find_lowest(t_list *params, int size_arg);
int		ft_is_lowest_of_b(t_list **pile_b, int current);
int		ft_is_highest_of_b(t_list **pile_b, int current);
int		ft_find_highest(t_list *params);

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

void	ft_push_swap(t_list *pile_a);
void	ft_swap_a(t_list **pile_a);
void	ft_swap_b(t_list **pile_b);
void	ft_rotate_a(t_list **pile_a);
void	ft_rotate_b(t_list **pile_b);
void	ft_turn_around(t_list **pile_a);
void	ft_rev_rotate_a(t_list **pile_a);
void	ft_rev_rotate_b(t_list **pile_b);
void	ft_fill_a(t_list **pile_a, t_list **b);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_small_list_b(t_list **pile_b, int size);
void	ft_push_a(t_list **pile_a, t_list **pile_b);
void	ft_push_b(t_list **pile_a, t_list **pile_b);
void	ft_chunking(t_list **pile_a, t_list **pile_b);
void	ft_part_stuff(t_list **pile_a, t_list **pile_b);
void	ft_sort_stuff(t_list **pile_a, t_list **pile_b);
void	ft_params_into_list(t_list **params, char **temp);
void	ft_both(t_list **pile_a, t_list **pile_b, int boool);
void	ft_fill_b(t_list **pile_a, t_list **pile_b, int median_a);
void	ft_small_list_a(t_list **pile_a, t_list **pile_b, int size);

size_t	ft_strlen(const char *s);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_magic(t_list **params, char *content);

#endif