/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:06:37 by jerrok            #+#    #+#             */
/*   Updated: 2021/11/15 14:59:18 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev_str(char *s)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	while (i < j)
	{
		if (s[i] == '-')
			i++;
		j--;
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
	}
	return (s);
}

static int	ft_size_str(int n)
{
	int	i;

	i = 0;
	if (n == 0 || n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_full_str(char *res, int n)
{
	int		i;
	long	long_n;

	i = 0;
	long_n = (long)n;
	if (long_n < 0)
	{
		long_n = -long_n;
		res[i] = '-';
		i++;
	}
	else if (long_n == 0)
	{
		res[i] = '0';
		i++;
	}
	while (long_n != 0)
	{
		res[i] = long_n % 10 + '0';
		long_n /= 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ft_size_str(n) + 1);
	if (!res)
		return ((void *)0);
	res = ft_full_str(res, n);
	res = ft_rev_str(res);
	return (res);
}
