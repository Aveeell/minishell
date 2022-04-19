/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:54 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 14:44:01 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	const char	*s;
	const char	*ls;
	char		*d;
	char		*ld;

	s = src;
	d = dest;
	if (!(!src && !dest))
	{
		if (d < s)
		{
			while (size--)
				*d++ = *s++;
		}
		else
		{
			ls = s + (size - 1);
			ld = d + (size - 1);
			while (size--)
				*ld-- = *ls--;
		}
	}
	return (dest);
}
