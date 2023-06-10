/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:49:52 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 13:55:22 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list **save, int error)
{
	t_list	*next;

	while (*save)
	{
		next = (*save)->next;
		free(*save);
		*save = next;
	}
	*save = 0;
	if (error == 1)
		write (2, "Error\n", 6);
}

int	ft_check_params(char *param)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strlen(param) == 1 && (param[i] < 48 || param[i] > 57))
		return (1);
	while (param[i])
	{
		if (param[i] == 45 && i != 0)
			return (1);
		if ((param[i] < 48 || param[i] > 57) && param[i] != 45)
			return (1);
		i++;
	}
	str = ft_itoa(ft_atoi(param));
	if (ft_strlen(param) != ft_strlen(str))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	ft_verif_unique(t_list *params)
{
	t_list	*check;
	int		i;

	while (params)
	{
		check = params;
		i = params->content;
		while (check && check->next)
		{
			check = check->next;
			if (i == check->content)
				return (1);
		}
		params = params->next;
	}
	return (0);
}

int	ft_magic(t_list **params, char *content)
{
	t_list	*new;
	t_list	*temp;
	t_list	*last_node;

	if (ft_check_params(content))
		return (0);
	temp = *params;
	new = malloc (sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->index = -1;
	new->content = ft_atoi(content);
	if (*params == NULL)
	{
		*params = new;
		return (1);
	}
	last_node = ft_lstlast(temp);
	last_node->next = new;
	return (1);
}
