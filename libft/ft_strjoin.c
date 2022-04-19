/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:57:39 by jerrok            #+#    #+#             */
/*   Updated: 2021/10/27 11:47:08 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_strs(char const *s1, char const *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2));
}

static char	*ft_join(char *res, char const *s, size_t len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		res[len + i] = s[i];
		i++;
	}
	res[len + i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return ((void *)0);
	res = malloc((sizeof(char) * ft_len_strs(s1, s2)) + 1);
	if (!res)
		return ((void *)0);
	res = ft_join(ft_join(res, s1, 0), s2, ft_strlen(s1));
	return (res);
}
