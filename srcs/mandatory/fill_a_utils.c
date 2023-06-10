/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:27:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 13:53:04 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_my_place(t_list **pile_a, int first, int last, int tested)
{
	int		count;
	t_list	*temp;

	temp = *pile_a;
	count = 0;
	while (temp && temp->next)
	{
		if (tested < first && tested > last)
			break ;
		last = first;
		temp = temp->next;
		first = temp->content;
		count++;
	}
	return (count);
}

static int	find_cost(t_list **pile_a, int tested)
{
	int		first;
	int		last;
	int		count;

	first = (*pile_a)->content;
	last = ft_lstlast(*pile_a)->content;
	if (!ft_is_highest(pile_a, tested) || !ft_is_lowest(pile_a, tested))
		count = rank_of_lowest(*pile_a);
	else
		count = find_my_place(pile_a, first, last, tested);
	if (count > ft_lstsize(*pile_a) / 2)
		return (ft_lstsize(*pile_a) - count);
	return (count);
}

static void	move_bitch(t_list **pile_b, int last, int next_next, int last_last)
{
	if (next_next <= last && next_next <= last_last)
	{
		ft_rotate(pile_b, 2);
		ft_rotate(pile_b, 2);
	}
	else if (last_last <= last && last_last <= next_next)
	{
		ft_rev_rotate(pile_b, 2);
		ft_rev_rotate(pile_b, 2);
	}
}

void	check_next_and_last(t_list **pile_a, t_list **pile_b)
{
	int	current;
	int	next;
	int	second_next;
	int	last;
	int	second_last;

	current = find_cost(pile_a, (*pile_b)->content);
	last = find_cost(pile_a, ft_lstlast(*pile_b)->content) + 1;
	next = find_cost(pile_a, (*pile_b)->next->content) + 1;
	second_next = last + current + 1;
	second_last = last + current + 1;
	if (ft_lstsize(*pile_b) > 4)
	{
		second_next = find_cost(pile_a, (*pile_b)->next->next->content) + 2;
		second_last = find_cost(pile_a, ft_lstlast(*pile_b)->prev->content) + 2;
	}
	if (current <= next && current <= last
		&& current <= second_next && current <= second_last)
		return ;
	else if (next <= last && next <= second_next && next <= second_last)
		ft_rotate(pile_b, 2);
	else if (last <= next && last <= second_next && last <= second_last)
		ft_rev_rotate(pile_b, 2);
	else
		move_bitch(pile_b, last, second_next, second_last);
}

int	find_around(t_list **pile, int value)
{
	int		around;
	t_list	*current;

	current = *pile;
	around = 0;
	while (current && current->next)
	{
		if (current->content < value && current->next->content > value)
			return (around);
		around++;
		current = current->next;
	}
	return (around);
}
