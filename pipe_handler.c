
#include "minishell.h"

void	pipe_close(t_command *tmp, int fd0, int fd1)
{
	if (tmp->next)
	{
		dup2(fd0, 0);
		close(fd0);
		close(fd1);
	}
}

void	std_out_close(int save_stdout)
{
	close(0);
	dup2(save_stdout, 0);
	close(save_stdout);
}

void	pipe_utils(t_command *tmp, t_envlist *lst)
{
	int	pid;
	int	fd[2];

	if (tmp->next) // если есть следующая команда, то открываем пайп
		pipe(fd);
	pid = fork();  // запускаем дочерний процесс
	if (pid < 0)
		perror("error\n");
	if (pid == 0) // если это дочерний процесс
	{
		if (tmp->next)		// если есть следующая команда
		{
			close(1); 		// то закрываем запись в стандартный вывод
			dup2(fd[1], 1); // int dup2(int oldfd, int newfd) - перенаправляем вывод из пайпа в стандартный вывод
			close(fd[1]);	// закрываем чтение из пайпа
			close(fd[0]);	// закрываем запись в пайп
		}
		redirection_handler(tmp, lst); // обрабатываем редиректы
		execve_builtin_binary(tmp, lst); // запуск программы
		exit(0);
	}
	close(0);
	pipe_close(tmp, fd[0], fd[1]);
}

void	status_handler(t_command *tmp)
{
	int			exits;

	while (tmp)
	{
		wait(&exits);
		if (WIFSIGNALED(exits))
		{
			if (WTERMSIG(exits) != 13)
				g_variable.g_exites = 128 + WTERMSIG(exits);
			if (WTERMSIG(exits) == SIGQUIT)
				printf(" Quit\n");
		}
		else
			g_variable.g_exites = WEXITSTATUS(exits);
		tmp = tmp->next;
	}
}

void	pipe_handler(t_command *command, t_envlist *lst) 
//t_command *command - структура с данными о команде, t_envlist *lst - односвязный список переменных окружения)
{
	int			save_stdout;
	t_command	*tmp;

	save_stdout = dup(0); //int dup(int oldfd) - duplicate a file descriptor, save_stdout = input from terminal
	tmp = command; // копируем ссылку на структуру комманд
	while (tmp)
	{
		pipe_utils(tmp, lst); // fork and execute command
		tmp = tmp->next;	  // move to next command
	}
	tmp = command;
	status_handler(tmp);
	std_out_close(save_stdout);
}
