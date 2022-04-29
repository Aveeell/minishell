
#include "minishell.h"

void	__exec__(t_command *command, t_envlist *lst)
{
	if (command -> program == NULL) //запуск билтинов или бинаркников
		return ;
	else if (ft_strchr(command -> program, '/') && \
		access(command -> program, F_OK) == -1) //задан путь и нет доступа
		printf("%s: file/program not found\n", command -> program);
	else if (ft_strcmp(command -> program, _CD) == 0)
		g_variable.g_exites = __cd__(command, lst);				//cd
	else if (ft_strcmp(command -> program, _PWD) == 0)
		g_variable.g_exites = __cwd__();						//pwd
	else if (ft_strcmp(command -> program, _ECHO) == 0)
		g_variable.g_exites = __echo(command);					//echo
	else if (ft_strcmp(command -> program, _ENV) == 0)
		g_variable.g_exites = __env(lst);						//env
	else if (ft_strcmp(command -> program, _EXPORT) == 0)
		g_variable.g_exites = __export(lst, command);			//export
	else if (ft_strcmp(command -> program, _UNSET) == 0)
		g_variable.g_exites = __unset(command, lst);			//unset
	else if (command -> program)
		execve_handler(command, lst); //если не билтин, то вызываем бинарник
}
