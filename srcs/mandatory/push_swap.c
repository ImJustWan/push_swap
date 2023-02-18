/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/18 13:31:16 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_fill_a(t_list **pile_a, t_list **pile_b)
// {
// 	int	highest;
	
// 	highest = ft_find_highest(*pile_b);
// 	// printf("WHERE IS MY TOP : %d\n", highest);
// 	if (highest < ft_lstsize(*pile_b) / 2)
// 	{
// 		while (ft_find_highest(*pile_b) != 1)
// 		{
// 			if (ft_find_highest(*pile_b) == 1)
// 				break ;
// 			ft_rotate_b(pile_b);
// 		}
// 	}
// 	else
// 	{
// 		while (ft_find_highest(*pile_b) != 1)
// 		{
// 			if (ft_find_highest(*pile_b) == 1)
// 				break ;
// 			ft_rev_rotate_b(pile_b);
// 		}
// 	}
// 	while (ft_lstsize(*pile_b) != 0)
// 		ft_push_a(pile_a, pile_b);
// }

										/* NOW MAKE A FUNCTION THAT DOES RR OR RRR 
												- find next value, (r)rotate accordingly
											
											MAKE ANOTHER FUNCTION TO HANDLE UP TO 6 SMARTLY
											*/



// void	ft_push_swap(t_list *pile_a)
// {
// 	t_list	*temp;
// 	t_list	*next;
// 	t_list	*pile_b;

// 	pile_b = NULL;
// 	temp = pile_a;
// 	// ft_params_into_list(&pile_a, str);
// 	if (!pile_a)
// 		return ;
// 	if (ft_is_in_order_a(&pile_a) == 0)
// 		return ;
// 	if (ft_lstsize(pile_a) <= 6)
// 		ft_small_list_a(&pile_a, &pile_b, ft_lstsize(pile_a));
// 	else if (ft_is_in_order_a(&pile_a) == 1)
// 	{
// 		if (ft_lstsize(pile_a) / 10 > 10)	
// 			ft_chunking(&pile_a, &pile_b);
// 		else
// 		{
// 			while (ft_lstsize(pile_a))
// 				ft_part_stuff(&pile_a, &pile_b);
// 			// ft_small_list_a(&pile_a, &pile_b, ft_lstsize(pile_a));
// 			// while (ft_find_lowest(pile_b, ft_lstsize(pile_b)) != 1)
// 			// 	ft_rev_rotate_b(&pile_b);
// 			// pile_a = pile_b;
// 			// free(pile_b);
// 			// pile_b = NULL;
// 		}
// 	}

	
// 		// while (temp)
// 		// {
// 		// 	next = temp->next;
// 		// 	free(temp);
// 		// 	temp = next;
// 		// }
// 	// while (pile_a)
// 	// {
// 	// 	temp = pile_a->next;
// 	// 	free(pile_a);
// 	// 	pile_a = temp;
// 	// }
// 	// while (pile_b)
// 	// {
// 	// 	temp = pile_b->next;
// 	// 	free(pile_b);
// 	// 	pile_b = temp;
// 	// }
// 	while (pile_a)
// 	{
// 	 	printf("PARAMS %d\n", pile_a->content);
// 	 	pile_a = pile_a->next;
// 	}
// 	while (pile_b)
// 	{
// 		printf("SECOND PILE %d\n", pile_b->content);
// 		pile_b = pile_b->next;
// 	}
// }

static void	ft_bottoms_up(t_list **pile_a, t_list **pile_b)
{
	int	highest;
	
	highest = ft_find_highest(*pile_b);
	// printf("WHERE IS MY TOP %d\n", highest);
	if (highest < ft_lstsize(*pile_b) / 2)
	{
		while (ft_find_highest(*pile_b) != 1)
		{
			if (ft_find_highest(*pile_b) == 1)
				break ;
			ft_rotate_b(pile_b);
		}
	}
	else
	{
		while (ft_find_highest(*pile_b) != 1)
		{
			if (ft_find_highest(*pile_b) == 1)
				break ;
			ft_rev_rotate_b(pile_b);
		}
	}
}

void	ft_fill_a(t_list **pile_a, t_list **pile_b)
{
	int	current_b;
	
	ft_bottoms_up(pile_a, pile_b);
	while (*pile_b && ft_lstsize(*pile_b) != 0)
	{
		current_b = (*pile_b)->content;
		// printf("CURRENT B IS %d AND CURRENT A IS %d \n", current_b, (*pile_a)->content);
		if (!ft_is_lowest_of_b(pile_a, current_b) && ft_find_lowest(*pile_a, ft_lstsize(*pile_a)) == 1)
			ft_push_a(pile_a, pile_b);
		else if (current_b < (*pile_a)->content && current_b > ft_lstlast(*pile_a)->content)
			ft_push_a(pile_a, pile_b);
		else if (ft_around(pile_a, current_b) != 0)
		{
			if (!ft_is_lowest_of_b(pile_a, current_b))
				printf("YEEEEEEPHAAAAAAAAW\n");
			printf("AROUND IS %d and size is %d\n", ft_around(pile_a, current_b), ft_lstsize(*pile_a));
			//  printf("AROUND IS %d and size is %d\n", ft_around(pile_a, current_b), ft_lstsize(*pile_a));
			if (ft_around(pile_a, current_b) < (ft_lstsize(*pile_a) / 2))
            {
                while (1)
                {
                    if ((current_b < (*pile_a)->content 
                        && current_b > (ft_lstlast(*pile_a))->content)
						|| (!ft_is_lowest_of_b(pile_a, current_b) 
						&& ft_find_lowest(*pile_a, ft_lstsize(*pile_a)) == 1))
                        break ;
                    ft_rotate_a(pile_a);
                }
            }
            else
            {
                while (1)
                {
					ft_rev_rotate_a(pile_a);
                    if ((current_b < (*pile_a)->content 
                        && current_b > (ft_lstlast(*pile_a))->content)
						|| (!ft_is_lowest_of_b(pile_a, current_b) 
						&& ft_find_lowest(*pile_a, ft_lstsize(*pile_a)) == 1))
                        break ;
					// printf("CURRENT_B IS %d AND FIRST A IS %d AND LAST A IS %d\n", (*pile_b)->content, (*pile_a)->content, (ft_lstlast(*pile_a))->content);
                    // ft_rev_rotate_a(pile_a);
					// printf("STUCK IN THE MID\n");
                }
            }
		}
	}
}

void	ft_push_swap(t_list *pile_a)
{
	t_list	*pile_b;
	int		size;

	pile_b = NULL;
	size = ft_lstsize(pile_a);
	//ft_params_into_list(&pile_a, str);
	if (!pile_a)
		return ;
	if (ft_is_in_order_a(&pile_a) == 0)
		return ;
	if (ft_lstsize(pile_a) <= 6)
		ft_small_list_a(&pile_a, &pile_b, ft_lstsize(pile_a));
	else if (ft_is_in_order_a(&pile_a) == 1)
	{
		// if (ft_lstsize(pile_a) / 10 > 10)
		while (ft_lstsize(pile_a) != 3)
			ft_part_stuff(&pile_a, &pile_b);
		// printf("SIZE IS %d\n", ft_lstsize(pile_a));
		ft_small_list_a(&pile_a, &pile_b, ft_lstsize(pile_a));
		// ft_sort_stuff(&pile_a, &pile_b);
		ft_fill_a(&pile_a, &pile_b);
	}
	// while (pile_a)
	// {
	//  	printf("PARAMS %d\n", pile_a->content);
	//  	pile_a = pile_a->next;
	// }
	// while (pile_b)
	// {
	// 	printf("SECOND PILE %d\n", pile_b->content);
	// 	pile_b = pile_b->next;
	// }
}