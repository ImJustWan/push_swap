/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:02:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/15 14:58:43 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*pile_a;
	t_list	*temp;
	t_list	*next;

	pile_a = NULL;
	// printf("ARGC IS %d \n", argc);
	if (argc <= 2)
		return (0);
	else
	{
		i = 0;
		while (argv[++i])
		{
			ft_magic(&pile_a, argv[i]) ;
		}
	}
	temp = pile_a;
	ft_push_swap(pile_a);
	// while (temp)
	// {
	// 	next = temp->next;
	// 	free(temp);
	// 	temp = next;
	// }
}


/*              NEXT STEPS

                - if current < size / 2
                    -  if around (b) > 1/4 (rb / rrb)
                        -  nouvelle recherche of next */