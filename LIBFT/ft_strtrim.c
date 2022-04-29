/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:23:26 by mkoch             #+#    #+#             */
/*   Updated: 2021/11/09 14:53:27 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isequal(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	i = 0;
	while ((ft_isequal(s1[i], (char *)set)) && (s1[i]))
		i++;
	end = ft_strlen(s1) - 1;
	while ((ft_isequal(s1[end], (char *)set)) && (end > i))
		end--;
	end = end + 1;
	if (end <= i)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = ft_substr(s1, i, (end - i));
	return (res);
}
