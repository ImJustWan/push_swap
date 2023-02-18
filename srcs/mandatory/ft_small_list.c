/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:42:07 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/18 12:18:17 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_bf_last(t_list **pile)
{
	t_list	*temp;

	temp = *pile;
	while (temp->next->next)
		temp = temp->next;
	return (temp->content);
}

void	ft_handle_three_b(t_list **pile_b)
{
	int	first;
	int	second;
	int	third;

	first = (*pile_b)->content;
	second = (*pile_b)->next->content;
	third = (*pile_b)->next->next->content;
	if ((first > third && third > second) || (third > second && second > first) 
		|| (second > first && first > third))
	{
		ft_swap_b(pile_b);
		if (first > second)
			ft_rotate_b(pile_b);
		if (third > second && second > first)
			ft_rev_rotate_b(pile_b);
	}
	else if (second > third && third > first)
		ft_rotate_b(pile_b);
	else if (third > first && first > second)
		ft_rev_rotate_b(pile_b);
}

void	ft_handle_three_a(t_list **pile_a)
{
	int	first;
	int	second;
	int	third;

	first = (*pile_a)->content;
	second = (*pile_a)->next->content;
	third = (*pile_a)->next->next->content;
	if ((second > third && third > first) || (third > first && first > second)
		|| (first > second && second > third))
	{
		ft_swap_a(pile_a);
		if (second > first)
			ft_rotate_a(pile_a);
		else if (second > third)
			ft_rev_rotate_a(pile_a);
	}
	else if (second > first && first > third)
		ft_rev_rotate_a(pile_a);
	else if (first > third && third > second)
		ft_rotate_a(pile_a);	
}

void ft_small_list_b(t_list **pile_b, int size)
{
	if (size == 1)
		return ;
	if (size == 2 && ft_is_in_order_b(pile_b))
		ft_swap_b(pile_b);
	if (size == 3)
		ft_handle_three_b(pile_b);
}

void ft_small_list_a(t_list **pile_a, t_list **pile_b, int size)
{
	if (size == 1)
		return ;
	if (size == 2 && ft_is_in_order_a(pile_a))
		ft_swap_a(pile_a);
	if (size == 3)
		ft_handle_three_a(pile_a);
	if (size > 3)
	{
		// printf("handling small list\n");
		while (ft_lstsize(*pile_a) > 3)
		{
			if ((*pile_a)->content < ft_find_median(pile_a))
				ft_push_b(pile_a, pile_b);
			ft_rotate_a(pile_a);
		}
		ft_small_list_b(pile_b, ft_lstsize(*pile_b));
		ft_small_list_a(pile_a, pile_b, ft_lstsize(*pile_a));
		while (ft_lstsize(*pile_b) > 0)
			ft_push_a(pile_a, pile_b);
		printf("PUSH A BITCHES\n");
	}
	// return ;

}