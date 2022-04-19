/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:45:19 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/26 12:23:49 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	while (i < size)
	{
		if (s[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}		
	return ((void *)0);
}
