/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:51:33 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 16:44:09 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_lowest(t_list **pile, int current)
{
	t_list	*temp;

	temp = *pile;
	while (temp)
	{
		if (temp->content < current)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_in_order(t_list **pile_a)
{
	t_list	*temp;
	t_list	*next;

	if (!(*pile_a))
		return (0);
	temp = *pile_a;
	next = (*pile_a)->next;
	if (is_lowest(pile_a, (*pile_a)->content))
		return (0);
	while (temp && next)
	{
		if (temp->content > next->content)
			return (0);
		temp = temp->next;
		next = next->next;
	}
	return (1);
}

void	results(t_list **pile_a, t_list **pile_b, int result)
{
	if (result == -1)
		write(2, "Error\n", 6);
	else if (result == 1 && is_in_order(pile_a) && (*pile_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clear(pile_b, 0);
	ft_clear(pile_a, 0);
}
