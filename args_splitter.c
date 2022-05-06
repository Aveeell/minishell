
#include "minishell.h"

static int	get_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '\"')
		while (str[++i] != '\"')
			len++;
	else if (str[i] == '\'')
		while (str[++i] != '\'')
			len++;
	else if (ft_strchr("|><", str[i]))
	{
		len = 1;
		if (str[i] == str[i + 1])
			len ++;
	}
	else
		while (str[i] && !ft_strchr(WHITE_SPACES, str[i])
			&& !ft_strchr("|><", str[i]) && !ft_strchr("\"'", str[i]))
			{
				i++;
				len++; //инкремент i ОЧЕНЬ ТУПОЙ БЛЯ
			}
	return (len);
}

static char	*red_as_arg(char *str)
{
	char	*ret;
	char	*tmp;
	char	*joined;
	char	ch;
	int		len;

	len = 0;
	ret = malloc(sizeof(char) * 2);
	ret[0] = 7; //звенит звоночек, если редирект в кавычках, можно выпилить
	ret[1] = '\0';
	ch = str[len++];
	while (str[len] != ch)
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	ft_strlcpy(tmp, str + 1, len);
	tmp[len] = '\0';
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
	int		is;

	len = get_len(str); //получем длину строки без кавычек, проблеов, редиректов
	i = 0;
	is = 0;
	ret = malloc(sizeof(char) * len + 1);
	if (str[i] == '\'' || str[i] == '\"') //если видим кавычки, перекидываем флаг
		is = 1;
	if (is && ft_strchr("|><", str[i + 1])) //есди редирект в кавычках, то читаем как символ
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

char	**args_splitter(char **ret, char *str)
//ret = NULL, str = считанная readline строка, где переменные окружения уже заменены на их значение
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (check_quotes(str) == 0) //возвращает 0, если нечетное количество ' or "
		return (NULL);
	str = ft_strtrim(str, WHITE_SPACES); //режем спереди и сзади пробельные символы
	ret = malloc(sizeof(char *) * (count_words(str)) + 1); //маллочим память
	while (str[i])
	{
		ret[j] = trimmer(str + i); //убираем все кавычки редиректы и прочее
		if (str[i] == '\'' || str[i] == '\"')
			i += 2;
		i += ft_strlen(ret[j]);
		while ((str[i] && !is_redir(ret[j]) && !ft_strchr(DELIMS, str[i])) ||
			j++ < 0) //пока не встретим редиректы, пайпы и пробелы
		{
			tmp = trimmer(str + i); //режем кавычки
			ret[j] = strjoin_free(ret[j], tmp); //соединяем строки и чистим память
			if (str[i] == '\'' || str[i] == '\"')
				i += 2;
			i += ft_strlen(tmp);
		}
		while (str[i] && ft_strchr(WHITE_SPACES, str[i])) //пока пробелы - скипаем
			i++;
	}
	ret[j] = NULL;
	free(str);
	return (ret);
}
