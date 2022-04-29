/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:24:18 by mkoch             #+#    #+#             */
/*   Updated: 2021/11/09 13:41:58 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	ft_word_num(char const *s, char c)
{
	int		i;
	int		word_num;

	if (!s[0])
		return (0);
	i = 0;
	word_num = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && s[i])
			i++;
		if (s[i] != '\0')
			word_num++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (word_num);
}

static void	ft_next_word(char **next_word, int *word_len, char c)
{
	int	i;

	*next_word = *next_word + *word_len;
	*word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*word_len)++;
		i++;
	}
}

static char	**ft_make_res(char	**res, char const *s, char c, int word_num)
{
	int		i;
	char	*next_word;
	int		word_len;

	i = 0;
	next_word = (char *)s;
	word_len = 0;
	while (s[i] && (i < word_num))
	{
		ft_next_word(&next_word, &word_len, c);
		res[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (res[i] == NULL)
			return (ft_free(res));
		ft_strlcpy(res[i], next_word, word_len + 1);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_num;

	if (!s)
		return (NULL);
	word_num = ft_word_num(s, c);
	res = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (res == NULL)
		return (NULL);
	return (ft_make_res(res, s, c, word_num));
}
