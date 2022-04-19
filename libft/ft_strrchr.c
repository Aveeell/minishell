/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:41:16 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 12:03:29 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int n)
{
	unsigned char	*s;
	size_t			i;

	i = ft_strlen(str);
	s = (unsigned char *)str;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)n)
			return ((char *)&s[i]);
		else if (i == 0)
			return ((void *)0);
		i--;
	}
	return ((void *)0);
}
