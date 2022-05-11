
#include "minishell.h"

void	free_arr_of_paths(char **others)
{
	int	i;

	i = 0;
	while (others[i])
		free(others[i++]);
	free(others);
}

int	print_env_with_declare(t_envlist *lst)
{
	if (!lst)
		return (1);
	while (lst != NULL)
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
	while (lst != NULL)
	{
		printf("%s=%s\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return (0);
}
