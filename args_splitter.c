/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:18:15 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:18:20 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '\"')
		len = get_len_in_quotes(str, '\"');
	else if (str[i] == '\'')
		len = get_len_in_quotes(str, '\'');
	else if (ft_strchr("|><", str[i]))
	{
		len = 1;
		if (str[i] == str[i + 1])
			len++;
	}
	else
	{
		while (str[i] && !ft_strchr(WHITE_SPACES, str[i]) && \
		!ft_strchr("|><", str[i]) && !ft_strchr("\"'", str[i]))
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*trimmer(char *str)
{
	int		i;
	int		len;
	char	*ret;
	int		is;

	len = get_len(str);
	i = 0;
	is = 0;
	ret = malloc(sizeof(char) * len + 1);
	if (str[i] == '\'' || str[i] == '\"')
		is = 1;
	if (is && ft_strchr("|><", str[i + 1]))
		return (red_as_arg(str));
	while (i < len)
	{
		while (str[i + 1] == -1)
			str++;
		if (!is)
			ret[i] = str[i];
		else if (str[i + 1] != str[0])
			ret[i] = str[i + 1];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static int	count_words(char *str)
{
	int		words;
	int		i;
	char	*tmp;

	words = 0;
	i = 0;
	while (str[i])
	{
		words++;
		tmp = trimmer(str + i);
		if (str[i] == '\'' || str[i] == '\"')
			i += 2;
		i += ft_strlen(tmp);
		while (str[i] && ft_strchr(WHITE_SPACES, str[i]))
			i++;
		free(tmp);
	}
	return (words);
}

static char	**while_in_split(char *str, char **ret, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		ret[j] = trimmer(str + i);
		if (str[i] == '\'' || str[i] == '\"')
			i += 2;
		i += ft_strlen(ret[j]);
		while ((str[i] && !is_redir(ret[j]) && !ft_strchr(DELIMS, str[i])))
		{
			j++;
			tmp = trimmer(str + i);
			ret[j] = strjoin_free(ret[j], tmp);
			if (str[i] == '\'' || str[i] == '\"')
				i += 2;
			i += ft_strlen(tmp);
		}
		j++;
		while (str[i] && ft_strchr(WHITE_SPACES, str[i]))
			i++;
	}
	return (ret);
}

char	**args_splitter(char **ret, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (check_quotes(str) == 0)
		return (NULL);
	str = ft_strtrim(str, WHITE_SPACES);
	ret = malloc(sizeof(char *) * (count_words(str)) + 1);
	if (!ret)
		return (NULL);
	ret = while_in_split(str, ret, tmp);
	ret[count_words(str)] = NULL;
	free(str);
	return (ret);
}
