/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:52 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 11:51:30 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(!src && !dest))
	{
		while (i < size && size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
