/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:08:34 by mkoch             #+#    #+#             */
/*   Updated: 2021/11/08 17:37:03 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	cc;

	ptr = (unsigned char *)s + ft_strlen(s);
	cc = (unsigned char)c;
	if (cc == '\0')
		return ((char *)ptr);
	while (ptr != (unsigned char *)s)
	{
		if (*ptr == cc)
			return ((char *)ptr);
		ptr--;
	}
	if (*ptr == cc)
		return ((char *)ptr);
	return (0);
}
