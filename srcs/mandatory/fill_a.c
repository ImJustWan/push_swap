/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:46:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/05 16:48:42 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_positionning(t_list **pile_a, int current)
{
	if (find_around(pile_a, current) < ft_lstsize(*pile_a) / 2)
	{
		while (1)
		{
			if (current < (*pile_a)->content
				&& current > ft_lstlast(*pile_a)->content)
				return ;
			ft_rotate(pile_a, 1);
		}
	}
	else
	{
		while (1)
		{
			if (current < (*pile_a)->content
				&& current > ft_lstlast(*pile_a)->content)
				break ;
			ft_rev_rotate(pile_a, 1);
		}
	}
}

void	ft_fill_a(t_list **pile_a, t_list **pile_b)
{
	while (ft_lstsize(*pile_b) != 0)
	{
		if (ft_lstsize(*pile_b) > 2)
			check_next_and_last(pile_a, pile_b);
		if (!ft_is_lowest(pile_a, (*pile_b)->content)
			|| !ft_is_highest(pile_a, (*pile_b)->content))
		{
			if (rank_of_lowest(*pile_a) <= ft_lstsize(*pile_a) / 2)
				while (ft_is_lowest(pile_a, (*pile_a)->content))
					ft_rotate(pile_a, 1);
			else
				while (ft_is_lowest(pile_a, (*pile_a)->content))
					ft_rev_rotate(pile_a, 1);
			ft_push(pile_b, pile_a, 1);
		}
		else if ((*pile_b)->content < (*pile_a)->content
			&& (*pile_b)->content > ft_lstlast(*pile_a)->content)
			ft_push(pile_b, pile_a, 1);
		else
		{
			ft_positionning(pile_a, (*pile_b)->content);
			ft_push(pile_b, pile_a, 1);
		}
	}
}
