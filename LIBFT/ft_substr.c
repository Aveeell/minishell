/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:26:42 by mkoch             #+#    #+#             */
/*   Updated: 2021/11/09 15:15:30 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s || (start >= ft_strlen(s)))
	{
		res = (char *)malloc (sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if ((ft_strlen(s) - start) < len)
		len = (ft_strlen(s) - start);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)len)
	{
		res[i] = s[start + i];
		if (s[start + i] == '\0')
			return (res);
	}
	res[i] = '\0';
	return (res);
}
