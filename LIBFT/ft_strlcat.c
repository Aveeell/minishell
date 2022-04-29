/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:08:09 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/21 14:19:27 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	size;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst < dstsize)
		size = len_dst + len_src;
	else
		size = len_src + dstsize;
	if ((dstsize == 0) || (dstsize < len_dst))
		return (size);
	i = 0;
	while (dst[i] && (i < dstsize))
		i++;
	while (i < (dstsize - 1) && (src[i - len_dst] != '\0'))
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return (size);
}
