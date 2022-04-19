/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:59 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 10:37:40 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int n)
{
	unsigned char	*s;
	int			i;

	i = 0;
	s = (unsigned char *)str;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)n)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)n)
		return ((char *)&s[i]);
	return ((void *)0);
}
