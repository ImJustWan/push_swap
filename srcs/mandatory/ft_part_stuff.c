/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:30:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/18 12:31:12 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_median(t_list **pile, int value, int size)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = *pile;
	while (temp)
	{
		// printf("median IS %d AND CONTENT IS %d \n", size/2, temp->content);
		if (temp->content > value)
			count++;
		temp = temp->next;
	}
	if (count == size / 2 || (count > size / 2 && count < (size / 2) + 1))
		return (1);
	else
		return (0);
}

int	ft_find_median(t_list **pile)
{
	int 	size;
	t_list	*current;

	size = ft_lstsize(*pile);
	current = *pile;
	while (current)
	{
		if (ft_is_median(pile, current->content, size))
			return (current->content);
		current = current->next;
	}
	return (current->content);
}

// void	ft_part_stuff(t_list **pile_a, t_list **pile_b)
// {
// 	int		median_a;
// 	int		size;
// 	int		count_start;
// 	int		count_end;
// 	int		current;

// 	size = ft_lstsize(*pile_a);
// 	median_a = ft_find_median(pile_a);
// 	while (ft_lstsize(*pile_a) > (size / 2))
// 	{
// 		// else
// 		// 	printf("not in order sorry bae\n");
// 		count_start = at_the_beginning(pile_a, median_a);
// 		count_end = at_the_end(pile_a, median_a);
// 		current = (*pile_a)->content;
// 		// printf("COUNT START IS %d AND END IS %d \n", count_start, count_end);
// 		if (count_start < count_end)
// 		{
// 			// printf("rotating a \t\t\t\t CAUSE START < END\n");
// 			while (current < median_a)
// 			{	
// 				ft_rotate_a(pile_a);
// 				current = (*pile_a)->content;
// 			}
// 		}
// 		else
// 		{
// 			// printf("rev_rotating until %d is <= %d\n", median_a, current);
// 			while (current < median_a)
// 			{
// 				// printf("rev rotating a\n");
// 				if (current >= median_a)
// 					break ;
// 				ft_rev_rotate_a(pile_a);
// 				current = (*pile_a)->content;
// 				// printf("it's a %d so please rev rotate a\n", current);
// 			}
// 		}
// 		if (current >= median_a)
// 			ft_fill_b(pile_a, pile_b, median_a);
// 	}
// 	// ft_push_b(pile_a, pile_b);
// }

void	ft_part_stuff(t_list **pile_a, t_list **pile_b)
{
	int		median_a;
	int		size;
	int		count_start;
	int		count_end;
	int		current;

	size = ft_lstsize(*pile_a);
	median_a = ft_find_median(pile_a);
	while (ft_lstsize(*pile_a) > (size / 2) && ft_lstsize(*pile_a) != 3)
	{
		// if (ft_is_in_order_a(pile_a))
		// {
		// 	printf("NO NO BREAK IT BREAK IT\n");
		// 	break ;
		// }
		// else
		// 	printf("not in order sorry bae\n");
		count_start = at_the_beginning(pile_a, median_a);
		count_end = at_the_end(pile_a, median_a);
		current = (*pile_a)->content;
		// printf("COUNT START IS %d AND END IS %d \n", count_start, count_end);
		if (count_start < count_end)
		{
			// printf("rotating a \t\t\t\t CAUSE START < END\n");
			while (current > median_a)
			{	
				ft_rotate_a(pile_a);
				current = (*pile_a)->content;
			}
		}
		else
		{
			// printf("rev_rotating until %d is <= %d\n", median_a, current);
			while (current > median_a)
			{
				ft_rev_rotate_a(pile_a);
				current = (*pile_a)->content;
				// printf("rev rotating a\n");
				if (current <= median_a)
					break ;
				
				// printf("it's a %d so please rev rotate a\n", current);
			}
		}
		if (current <= median_a)
			ft_fill_b(pile_a, pile_b, median_a);
	}
	// ft_push_b(pile_a, pile_b);
}