/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:33:20 by jerrok            #+#    #+#             */
/*   Updated: 2021/11/09 15:45:06 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return ((void *)0);
	if (start < ft_strlen(s))
	{
		while (len > 0 && s[start] != '\0')
		{
			substr[j++] = s[start++];
			len--;
		}
	}
	substr[j] = '\0';
	return (substr);
}