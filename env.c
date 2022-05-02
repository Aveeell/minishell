
#include "minishell.h"

int	export_printer(t_envlist *lst)
{
	if (!lst)
		return (1);
	while (lst != NULL) //печатаем export
	{
		printf("declare -x %s=\"%s\"\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return (0);
}

int	env_builtin(t_envlist *lst)
{
	if (!lst)
		return (1);
	while (lst != NULL) //просто печатаем  env
	{
		printf("%s=%s\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return (0);
}

