/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_around.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:43:57 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/04 11:59:57 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_turn_around(t_list **pile_a)
{
    t_list  *current;

    current = *pile_a;
    if (current->content >= (ft_lstsize(*pile_a) / 2)
        && current->next->content >= (ft_lstsize(*pile_a) / 2))
    {
        if (current->content > current->next->content)
        {
            if (ft_find_highest(*pile_a) != 1)
            {
                // printf("doin' it baby\n");
                ft_swap_a(pile_a);
            }
        }    
    }
}