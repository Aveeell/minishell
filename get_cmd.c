
#include "minishell.h"

void	set_error(char *s) //сообщение об ошибке
{
	printf("\x1b[31m%s: command not found\n\x1b[37m", s);
	g_variable.g_exites = 1;
	return ;
}

char	*path_joiner(char *path, char *cmd) //соединятель пути к бинарнику
{
	char	*ret;
	char	*slash;

	slash = ft_strjoin(path, "/");
	ret = ft_strjoin(slash, cmd);
	free(slash);
	return (ret);
}

char	*is_in_list(char *cmd, char **others, char *path, int i)
{
	if (is_builtin(cmd)) //является ли билтином
		return (ft_strdup(is_builtin(cmd)));
	if (ft_strchr(cmd, '/')) //если указан путь
		return (ft_strdup(cmd));
	path = getenv("PATH"); //получаем path
	if (path == NULL)
		return (set_error(cmd), NULL); //бросаем ошибку
	others = ft_split(path, ':'); //сплитим по :
	while (others[i]) //пока есть элементы
	{
		path = path_joiner(others[i++], cmd); //дополняем путь
		if (access(path, F_OK) != -1) //проверяем доступ
		{
			i = 0;
			while (others[i])
				free(others[i++]);
			free(others);
			return (path);
		}
		free(path);
	}
	i = 0;
	while (others[i]) //все зачищаем
		free(others[i++]);
	return (free(others), set_error(cmd), NULL);
}
//------------------------------------------------------------------------------
// char	*args_joiner(char *args, char *new) //нахер не нужная функция, лол
// { //можно просто снести, наверное заготовка к бонусам
// 	char	*joined;
// 	char	*space;

// 	if (args == NULL)
// 		return (ft_strdup(new));
// 	space = ft_strjoin(args, " ");
// 	joined = ft_strjoin(space, new);
// 	free(args);
// 	free(space);
// 	return (joined);
// }
//------------------------------------------------------------------------------
t_command	*get_cammand(char **buff, int i, int tmp, t_envlist *lst)
// buff is a readline that was splitted by pipes, redirects, WHITE_SPACES, single and double quotes, etc..

{
	t_command	*command;
	int			ai;

	ai = 0;
	command = init_cmd(buff); //инициализируем структуру // // set fields in command structure to NULL and mallocs memory
	while (buff[++i])
	{
		parser(command, buff, &i, &ai); //парсим входящую структуру, проверяем команды и редиректы
		if (buff[i] && buff[i][0] == RED_PIPE && ++i)
		{
			command -> next = get_cammand(buff, i - 1, i, lst); //если пайп, то записываем следующую команду
			break ;
		}
		if (buff[i] && ft_strchr(REDIRECTIONS, buff[i][0])) //есди редиректы, то генерим файлы //// REDIRECTIONS = ">|<"
			gen_files(command, buff[i], buff[i + 1], &i);
		else if (buff[i] && !command -> program)
		{
			command -> program = is_in_list(buff[i], NULL, NULL, 0); //проверяем наличие проги
			if (command -> program == NULL)
				break ;
		}
	}
	if (!ft_strcmp(command->redirection, "<<")) //если есть <<, то запускаем heredoc
		command->heredoc = heredoc(command, lst); //запускаем heredoc 
	return (command -> execve = get_execve(buff, tmp), command); //возвращаем запускаемую команду
}
