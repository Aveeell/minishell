
#include "minishell.h"

static char	*ft_alloc_fill(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c) //до разделителя
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*ft_alloc_fill_2(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i]) //до конца строки
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split_smart(char const *s, char c)
{
	int		j;
	char	**str;

// делит строку на три

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * 3);
	j = 0;
	while (*s)
	{
		if (*s != c) //если не разделитель || копируем название переменной
		{
			str[j++] = ft_alloc_fill((char *) s, c); //копируем, пока не встретим разделитель
			while (*(s + 1) && *(s + 1) != c) // скпипаем до разделителя
				s++;
		}
		else // копируем значение переменной
		{
			str[j++] = ft_alloc_fill_2((char *)++s, c); //копируем остаток строки
			break ;
		}
		s++;
	}
	str[j] = NULL;
	return (str);
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
