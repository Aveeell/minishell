
#include "minishell.h"

int	search_directory(t_command *command)
{
	char	*user;
	int		ret;

	if (command->args && (command -> args[0] == NULL \
		|| ft_strcmp(command -> args[0], "~") == 0)) //если просто cd или ~
	{
		user = getenv("USER"); //получаем имя юзера
		chdir("/Users/");
		ret = chdir(user); //переходим в папку юзера
		if (ret != 0)
			puts("cd: no such file or directory");
	}
	else
		ret = chdir(command -> args[0]); //иначе переходим в указанную папку
	return (ret);
}

int	cd_builtin(t_command *command, t_envlist *lst)
{
	char	*wd;
	int		ret;

	ret = search_directory(command); //ищем нужную папку
	wd = getcwd(NULL, 0); 
	if (ret != 0)
	{
		puts("cd: no such file or directory");
		return (1);
	}
	else //меняем текущую папку в env
	{
		free(*(command->args));
		*(command->args) = ft_strjoin("PWD=", wd);
		*(command->args + 1) = NULL;
		export_builtin(lst, command);
	}
	free(wd);
	return (0);
}
