
#include "minishell.h"

char	*is_builtin(char *cmd) //является билтином
{
	int			i;
	static char	*all[] = {"echo", "cd", "pwd", "export", "unset", "env",
		"exit"};

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(all[i], cmd))
			return (all[i]);
		i++;
	}
	return (NULL);
}
