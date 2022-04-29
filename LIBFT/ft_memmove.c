/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:07:40 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/25 18:20:23 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrsrc;
	char	*ptrdst;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	ptrsrc = (char *)src;
	ptrdst = (char *)dst;
	if (src < dst)
	{
		while (len-- > 0)
		{
			*(ptrdst + len) = *(ptrsrc + len);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(ptrdst + i) = *(ptrsrc + i);
			i++;
		}
	}
	return (ptrdst);
}
