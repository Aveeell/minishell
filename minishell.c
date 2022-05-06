
#include "minishell.h"

static t_command	*get_next_cmd(t_envlist *lst)
{
	char		*read;
	t_command	*command;
	char		**buff;
	int			i;

	i = 0;
	read = readline("MINISHELL > ");
	if (!read) //если ctrl+d, то выходим
	{
		printf("exit");
		exit(1);
	}
	if (ft_strlen(read) > 0) //если введена команда, то добавляем в историю // зачем if, если раньше был if (!read)?
		add_history(read);
	read = get_env(read, lst); //получаем считанную readline строку, где переменные окружения уже заменены на их значение
	buff = args_splitter(NULL, read); //сплитим аргументы команды //// buff = readline that was splitted
	if (!error_checker(buff)) //проверяем на ошибки (отсутствие команды после пайпа, к примеру)
		return (NULL);
	if (!buff || !buff[0])
		return (NULL);
	free(read);
	command = get_command(buff, -1, 0, lst);
	return (command);
	//чистим ридлайн и получаем структуру с командами и аргументами
}

static void	free_cmd(t_command *command)
{
	int	i;

	i = 0;
	if (!command)
		return ;
	free(command->program);
	while (command->args && command->args[i])
		free(command->args[i++]);
	i = 0;
	while (command->execve[i])
		free(command->execve[i++]);
	while (command->files)
	{
		free(command->files->file);
		free(command->files);
		command->files = command->files->next;
	}
	free(command->execve);
	free(command->args);
	free(command->options);
	free(command->redirection);
	free(command);
	command = command->next;
	free_cmd(command);
}

static void	command_roots(t_command *command, t_envlist *lst)
{
	g_variable.is_running = 1; //флаг работы команды
	if (command->next || command->redirection) //если есть редиректы или пайпы
		pipe_handler(command, lst); //ловим пайпы
	else
		execve_builtin_binary(command, lst); //иначе просто запускаем
	g_variable.is_running = 0; //флаг в ноль
}

static void	ft_exit(t_command *command)
{
	if (command && command->program && !ft_strcmp(command->program, "exit"))
	{
		write(1, "exit\n", 5);
		free_cmd(command);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_command	*command;
	t_envlist	*lst;

	(void)argc;
	(void)argv;
	lst = init_env_list(envp); //копируем окружение в свой терминал
	signal_handler(); //переопределяем сигналы
	while (1)
	{
		command = get_next_cmd(lst); //получаем команду
		ft_exit(command);
		if (command) //если команда введена 
			command_roots(command, lst);
		free_cmd(command); //зачистка памяти
		command = NULL;
	}
	rl_clear_history(); //Clear the history list by deleting all of the entries
	return (0);
}
