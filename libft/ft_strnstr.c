/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:41:12 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 18:08:27 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *substr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!substr[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && substr[j] && \
				n > (i + j) && str[i + j] == substr[j])
			j++;
		if (!substr[j])
			return ((char *)&str[i]);
		i++;
	}
	return ((void *)0);
}
