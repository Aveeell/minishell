
#include "minishell.h"

int	check_quotes(char	*str)
{
	int	count1;
	int	count2;
	int	i;

	count2 = 0;
	count1 = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i]) //считаем кол-во
	{
		if (str[i] == '\"' && count1 % 2 == 0)
			count2++;
		if (str[i] == '\'' && count2 % 2 == 0)
			count1++;
		i++;
	}
	if (count1 % 2 != 0 || count2 % 2 != 0) //нечетное => ошибка
	{
		printf("Error: expected \" or '\n");
		return (0);
	}
	return (1);
}
