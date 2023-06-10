/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:07:40 by tgibier           #+#    #+#             */
/*   Updated: 2023/04/15 18:52:57 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_smallest(t_list **pile_a)
{
	t_list	*temp;

	temp = *pile_a;
	while (temp)
	{
		if (!ft_is_lowest(pile_a, temp->content))
		{
			temp->index = 0;
			return ;
		}
		temp = temp->next;
	}
}

static int	find_smaller(t_list **pile_a, int current)
{
	t_list	*temp;

	temp = *pile_a;
	while (temp)
	{
		if (temp->content < current && temp->index == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	indexing(t_list **pile_a)
{
	t_list	*temp;
	int		index;

	find_smallest(pile_a);
	index = 1;
	while (index != ft_lstsize(*pile_a))
	{
		temp = *pile_a;
		while (temp)
		{
			if (temp->index == -1)
			{
				if (find_smaller(pile_a, temp->content) == 0)
				{
					temp->index = index;
					break ;
				}
			}
			temp = temp->next;
		}
		temp->index = index;
		index++;
	}
}
