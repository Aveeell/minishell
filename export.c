
#include "minishell.h"

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char	**export_spliter(t_command *command, int i)
{
	char	**out;
	char	*tmp;

	tmp = NULL;
	out = NULL;
	if (!command->args[i])
		return (out);
	if (!ft_strchr(command->args[i], '+'))
	{
		command->is_append = 0;
		out = ft_split_smart(command->args[i], '='); //делим строку на название и значение по '='
		if (!ft_isalpha(out[0][0])) //если начинается с цифры
		{
			printf("export: `%s': invalid param name\n", out[0]);
			return (NULL); //бросаем ошибку
		}
		else if (!ft_strcmp(command->args[i], out[0]))
			return (NULL);
	}
	else if (ft_strchr(command->args[i], '+') != NULL)
	{
		command->is_append = 1;
		out = ft_split_smart(command->args[i], '+');
		tmp = out[1];
		out[1] = ft_strdup(ft_strchr(out[1], '=') + 1);
		free(tmp);
	}
	return (out);
}

static void	add_var_to_env(char **tab, t_envlist *lst, t_command *command)
{
	t_envlist	*tmp;
	char		*to_free;

	tmp = lst;
	to_free = NULL;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->var_name, tab[0]) && !command->is_append) 
		{
			free(tmp->var_content);
			tmp->var_content = ft_strdup(tab[1]);
			return ;
		}
		else if (!ft_strcmp(tmp->var_name, tab[0]) && command->is_append == 1)
		{
			to_free = tmp->var_content;
			tmp->var_content = ft_strjoin(tmp->var_content, tab[1]);
			free(to_free);
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&lst, ft_lstnew_2(tab)); //добавляем в конец списка нашу переменную
}

int	export_builtin(t_envlist *lst, t_command *command)
{
	char	**tab;
	int		tablen;
	int		i;

	i = 0;
	tablen = 0;
	if (!command->args || !command->args[0]) //если аргументы не заданы, выводим declare -x
		return (export_printer(lst));
	tablen = ft_tab_len(command->args); //считаем кол-во строк
	while (tablen != 0)
	{
		tab = export_spliter(command, i); //сплитим аргументы экспорта
		if (!tab)
			return (1);
		add_var_to_env(tab, lst, command); //добавляем в env нашу строку
		tablen--;
		i++;
		free(tab[0]);
		free(tab[1]);
		free(tab);
	}
	return (0);
}
