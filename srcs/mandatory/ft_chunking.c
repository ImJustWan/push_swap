/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:39:32 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/15 11:45:15 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_chunk(t_list **pile, int value, int chunk)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = *pile;
	while (temp)
	{
		// printf("median IS %d AND CONTENT IS %d \n", value, temp->content);
		if (temp->content > value)
			count++;
		temp = temp->next;
	}
	if (count == chunk - 1 || (count > chunk - 1 && count < chunk + 1))
		return (1);
	else
		return (0);
}

static int	ft_find_chunk(t_list **pile, int chunk)
{
	t_list	*current;

	current = *pile;
	while (current)
	{
		if (ft_is_chunk(pile, current->content, chunk))
		{
			// printf("CURRENT IS %d CHUNK IS %d\n", current->content, chunk);
			return (current->content);
		}
		current = current->next;
	}
	return (0);
}



void	ft_chunking(t_list **pile_a, t_list **pile_b)
{
	int		chunk;
	int		size;
	int		count_start;
	int		count_end;
	int		chunk_lim;
	int		current;
	int		counter;
	t_list	*temp;

	size = ft_lstsize(*pile_a);
	chunk = size / 10;
	
	temp = *pile_a;
	while (*pile_a)
	{
		size = ft_lstsize(*pile_b);
		chunk_lim = ft_find_chunk(pile_a, size / 10);
		while (ft_lstsize(*pile_b) < size + chunk)
		{
			count_start = at_the_beginning(pile_a, chunk_lim);
			count_end = at_the_end(pile_a, chunk_lim);
			current = (*pile_a)->content;
			if (count_start < count_end)
			{
				// printf("rotating a \t\t\t\t CAUSE START < END\n");
				while (current < chunk_lim)
				{	
					ft_rotate_a(pile_a);
					current = (*pile_a)->content;
				}
			}
			else
			{
				// printf("rev_rotating until %d is <= %d\n", median_a, current);
				while (current < chunk_lim)
				{
					// printf("rev rotating a\n");
					if (current >= chunk_lim)
						break ;
					ft_rev_rotate_a(pile_a);
					current = (*pile_a)->content;
					// printf("it's a %d so please rev rotate a\n", current);
				}
			}
			if (current >= chunk_lim)
			{
				// printf("CURRENT IS %d LIM IS %d SIZE OF A IS %d\n", current, chunk_lim, ft_lstsize(*pile_a));
				ft_fill_b(pile_a, pile_b, chunk_lim);
				counter++;
			}
		}
		// printf("\t\t\t\t\t\t\t\t\t\t\t\tAUGMENTING CHUNK SIZE\n");
		chunk += size / 10;
	}
	// while (ft_find_lowest(*pile_b, ft_lstsize(*pile_b)) != 1)
	// 	ft_rev_rotate_b(pile_b);
	// *pile_a = *pile_b;
	// *pile_b = NULL;
}

		
		