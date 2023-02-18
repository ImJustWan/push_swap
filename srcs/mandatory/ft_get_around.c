/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_around.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:15:12 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/15 13:13:53 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int at_the_end(t_list **pile, int median)
{
	int		count_end;
	t_list	*current;

	current = ft_lstlast(*pile);
	count_end = 1;
	while (current && count_end < (ft_lstsize(*pile) / 2))
	{
		if (current->content > median)
			return (count_end);
		count_end++;
		current = current->prev;
	}
	return (count_end);
}


int at_the_beginning(t_list **pile, int median)
{
	int		count_start;
	t_list	*current;

	current = *pile;
	count_start = 0;
	while (current && count_start < (ft_lstsize(*pile) / 2))
	{
		if (current->content > median)
			return (count_start);
		count_start++;
		current = current->next;
	}
	return (count_start);
}

// int ft_around(t_list **pile, int value)
// {
// 	int		around;
// 	t_list	*current;
// 	t_list	*last;

// 	last = ft_lstlast(*pile);
// 	current = *pile;
// 	around = 0;
// 	if (current && current->next && last->prev)
// 	{
// 		if (current->content > value && current->next->content < value 
// 			&& last->content > value && last->prev->content > value)
// 			return (0);
// 	}
// 	while (current && current->next)
// 	{
// 		if (current->content < value && current->next->content > value)
// 			return (around);
// 		current = current->next;
// 		around++;
// 	}
// 	// printf("AROUND IS %d\n", around);
// 	return (around);
// }

int ft_around(t_list **pile, int value)
{
	int		around;
	t_list	*current;
	t_list	*last;

	last = ft_lstlast(*pile);
	current = *pile;
	around = 0;
	if (current && current->next && last->prev)
	{
		if (current->content < value && current->next->content > value 
			&& last->content < value && last->prev->content < value)
			return (0);
	}
	while (current && current->next)
	{
		around++;
		if (current->content > value && current->next->content < value)
			return (around);
		current = current->next;
	}
	// printf("AROUND IS %d\n", around);
	return (around);
}
