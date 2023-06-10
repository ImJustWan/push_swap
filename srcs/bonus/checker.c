/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:32:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 16:20:22 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	double_it(t_list **pile_a, t_list **pile_b, int boool)
{
	if (!(*pile_a) || !(*pile_b))
		return ;
	if (boool == 1)
	{
		ft_swap(pile_a, 0);
		ft_swap(pile_b, 0);
	}
	if (boool == 2)
	{
		ft_rotate(pile_a, 0);
		ft_rotate(pile_b, 0);
	}
	if (boool == 3)
	{
		ft_rev_rotate(pile_a, 0);
		ft_rev_rotate(pile_b, 0);
	}
}

static int	two_letters(t_list **pile_a, t_list **pile_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a')
		ft_swap(pile_a, 0);
	else if (line[0] == 's' && line[1] == 'b')
		ft_swap(pile_b, 0);
	else if (line[0] == 'r' && line[1] == 'a')
		ft_rotate(pile_a, 0);
	else if (line[0] == 'r' && line[1] == 'b')
		ft_rotate(pile_b, 0);
	else if (line[0] == 'p' && line[1] == 'a')
		ft_push(pile_b, pile_a, 0);
	else if (line[0] == 'p' && line[1] == 'b')
		ft_push(pile_a, pile_b, 0);
	else if (line[0] == 's' && line[1] == 's')
		double_it(pile_a, pile_b, 1);
	else if (line[0] == 'r' && line[1] == 'r')
		double_it(pile_a, pile_b, 2);
	else
		return (-1);
	return (1);
}

static int	at_your_service(t_list **pile_a, t_list **pile_b, char *line)
{
	if (ft_strlen(line) == 3)
		return (two_letters(pile_a, pile_b, line));
	else if (ft_strlen(line) == 4)
	{
		if ((*pile_a) && line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
			ft_rev_rotate(pile_a, 0);
		else if ((*pile_b) && line[0] == 'r'
			&& line[1] == 'r' && line[2] == 'b')
			ft_rev_rotate(pile_b, 0);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
			double_it(pile_a, pile_b, 3);
		else
		{
			return (-1);
		}
	}
	return (1);
}

int	checker(t_list **pile_a, t_list **pile_b, char *line)
{
	int	result;

	result = 1;
	if (ft_strlen(line) < 3 || ft_strlen(line) > 4)
		result = -1;
	else
		result = at_your_service(pile_a, pile_b, line);
	return (result);
}
