/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/18 13:01:26 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void ft_riverdeep(t_list **pile_a, t_list **pile_b)
{
    if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b) != 1))
    {
        if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b)) 
        <= (ft_lstsize(*pile_b) / 2))
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
				// printf("STUCK IN THE RIVER\n");
            }
        }
    }
}

static void ft_mountainhigh(t_list **pile_a, t_list **pile_b)
{
    if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b) != 1))
    {
        if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b))
        <= (ft_lstsize(*pile_b) / 2))
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
				// printf("STUCK IN THE MOUNTAIN\n");
            }
        }
    }
}

static void ft_riverdeep_mountainhigh(t_list **pile_a, t_list **pile_b)
{
    int		current_a;
	int		current_b;
	int		around;
	t_list	*print;

	current_a = (*pile_a)->content;
	around = ft_around(pile_b, current_a);
    if (!ft_is_lowest_of_b(pile_b, current_a))
    {
        ft_riverdeep(pile_a, pile_b);
    }
	else
    {
       ft_mountainhigh(pile_a, pile_b);
    }
}

static void ft_stuckinthemiddle(t_list **pile_a, t_list **pile_b)
{
   	int		current_a;
	int		around;

	current_a = (*pile_a)->content;
	around = ft_around(pile_b, current_a);
    if (ft_lstsize(*pile_b) > 1)
    {
        if (around != 0)
        {
            // printf("AROUND %d SIZE IS %d\n", around, ft_lstsize(*pile_a) / 2);
            if (around <= (ft_lstsize(*pile_a) / 2))
            {
                while (1)
                {
                    if (current_a > (*pile_b)->content 
                        && current_a < (ft_lstlast(*pile_b))->content)
                        break ;
                    ft_rotate_b(pile_b);
                }
            }
            else
            {
                while (1)
                {
                    if (current_a > (*pile_b)->content 
                        && current_a < (ft_lstlast(*pile_b))->content)
                        break ;
					// printf("CURRENT_A IS %d AND CURRENT B IS %d AND LAST BS IS %d\n", current_a, (*pile_b)->content, (ft_lstlast(*pile_b))->content);
                    ft_rev_rotate_b(pile_b);
					// printf("STUCK IN THE MID\n");
                }
            }
        }
    }
}

void ft_fill_b(t_list **pile_a, t_list **pile_b, int median_a)
{
	int		current_a;
	int		current_b;
	int		around;
	t_list	*print;

	// printf("filling b\n");
	current_a = (*pile_a)->content;
	// printf("CURRENT_A IS %d\n", current_a);
	around = ft_around(pile_b, current_a);
	// printf("AROUND IS %d\n", around);

	if (ft_lstsize(*pile_b) > 1 && 
        (!ft_is_lowest_of_b(pile_b, current_a) 
        || !ft_is_highest_of_b(pile_b, current_a)))
	{
		ft_riverdeep_mountainhigh(pile_a, pile_b);
	}
	else 
	{
		ft_stuckinthemiddle(pile_a, pile_b);
	}
	ft_push_b(pile_a, pile_b);
	// printf("size this sh*t is %d\n", ft_lstsize(*pile_b));
	// printf("LAST IS %d\n", (ft_lstlast(*pile_b))->content);	
	// print = *pile_b;
	// while (print)
	// {
	// 	printf("SECOND PILE %d\n", print->content);
	// 	print = print->next;
	// }
	// if (ft_lstsize(*pile_b) == 3)
	// 	ft_small_list_b(pile_b, ft_lstsize(*pile_b));
}

// static void ft_riverdeep(t_list **pile_a, t_list **pile_b)
// {
//     if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b) != 1))
//     {
//         if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b)) 
//         <= (ft_lstsize(*pile_b) / 2))
//         {
//             while (ft_find_highest(*pile_b) != ft_lstsize(*pile_b))
//             {
//                 if (ft_find_highest(*pile_b) == ft_lstsize(*pile_b))
//                     break ;
//                 ft_rotate_b(pile_b);
//             }
//         }
//         else
//         {
//             while (ft_find_highest(*pile_b) != ft_lstsize(*pile_b))
//             {
//                 if (ft_find_highest(*pile_b) == ft_lstsize(*pile_b))
//                     break ;
//                 ft_rev_rotate_b(pile_b);
//             }
//         }
//     }
// }

// static void ft_mountainhigh(t_list **pile_a, t_list **pile_b)
// {
//     if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b) != 1))
//     {
//         if (ft_find_lowest(*pile_b, ft_lstsize(*pile_b))
//         <= (ft_lstsize(*pile_b) / 2))
//         {
//             while (ft_find_highest(*pile_b) != ft_lstsize(*pile_b))
//             {
//                 if (ft_find_highest(*pile_b) == ft_lstsize(*pile_b))
//                     break ;
//                 ft_rotate_b(pile_b);
//             }
//         }
//         else
//         {
//             while (ft_find_highest(*pile_b) != ft_lstsize(*pile_b))
//             {
//                 if (ft_find_highest(*pile_b) == ft_lstsize(*pile_b))
//                     break ;
//                 ft_rev_rotate_b(pile_b);
//             }
//         }
//     }
// }

// static void ft_riverdeep_mountainhigh(t_list **pile_a, t_list **pile_b)
// {
//     int		current_a;
// 	int		current_b;
// 	int		around;

// 	current_a = (*pile_a)->content;
// 	around = ft_around(pile_b, current_a);
//     if (!ft_is_lowest_of_b(pile_b, current_a))
//     {
//         ft_riverdeep(pile_a, pile_b);
//     }
// 	else
//     {
//        ft_mountainhigh(pile_a, pile_b);
//     }
// }

// static void ft_stuckinthemiddle(t_list **pile_a, t_list **pile_b)
// {
//    	int		current_a;
// 	int		around;

// 	current_a = (*pile_a)->content;
// 	around = ft_around(pile_b, current_a);
//     if (ft_lstsize(*pile_b) > 1)
//     {
//         if (around != 0)
//         {
//             // printf("AROUND %d SIZE IS %d\n", around, ft_lstsize(*pile_b));
//             if (around <= (ft_lstsize(*pile_b) / 2))
//             {
//                 while (1)
//                 {
//                     if (current_a < (*pile_b)->content 
//                         && current_a > (ft_lstlast(*pile_b))->content)
//                         break ;
//                     ft_rotate_b(pile_b);
//                 }
//             }
//             else
//             {
//                 while (1)
//                 {
//                     if (current_a < (*pile_b)->content 
//                         && current_a > (ft_lstlast(*pile_b))->content)
//                         break ;
// 					// printf("rev rotate stuck in the middle\n");
//                     ft_rev_rotate_b(pile_b);
//                 }
//             }
//         }
//     }
// }

// void ft_fill_b(t_list **pile_a, t_list **pile_b, int median_a)
// {
// 	int		current_a;
// 	int		current_b;
// 	int		around;
// 	t_list	*print;

// 	// printf("filling b\n");
// 	current_a = (*pile_a)->content;
// 	// printf("CURRENT_A IS %d\n", current_a);
// 	around = ft_around(pile_b, current_a);
// 	// printf("AROUND IS %d\n", around);
// 	if (ft_lstsize(*pile_b) > 1 && 
// 		(!ft_is_lowest_of_b(pile_b, current_a) 
// 			|| !ft_is_highest_of_b(pile_b, current_a)))
// 	{
// 		// printf("riverdeep/mountainhigh %d\n", current_a);
// 		ft_riverdeep_mountainhigh(pile_a, pile_b);
// 	}
// 	else 
// 	{
// 		ft_stuckinthemiddle(pile_a, pile_b);
// 	}
// 	// printf("\t\t\t\t\t\t\t\t\t\tCURRENT_A IS %d\n", (*pile_a)->content);
// 	ft_push_b(pile_a, pile_b);
// 	// if ((*pile_b)->next)
// 	// {
// 	// 	if ((*pile_b)->content < (*pile_b)->next->content)
// 	// 		ft_swap_b(pile_b);
// 	// }
// 	// printf("size this sh*t is %d\n", ft_lstsize(*pile_b));
// 	// printf("LAST IS %d\n", (ft_lstlast(*pile_b))->content);	
// 	// print = *pile_b;
// 	// while (print)
// 	// {
// 	// 	printf("SECOND PILE %d\n", print->content);
// 	// 	print = print->next;
// 	// }
// 	// if (ft_lstsize(*pile_b) == 3)
// 	// 	ft_small_list_b(pile_b, ft_lstsize(*pile_b));
// }