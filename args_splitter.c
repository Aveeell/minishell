/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:18:10 by majjig            #+#    #+#             */
/*   Updated: 2022/04/28 14:11:47 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*trimmer(char *str);

int	get_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == DOUBLE_QUOTE)
		while (str[++i] != DOUBLE_QUOTE)
			len++;
	else if (str[i] == SINGLE_QUOTE)
		while (str[++i] != SINGLE_QUOTE)
			len++;
	else if (ft_strchr(REDIRECTIONS, str[i]))
	{
		len = 1;
		if (str[i] == str[i + 1])
			len ++;
	}
	else
		while (str[i] && !ft_strchr(WHITE_SPACES, str[i])
			&& !ft_strchr(REDIRECTIONS, str[i]) && !ft_strchr("\"'", str[i]))
			len += (i++ *0) + 1;
	return (len);
}

char	*red_as_arg(char *red)
{
	char	*ret;
	char	*tmp;
	char	*joined;
	char	ch;
	int		len;

	len = 0;
	ret = malloc (2 * sizeof(char));
	ret[0] = 7; //звенит звоночек, если редирект в кавычках, можно выпилить
	ret[1] = 0;
	ch = red[len++];
	while (red[len] != ch)
		len++;
	tmp = (char *) malloc (len);
	ft_strlcpy(tmp, red + 1, len);
	tmp[len] = 0;
	joined = ft_strjoin(ret, tmp);
	free(ret);
	free(tmp);
	return (joined);
}

static char	*trimmer(char *str)
{
	int		i;
	int		len;
	char	*ret;
	bool	is;

	len = get_len(str); //получем длину строки без кавычек, проблеов, редиректов
	i = 0;
	is = false;
	ret = (char *) malloc (len + 1);
	if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE) //если видим кавычки, перекидываем флаг
		is = true;
	if (is && ft_strchr(REDIRECTIONS, str[i + 1])) //есди редирект в кавычках, то читаем как символ
		return (red_as_arg(str));
	while (i < len)
	{
		while (str[i + 1] == -1)
			str++;
		if (is == false)
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
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i += 2;
		i += ft_strlen(tmp);
		while (str[i] && ft_strchr(WHITE_SPACES, str[i]))
			i++;
		free(tmp);
	}
	return (words);
}

char	**args_splitter(char **ret, char *str, int i, int j)
{
	char	*tmp;

	if (check_quotes(str) == 0) //проверяем кавычки
		return (NULL);
	str = ft_strtrim(str, WHITE_SPACES); //режем спереди и сзади пробельные символы
	ret = (char **) malloc ((count_words(str) + 1) * sizeof(char *)); //маллочим память
	while (str[i])
	{
		ret[j] = trimmer(str + i); //убираем все кавычки редиректы и прочее
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i += 2;
		i += ft_strlen(ret[j]);
		while ((str[i] && !is_redirection(ret[j])
				&& !ft_strchr(" \t\v\r\f>|<", str[i])) || j++ < 0) //пока не встретим редиректы, пайпы и пробелы
		{
			tmp = trimmer(str + i); //режем кавычки
			ret[j] = strjoin_free(ret[j], tmp); //соединяем строки и чистим память
			if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
				i += 2;
			i += ft_strlen(tmp);
		}
		while (str[i] && ft_strchr(WHITE_SPACES, str[i])) //пока пробелы - скипаем
			i++;
	}
	return (ret[j] = NULL, free(str), ret);
}
