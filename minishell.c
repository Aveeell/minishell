/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:14:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/04/29 12:27:28 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*get_next_cmd(t_envlist *lst)
{
	char		*read;
	t_command	*command;
	char		**buff;
	int			i;

	i = 0;
	if (g_variable.g_exites != 0) //если флаг выхода не 1, то зеленая стрелочка
		read = readline(MINISHELL_RED);
	else //иначе красная
		read = readline(MINISHELL_GREEN);
	if (!read) //если ctrl+d, то выходим
	{
		printf("exit");
		exit(1);
	}
	if (ft_strlen(read) > 0) //если введена команда, то добавляем в историю
		add_history(read);
	read = __get_env(read, lst, 0); //получаем окружение для выполнения команды
	buff = args_splitter(NULL, read, 0, 0); //сплитим аргументы команды //// readline that was splitted
	if (error_checker(buff) == false) //проверяем на ошибки (отсутствие команды после пайпа, к примеру)
		return (NULL);
	if (!buff || buff[0] == NULL)
		return (NULL);
	return (free(read), command = get_cammand(buff, -1, 0, lst), command); 
	//чистим ридлайн и получаем структуру с командами и аргументами
}

void	free_cmd(t_command *command)
{
	int	i;

	i = 0;
	if (!command)
		return ;
	free(command -> program);
	while (command -> args && command -> args[i])
		free(command -> args[i++]);
	i = 0;
	while (command -> execve[i])
		free(command -> execve[i++]);
	while (command -> files)
	{
		free(command -> files -> file);
		free(command -> files);
		command -> files = command -> files -> next;
	}
	free(command -> execve);
	free(command -> args);
	free(command -> options);
	free(command -> redirection);
	free(command);
	command = command->next;
	free_cmd(command);
}

void	command_roots(t_command *command, t_envlist *lst)
{
	g_variable.is_running = 1; //флаг работы команды
	if (command->next || command->redirection) //если есть редиректы или пайпы
		pipe_handler(command, lst); //ловим пайпы
	else
		__exec__(command, lst); //иначе просто запускаем
	g_variable.is_running = 0; //флаг в ноль
}

void	__exit(t_command *command)
{
	if (command && command -> program != NULL \
		&& ft_strcmp(command -> program, "exit") == 0)
	{
		write(1, "exit\n", 5);
		free_cmd(command);
		exit(1);
	}
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_command	*command;
	t_envlist	*lst;

	av = NULL; //(void)av/ac
	lst = __env__init(envp); //копируем окружение в свой терминал
	signal_handler(); //переопределяем сигналы
	while (true)
	{
		ac = 0;
		command = get_next_cmd(lst); //получаем команду
		__exit(command);
		if (command) //если команда введена 
			command_roots(command, lst);
		free_cmd(command); //зачистка памяти
		command = NULL;
	}
	rl_clear_history();
	return (0);
}
