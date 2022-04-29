/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:45:35 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/26 18:16:48 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc (sizeof(char) * ft_nlen(n) + 1);
	if (res == NULL)
		return (NULL);
	i = ft_nlen(n);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[i] = '\0';
	i--;
	while (n / 10 != 0)
	{
		res[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	res[i] = 48 + (n % 10);
	return (res);
}
