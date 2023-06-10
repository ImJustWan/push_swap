/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:01:22 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/10 16:48:53 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_clear_gnl(t_list *save)
{
	t_list	*temp;
	t_list	*next;

	temp = save;
	while (temp)
	{
		if (temp->text)
			free(temp->text);
		next = temp->next;
		free(temp);
		temp = next;
	}
}

static int	ft_next_nl(t_list *save)
{
	int	i;
	int	len;

	len = 0;
	while (save)
	{
		i = 0;
		while (save->text[i])
		{
			if (save->text[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		save = save->next;
	}
	return (len);
}

static t_list	*ft_clean_save(t_list *save)
{
	t_list	*clean;
	t_list	*last;
	int		i;
	int		j;

	last = ft_lst_last(save);
	i = ft_next_nl(last);
	clean = malloc (sizeof(t_list));
	if (!clean)
		return (NULL);
	clean->next = NULL;
	clean->text = malloc (sizeof(char) * ((BUFFER_SIZE - i) + 1));
	if (!clean->text)
		return (NULL);
	j = 0;
	while (last->text[i])
		clean->text[j++] = last->text[i++];
	clean->text[j] = '\0';
	ft_clear_gnl(save);
	return (clean);
}

static char	*ft_get_line(t_list *save, char *line)
{
	int	i;
	int	j;
	int	size;

	size = ft_next_nl(save);
	line = malloc (sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (save)
	{
		i = 0;
		while (save->text[i])
		{
			if (save->text[i] == '\n')
			{
				line[j++] = save->text[i];
				break ;
			}
			line[j++] = save->text[i++];
		}
		save = save->next;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd, int bop)
{
	static t_list	*save[FOPEN_MAX];
	char			*line;

	if (bop == -1)
		return (ft_clear_gnl(save[fd]), NULL);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	ft_read(fd, &save[fd]);
	if (!save[fd])
	{
		ft_clear_gnl(save[fd]);
		return (NULL);
	}
	line = ft_get_line(save[fd], line);
	if (line[0] == '\0' || line[0] == '\n')
	{
		free(line);
		line = NULL;
		ft_clear_gnl(save[fd]);
		return (NULL);
	}
	save[fd] = ft_clean_save(save[fd]);
	return (line);
}
