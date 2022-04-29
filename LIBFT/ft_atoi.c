/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:00:59 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/26 17:14:36 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long long	nb;

	neg = 1;
	i = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
		neg = -1;
	if ((str[i] == '+') || (str[i] == '-') || str[i] == '0')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9') && (str[i] != '\0'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb > 9223372036854775807ULL)
	{
		if (neg == 1)
			return (-1);
		return (0);
	}
	return (neg * (int)nb);
}
