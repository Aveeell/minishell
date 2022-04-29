/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:08:01 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/25 20:31:31 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	cc;

	ptr = (unsigned char *)s;
	cc = (unsigned char )c;
	while (*ptr != '\0')
	{
		if (*ptr == cc)
			return ((char *)ptr);
		ptr++;
	}
	if (cc == '\0')
		return ((char *)ptr);
	return (0);
}
