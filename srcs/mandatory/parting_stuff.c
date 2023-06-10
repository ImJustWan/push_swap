/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parting_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:21:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/10 22:56:33 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bye(t_list **pile_a, t_list **pile_b, int index_lim, int index_mid)
{
	(void)index_mid;
	if ((*pile_a)->index <= index_lim && ft_lstsize(*pile_b) <= 2)
		ft_push(pile_a, pile_b, 2);
	else if ((*pile_a)->index <= index_mid)
		ft_push(pile_a, pile_b, 2);
	else if (((*pile_a)->index <= index_lim && (*pile_a)->index >= index_mid))
	{
		ft_push(pile_a, pile_b, 2);
		if ((*pile_a)->index > index_lim)
			ft_both (pile_a, pile_b, 2);
		else
			ft_rotate(pile_b, 2);
	}
	else
		ft_rotate(pile_a, 1);
}

static void	for_hundred(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		index_lim;
	int		index_mid;

	size = ft_lstsize(*pile_a);
	index_lim = 0;
	while (ft_lstsize(*pile_a) > 3)
	{
		size = ft_lstsize(*pile_a);
		index_lim += size / 2;
		index_mid = (index_lim + ft_lstsize(*pile_b)) / 2;
		while (ft_lstsize(*pile_b) <= index_lim
			&& ft_lstsize(*pile_a) > 3)
			bye(pile_a, pile_b, index_lim, index_mid);
	}
}

static void	for_five_hundred(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		index_lim;
	int		index_mid;
	int		check;

	size = ft_lstsize(*pile_a);
	index_lim = size / 8;
	index_mid = (index_lim + ft_lstsize(*pile_b)) / 2;
	check = index_mid;
	while (ft_lstsize(*pile_a) > 3)
	{
		while (ft_lstsize(*pile_a) >= size - index_lim
			&& ft_lstsize(*pile_a) > 3)
			bye(pile_a, pile_b, index_lim, index_mid);
		index_lim += size / 8;
		index_mid = (index_lim + ft_lstsize(*pile_b)) / 2;
		while (ft_lstlast(*pile_b)->index > check)
		{
			if ((*pile_a)->index > index_lim)
				ft_both(pile_a, pile_b, 3);
			else
				ft_rev_rotate(pile_b, 2);
		}
	}
}

void	ft_part_stuff(t_list **pile_a, t_list **pile_b)
{
	if (ft_lstsize(*pile_a) <= 100)
		for_hundred(pile_a, pile_b);
	else
		for_five_hundred(pile_a, pile_b);
	ft_small_list(pile_a, pile_b, 3);
	ft_fill_a(pile_a, pile_b);
}
