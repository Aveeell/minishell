
#include "minishell.h"

static char	*path_joiner(char *path, char *cmd) //соединятель пути к бинарнику
{
	char	*ret;
	char	*slash;

	slash = ft_strjoin(path, "/");
	ret = ft_strjoin(slash, cmd);
	free(slash);
	return (ret);
}

static char	*is_in_list(char *cmd, char **others, char *path, int i)
{
	if (is_builtin(cmd)) //является ли билтином
		return (ft_strdup(is_builtin(cmd)));
	if (ft_strchr(cmd, '/')) //если указан путь
		return (ft_strdup(cmd));
	path = getenv("PATH"); //получаем path
	if (!path)
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

static t_command	*init_cmd(char **buff)
{
	int			len;
	t_command	*command;

	command = NULL;
	if (!buff || buff[0] == NULL)
		return (NULL);
	len = 0;
	while (buff[len])
		len++;
	command = malloc(sizeof(t_command));
	command->options = NULL;
	command->args = malloc(sizeof(char *) * len + 1);
	command->args[0] = NULL;
	command->program = NULL;
	command->next = NULL;
	command->redirection = NULL;
	command->files = NULL;
	return (command);
}

static void	gen_files(t_command *command, char *red, char *file, int *i)
{
	t_files	*new;
	t_files	*tmp;

	command->redirection = ft_strdup(red);
	*i += 1;
	new = malloc(sizeof(t_files));
	tmp = command->files;
	new->file = file;
	new->next = NULL;
	if (command->files == NULL)
	{
		command->files = new;
		return ;
	}
	while (command->files->next)
		command->files = command->files->next;
	command->files->next = new;
	command->files = tmp;
}

t_command	*get_command(char **buff, int i, int tmp, t_envlist *lst)
// buff is a readline that was splitted by pipes, redirects, WHITE_SPACES, single and double quotes, etc..
{
	t_command	*command;
	int			j;

	j = 0;
	command = init_cmd(buff); //инициализируем структуру // // set fields in command structure to NULL and mallocs memory
	while (buff[++i])
	{
		parser(command, buff, &i, &j); //парсим входящую структуру, проверяем команды и редиректы
		if (buff[i] && buff[i][0] == '|' && ++i)
		{
			command->next = get_command(buff, i - 1, i, lst); //если пайп, то записываем следующую команду
			break ;
		}
		if (buff[i] && ft_strchr("|><", buff[i][0])) //есди редиректы, то генерим файлы //// "|><" = ">|<"
			gen_files(command, buff[i], buff[i + 1], &i);
		else if (buff[i] && !command->program)
		{
			command->program = is_in_list(buff[i], NULL, NULL, 0); //проверяем наличие проги
			if (command->program == NULL)
				break ;
		}
	}
	if (!ft_strcmp(command->redirection, "<<")) //если есть <<, то запускаем heredoc
		command->heredoc = heredoc(command, lst); //запускаем heredoc 
	return (command->execve = get_execve(buff, tmp), command); //возвращаем запускаемую команду
}
