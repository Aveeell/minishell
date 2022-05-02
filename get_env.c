
#include "minishell.h"

static char	*finder(char *find, t_envlist *lst)
{
	if (!ft_strcmp(find, "?"))
		return (ft_itoa(g_variable.g_exites));
	while (lst)
	{
		if (!ft_strcmp(find, lst->var_name))
		{
			free(find);
			return (ft_strdup(lst->var_content));
		}
		lst = lst->next;
	}
	return (NULL);
}

static char	*cutter(char *tofind)
{
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = 0;
	/*
	обработка $...
	
	*/
	while (tofind[len] && (ft_isalnum(tofind[len])
			|| tofind[len] == '_' || tofind[len] == '?'))
		len++;
	ret = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		ret[i] = tofind[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*joiner(char *s1, char *s2, t_envlist *lst)
{
	int		len;
	int		i;
	char	*ret;

	i = 0;
	len = 0;
	s2 = finder(s2, lst);
	if (s2 == NULL)
	{
		free (s2);
		return (s1);
	}
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
		ret[i++] = s2[len++];
	ret[i] = 0;
	free(s1);
	free(s2);
	return (ret);
}

static char	*add_char(char *s, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!s)
	{
		ret = malloc(sizeof(char) * 2);
		ret[0] = c;
		ret[1] = 0;
		return (ret);
	}
	ret = malloc(sizeof(char) * ft_strlen(s) + 2);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = 0;
	free(s);
	return (ret);
}

char	*get_env(char *read, t_envlist *lst, int i)
{
	char	*ret;
	int		count1;
	int		count2;
	char	*tmp;

	count2 = 0;
	count1 = 0;
	ret = NULL;
	while (read[i])
	{
		if (read[i] == '\'' && count2 % 2 == 0) //считаем кол-во кавычек
			count1 ++;
		if (read[i] == '\"' && count1 % 2 == 0)
			count2 ++;
		if (read[i] == '$' && count1 % 2 == 0) //если встречаем знак доллара
		{
			tmp = cutter(&read[++i]); //выбираем именно $... 
			i += ft_strlen(tmp);
			ret = joiner(ret, tmp, lst); //соединяем в единую строку возвращаемое значение
		}
		else
			ret = add_char(ret, read[i++]); //собираем нашу команду посимвольно
	}
	free(read);
	return (ret);
}
