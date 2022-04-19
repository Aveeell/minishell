/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:41:02 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 11:46:43 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = ft_strlen(dest) + ft_strlen(src);
	if (size < ft_strlen(dest))
		res = size + ft_strlen(src);
	while (dest[j] != '\0' && size > 0)
	{
		j++;
		size--;
	}
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[j + i] = src[i];
			i++;
		}
		dest[j + i] = '\0';
	}
	return (res);
}
