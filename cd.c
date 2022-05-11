
#include "minishell.h"

static int	search_directory(t_command *com)
{
	char	*user;
	int		ret;

	if (com->args && (!com->args[0] || !ft_strcmp(com->args[0], "~")))
	{
		user = getenv("USER");
		chdir("/Users/");
		ret = chdir(user);
		if (ret != 0)
			printf("cd: no such file or directory\n");
	}
	else
		ret = chdir(com->args[0]);
	return (ret);
}

int	cd_builtin(t_command *command, t_envlist *lst)
{
	char	*wd;
	int		ret;

	ret = search_directory(command);
	wd = getcwd(NULL, 0);
	if (ret != 0)
	{
		printf("cd: no such file or directory\n");
		return (1);
	}
	else
	{
		free(*(command->args));
		*(command->args) = ft_strjoin("PWD=", wd);
		*(command->args + 1) = NULL;
		export_builtin(lst, command);
	}
	free(wd);
	return (0);
}
