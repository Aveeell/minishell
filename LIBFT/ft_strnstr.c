/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:06:36 by mkoch             #+#    #+#             */
/*   Updated: 2021/10/19 17:54:26 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while ((*(haystack + i) != '\0') && (i < len))
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			while ((*(haystack + i + j) == *(needle + j)) && (i + j < len))
			{
				j++;
				if (*(needle + j) == '\0')
					return ((char *)(haystack + i));
			}
		}
		i++;
	}
	return (0);
}
