/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:07:29 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/21 12:32:38 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrsrc;
	char	*ptrdst;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	ptrsrc = (char *)src;
	ptrdst = (char *)dst;
	while (i < n)
	{
		*(ptrdst + i) = *(ptrsrc + i);
		i++;
	}
	return (dst);
}
