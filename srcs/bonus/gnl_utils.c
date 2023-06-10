/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:02:28 by tgibier           #+#    #+#             */
/*   Updated: 2023/04/28 21:04:46 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lst_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	ft_magic_gnl(t_list **save, char *temp, int nb)
{
	t_list	*new;
	t_list	*last_node;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->text = malloc (sizeof(char) * (nb + 1));
	if (!new->text)
		return ;
	i = 0;
	while (temp[i] && i < nb)
	{
		new->text[i] = temp[i];
		i++;
	}
	new->text[i] = '\0';
	if (*save == NULL)
	{
		*save = new;
		return ;
	}
	last_node = ft_lst_last(*save);
	last_node->next = new;
}

void	ft_read(int fd, t_list **save)
{
	int		nb;
	char	*temp;

	nb = 1;
	while (nb != 0 && !ft_new_line(*save))
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return ;
		nb = (int)read(fd, temp, BUFFER_SIZE);
		if (nb == -1 || ((*save) == NULL && nb == 0))
		{
			free(temp);
			break ;
		}
		temp[nb] = '\0';
		ft_magic_gnl(save, temp, nb);
		free(temp);
	}
}

int	ft_new_line(t_list *save)
{
	int		i;
	t_list	*last;

	if (!save)
		return (0);
	last = ft_lst_last(save);
	i = 0;
	while (last->text[i])
	{
		if (last->text[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
