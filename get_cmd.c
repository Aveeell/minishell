
#include "minishell.h"

static char	*path_joiner(char *path, char *cmd)
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
	if (is_builtin(cmd))
		return (ft_strdup(is_builtin(cmd)));
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = getenv("PATH");
	if (!path)
	{
		set_error(cmd);
		return (NULL);
	}
	others = ft_split(path, ':');
	while (others[i])
	{
		path = path_joiner(others[i++], cmd);
		if (access(path, F_OK) != -1)
		{
			free_arr_of_paths(others);
			return (path);
		}
		free(path);
	}
	free_arr_of_paths(others);
	set_error(cmd);
	return (NULL);
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
{
	t_command	*command;
	int			j;

	j = 0;
	command = init_cmd(buff);
	while (buff[++i])
	{
		parser(command, buff, &i, &j);
		if (buff[i] && buff[i][0] == '|' && ++i)
		{
			command->next = get_command(buff, i - 1, i, lst);
			break ;
		}
		if (buff[i] && ft_strchr("|><", buff[i][0]))
			gen_files(command, buff[i], buff[i + 1], &i);
		else if (buff[i] && !command->program)
		{
			command->program = is_in_list(buff[i], NULL, NULL, 0);
			if (command->program == NULL)
				break ;
		}
	}
	redir_and_execve(command, lst, buff, tmp);
	return (command);
}
