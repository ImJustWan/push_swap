/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:52:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/15 12:01:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **pile_a)
{
	int		temp;
	t_list	*next;

	next = (*pile_a)->next;
	temp = (*pile_a)->content;
	(*pile_a)->content = next->content;
	next->content = temp;
	write (1, "sa\n", 3);
}

void	ft_swap_b(t_list **pile_b)
{
	int		temp;
	t_list	*next;

	next = (*pile_b)->next;
	temp = (*pile_b)->content;
	(*pile_b)->content = next->content;
	next->content = temp;
	write (1, "sb\n", 3);
}

void	ft_push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*next;
	t_list	*new;
	t_list	*temp;

	temp = *pile_b;
	next = (*pile_b)->next;
	new = ft_lstnew((*pile_b)->content);
	if (!new)
		return ;
	ft_lstadd_front(pile_a, new);
	*pile_b = next;
	free(temp);
	write (1, "pa\n", 3);
}

void	ft_push_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*next;
	t_list	*new;
	t_list	*temp;

	temp = *pile_a;
	next = (*pile_a)->next;
	new = ft_lstnew((*pile_a)->content);
	if (!new)
		return ;
	ft_lstadd_front(pile_b, new);
	*pile_a = next;
	free(temp);
	write (1, "pb\n", 3);
}
