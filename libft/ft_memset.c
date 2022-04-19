/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:57 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/26 12:23:55 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(char *str, char symb, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = symb;
		i++;
	}
	return (str);
}
