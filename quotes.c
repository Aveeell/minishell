
#include "minishell.h"

int	check_quotes(char	*str)
{
	int	count1;
	int	count2;
	int	i;

	count2 = 0;
	count1 = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i]) //считаем кол-во
	{
		if (str[i] == DOUBLE_QUOTE && count1 % 2 == 0)
			count2++;
		if (str[i] == SINGLE_QUOTE && count2 % 2 == 0)
			count1++;
		i++;
	}
	if (count1 % 2 != 0 || count2 % 2 != 0) //нечетное => ошибка
		return (printf("Error:\n	expected \" or '\n"), 0);
	return (1);
}
