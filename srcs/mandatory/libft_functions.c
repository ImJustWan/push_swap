/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:52:36 by tgibier           #+#    #+#             */
/*   Updated: 2023/01/27 14:44:58 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	len(long int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*nbtoa(char *tab, long int nb, int i)
{
	if (nb < 0)
	{
		tab[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		tab[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char		*tab;
	long int	nb;
	int			i;

	nb = n;
	i = len(n);
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (0);
	tab[i--] = '\0';
	if (nb == 0)
	{
		tab[0] = 48;
		return (tab);
	}
	else
		tab = nbtoa(tab, nb, i);
	return (tab);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		return (-res);
	return (res);
}
