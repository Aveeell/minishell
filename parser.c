
#include "minishell.h"

void	parser(t_command *command, char **buff, int *i, int *j)
{
	if (buff[*i] && *i == 1 && !ft_strcmp(buff[*i], "-n") 
		&& !ft_strcmp("echo", command->program)) //проверяем наличие аргументов и флагов
		command->options = ft_strdup(buff[*i]); //копируем флаг
	else if (buff[*i] && *i > 0 && !ft_strchr("|><", buff[*i][0]))
	{
		command->args[*j] = ft_strdup(buff[*i]); //копируем аргументы
		*j += 1;
		command->args[*j] = NULL;
	}
}
