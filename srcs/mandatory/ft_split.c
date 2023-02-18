/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:59:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/02/15 14:57:50 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include "push_swap.h"

// static int	ft_issep(char s, char c)
// {
// 	return (s == c);
// }

// static int	ft_count(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s && ft_issep(*s, c))
// 			s++;
// 		if (*s && !ft_issep(*s, c))
// 		{
// 			count++;
// 			while (*s && !ft_issep(*s, c))
// 				s++;
// 		}
// 	}
// 	return (count);
// }

// static char	*ft_makestr(char const *s, char c)
// {
// 	char	*str;
// 	int		i;
// 	int		nb;

// 	nb = 0;
// 	i = 0;
// 	while (s[nb] && !ft_issep(s[nb], c))
// 		nb++;
// 	str = malloc (sizeof(char) * (nb + 1));
// 	if (!str)
// 		return (NULL);
// 	while (i < nb)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }

// static void	ft_free(char **split, int index)
// {
// 	while (index >= 0)
// 		free(split[index--]);
// 	free(split);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char		**split;
// 	int			j;
// 	int const	count = ft_count(s, c);

// 	if (!s)
// 		return (0);
// 	j = -1;
// 	split = malloc (sizeof(char *) * (count + 1));
// 	if (!split)
// 		return (NULL);
// 	while (++j < count)
// 	{
// 		while (*s && ft_issep(*s, c))
// 			s++;
// 		split[j] = ft_makestr(s, c);
// 		if (!split[j])
// 		{
// 			ft_free(split, j);
// 			return (NULL);
// 		}
// 		while (*s && !ft_issep(*s, c))
// 			s++;
// 	}
// 	split[j] = 0;
// 	return (split);
// }
