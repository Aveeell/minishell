
#include "minishell.h"

void	unset_builtin_utils(t_envlist *lst, char *tab)
{
	while (lst != NULL) //бежим по списку
	{
		if (lst->next && !ft_strcmp(lst->next->var_name, tab)) //если совпало
		{
			free(lst->next); //фришим
			lst->next = lst->next->next; //перезаписываем ссылку
			return ;
		}
		lst = lst->next;
	}
}

int	unset_builtin(t_command *commad, t_envlist *lst)
{
	int			tablen;
	int			i;
	t_envlist	*tmp;

	if (!commad->args) //если нет такой переменной
		return (1);
	i = 0;
	tablen = ft_tab_len(commad->args);
	while (i < tablen) //в цикле бежим и анлинкаем
	{
		tmp = lst;
		unset_builtin_utils(tmp, commad->args[i]);
		i++;
	}
	return (0);
}
