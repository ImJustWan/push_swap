/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:09:20 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/04 11:59:18 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stuff(t_list **pile_a, t_list **pile_b)
{
	// t_list	*temp;
	int		size;
	
	while (ft_lstsize(*pile_a) > 0)
	{
		size = ft_lstsize(*pile_a);
		if (ft_find_lowest(*pile_a, size) == 1)
			ft_push_b(pile_a, pile_b);
		else if (ft_find_lowest(*pile_a,size) == 2)
		{
			ft_swap_a(pile_a);
			ft_push_b(pile_a, pile_b);
		}
		else if (ft_find_lowest(*pile_a, size) == size)
		{
			ft_rev_rotate_a(pile_a);
			ft_push_b(pile_a, pile_b);
		}
		// if (!ft_is_in_order_a(pile_a)
		// 	return ; 
		else
			ft_rotate_a(pile_a);
	}
}


int	ft_find_lowest(t_list *pile_a, int size_arg)
{
	int	i;
	int	rang;
	int	lowest;

	i = 0;
	rang = 1;
	lowest = pile_a->content;
	while (pile_a && i < size_arg)
	{
		i++;
		if (pile_a->content < lowest)
		{
			lowest = pile_a->content;
			rang = i;
		}
		pile_a = pile_a->next;
	}
	return (rang);
}

int	ft_find_highest(t_list *pile_a)
{
	int	i;
	int	rang;
	int	highest;
	t_list *print;

	i = 0;
	rang = 1;
	highest = pile_a->content;
	print = pile_a;
	// while (print)
	// {
	// 	printf("SECOND PILE %d\n", print->content);
	// 	print = print->next;
	// }
	// printf("MY TOP IS %d\n", highest);
	while (pile_a)
	{
		i++;
		if (pile_a->content > highest)
		{
			highest = pile_a->content;
			rang = i;
		}
		pile_a = pile_a->next;
		// printf("MY TOP IS %d\n", rang);
	}
	return (rang);
}

int	ft_is_in_order_a(t_list **pile_a)
{
	int		current;
	t_list	*temp;
	t_list	*next;

	temp = *pile_a;
	next = (*pile_a)->next;
	while (temp && next)
	{
		if (temp->content > next->content)
		{
			if (!ft_is_highest_of_b(pile_a, temp->content))
			{
				// printf("it's highest of a you're good\n");
				while (temp && next)
				{
					if (temp->content > next->content && ft_is_highest_of_b(pile_a, temp->content))
						return (1);
					temp = temp->next;
					next = next->next;
				}
				return (0);
			}
			return (1);
		}
		temp = temp->next;
		next = next->next;
	}
	return (0);
}

int	ft_is_in_order_b(t_list **pile_b)
{
	int		current;
	t_list	*temp;
	t_list	*next;

	temp = *pile_b;
	next = (*pile_b)->next;
	while (temp && next)
	{
		if (temp->content < next->content)
		{
			// if (temp->content == ft_is_lowest_of_b(pile_b, temp->content))
			// {
			// 	printf("it's lowest of b you're good\n");
			// 	while (temp && next)
			// 	{
			// 		if (temp->content < next->content)
			// 			return (1);
			// 		temp = temp->next;
			// 		next = next->next;
			// 	}
			// }
			return (1);
		}
		temp = temp->next;
		next = next->next;
	}
	return (0);
}

int	ft_is_lowest_of_b(t_list **pile_b, int current)
{
	t_list	*temp;

	temp = *pile_b;
	while (temp)
	{
		if (temp->content < current)
			return (1);
		temp = temp->next;
	}
	// printf("LOWEST\n");
	return (0);
}

int	ft_is_highest_of_b(t_list **pile_b, int current)
{
	t_list	*temp;

	temp = *pile_b;
	while (temp)
	{
		if (temp->content > current)
			return (1);
		temp = temp->next;
	}
	return (0);
}