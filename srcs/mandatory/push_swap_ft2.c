/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:17:32 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/11 21:25:24 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **pile_a)
{
	t_list	*start;
	t_list	*next;
	t_list	*new;

	start = *pile_a;
	next = (*pile_a)->next;
	new = ft_lstnew((*pile_a)->content);
	ft_lstadd_back(pile_a, new);
	*pile_a = next;
	free(start);
	write (1, "ra\n", 3);
}

void	ft_rotate_b(t_list **pile_b)
{
	t_list	*start;
	t_list	*next;
	t_list	*new;

	start = *pile_b;
	next = (*pile_b)->next;
	new = ft_lstnew((*pile_b)->content);
	ft_lstadd_back(pile_b, new);
	*pile_b = next;
	free(start);
	write (1, "rb\n", 3);
}

void	ft_rev_rotate_a(t_list **pile_a)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstnew(ft_lstlast(*pile_a)->content);
	ft_lstadd_front(pile_a, last);
	temp = *pile_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	write (1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_list **pile_b)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstnew(ft_lstlast(*pile_b)->content);
	ft_lstadd_front(pile_b, last);
	temp = *pile_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	write (1, "rrb\n", 4);
}

void	ft_both(t_list **pile_a, t_list **pile_b, int boool)
{
	if (boool == 1)
	{
		ft_swap_a(pile_a);
		ft_swap_b(pile_b);
		write (1, "ss\n", 3);
	}
	if (boool == 2)
	{
		ft_rotate_a(pile_a);
		ft_rotate_b(pile_b);
		write (1, "rr\n", 3);
	}
	if (boool == 3)
	{
		ft_rev_rotate_a(pile_a);
		ft_rev_rotate_b(pile_b);
		write (1, "rrr\n", 4);
	}
}
