/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:45:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/03 15:57:38 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next(t_list **pile_a, t_list **pile_b, int median)
{
	t_list	*temp;
	int		rank;

	(void)pile_b;
	temp = *pile_a;
	rank = 0;
	while (temp)
	{
		if (temp->index <= median)
			return (rank);
		rank++;
		temp = temp->next;
	}
	return (ft_lstsize(*pile_a));
}

static void	ft_handle_three_a(t_list **pile_a)
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
		ft_swap(pile_a, 1);
		if (second > first)
			ft_rotate(pile_a, 1);
		else if (second > third)
			ft_rev_rotate(pile_a, 1);
	}
	else if (second > first && first > third)
		ft_rev_rotate(pile_a, 1);
	else if (first > third && third > second)
		ft_rotate(pile_a, 1);
}

static void	ft_handle_three_b(t_list **pile_b)
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
		ft_swap(pile_b, 2);
		if (first > second)
			ft_rotate(pile_b, 2);
		if (third > second && second > first)
			ft_rev_rotate(pile_b, 2);
	}
	else if (second > third && third > first)
		ft_rotate(pile_b, 2);
	else if (third > first && first > second)
		ft_rev_rotate(pile_b, 2);
}

static void	ft_smallish_list(t_list **pile_a, t_list **pile_b, int median)
{
	while (ft_lstsize(*pile_a) > 3)
	{
		if (find_next(pile_a, pile_b, median) < ft_lstsize(*pile_a) / 2)
			while ((*pile_a)->index >= median)
				ft_rotate(pile_a, 1);
		else
			while ((*pile_a)->index >= median)
				ft_rev_rotate(pile_a, 1);
		if ((*pile_a)->index < median)
			ft_push(pile_a, pile_b, 2);
	}
	ft_small_list(pile_a, pile_b, ft_lstsize(*pile_a));
	if (ft_lstsize(*pile_b) == 1)
		return ;
	if (ft_lstsize(*pile_b) == 2
		&& (*pile_b)->content < (*pile_b)->next->content)
		ft_swap(pile_b, 2);
	if (ft_lstsize(*pile_b) == 3)
		ft_handle_three_b(pile_b);
}

void	ft_small_list(t_list **pile_a, t_list **pile_b, int size)
{
	int	median;

	if (size == 1)
		return ;
	if (size == 2 && (*pile_a)->content > (*pile_a)->next->content)
		ft_swap(pile_a, 1);
	if (size == 3)
		ft_handle_three_a(pile_a);
	if (size > 3)
	{
		median = ft_find_median(pile_a);
		ft_smallish_list(pile_a, pile_b, median);
		while (ft_lstsize(*pile_b) != 0)
			ft_push(pile_b, pile_a, 1);
	}
}
