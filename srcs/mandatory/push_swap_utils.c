/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:20:43 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/11 22:36:11 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_params(char *param)
{
	int	i;
	char	*str;

	i = 0;
	while (param[i])
	{
		if ((param[i] < 48 || param[i] > 57) && param[i] != 45)
		{
			printf("(not a number) - Check your params bro\n");
			return (1);
		}
		i++;
	}
	str = ft_itoa(ft_atoi(param));
	if (ft_strlen(param) != ft_strlen(str))
	{
		printf("(overflow) - Check your params bro\n");
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
			{
				printf("(double) - Check your params bro\n");
				return (1);
			}
		}
		params = params->next;
	}
	return (0);
}

t_list	*ft_magic(t_list **params, char *content)
{
	t_list	*new;
	t_list	*temp;
	t_list	*last_node;

	temp = *params;
	new = malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = ft_atoi(content);
	if (*params == NULL)
	{
		*params = new;
		return (*params);
	}
	last_node = ft_lstlast(temp);
	last_node->next = new;
	if (ft_check_params(content) || ft_verif_unique(*params))
	{
		// printf("pas d'params, pas d'chocolat\n");
		return (NULL);
	}
	return (*params);
}

void	ft_params_into_list(t_list **params, char **temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		*params = ft_magic(params, temp[i]);
		if (!(*params))
		{
			// printf("pas d'params, pas d'chocolat\n");
			return ;
		}
		i++;
	}
}
