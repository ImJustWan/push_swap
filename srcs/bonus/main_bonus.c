/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:30:40 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 16:48:28 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*creating_list(t_list *pile_a, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_magic(&pile_a, argv[i]))
		{
			ft_clear(&pile_a, 1);
			exit (1);
		}
	}
	if (ft_verif_unique(pile_a))
	{
		ft_clear(&pile_a, 1);
		exit (1);
	}
	return (pile_a);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	*line;
	int		result;

	if (argc < 2)
		return (0);
	pile_a = NULL;
	pile_b = NULL;
	result = 1;
	pile_a = creating_list(pile_a, argv);
	if (!pile_a)
		exit (1);
	line = get_next_line(0, 0);
	while (line != NULL && result != -1)
	{
		result = checker(&pile_a, &pile_b, line);
		free(line);
		line = get_next_line(0, result);
	}
	if (line)
		free(line);
	results(&pile_a, &pile_b, result);
	return (0);
}
