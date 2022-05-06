
#include "minishell.h"

int	heredoc(t_command *command, t_envlist *lst)
{
	char	*prompt;
	int		fd[2];

	pipe(fd); //делаем пайп
	while (1)
	{
		prompt = readline("\x1b[34mheredoc > \x1b[37m"); //ждем ввода
		if (!prompt || !ft_strcmp(command->files->file, prompt)) //если ввод пустой или ввод равен command->files->file
			return (free(prompt), close(fd[1]), fd[0]); // return(fd[0])
		ft_putstr_fd(get_env(prompt, lst), fd[1]);
		ft_putstr_fd("\n", fd[1]);
	}
}

static void	right_redirection(t_command *command, int file_out) 
//file_out - файловый дескриптор файла, в который идет вывод
{
	if (!ft_strcmp(command->redirection, ">"))
	{
		file_out = open(command->files->file, O_CREAT | O_RDWR | O_TRUNC, 0666); // проверить возвращаемые значения
		// открываем файл в который будет вестись запись
		dup2(file_out, 1);  // int dup2(int oldfd, int newfd) - заменяем вывод в файл в стандартный вывод
		close(file_out);	// закрываем файл для записи
	}
	else if (!ft_strcmp(command->redirection, ">>"))
	{
		file_out = open(command->files->file, O_CREAT | O_RDWR | O_APPEND, 0666); 	// проверить возвращаемые значения, то же самое, что и выше
		dup2(file_out, 1);
		close(file_out);
	}
}

static void	left_redirection(t_command *command, int file_out)
{
	if (!ft_strcmp(command->redirection, "<"))
	{
		file_out = open(command->files->file, O_RDONLY);
		// открываем файл для чтения
		if (file_out == -1) // если не открылся, выводим ошибку
		{
			printf("%s: No such file or directory\n", command->files->file);
			exit(1);
		}
		dup2(file_out, 0);   // int dup2(int oldfd, int newfd) - заменяем ввод из файла на стандартный ввод
		close(file_out);	 // закрываем файл для чтения
	}
	else if (!ft_strcmp(command->redirection, "<<"))
	{
		dup2(command->heredoc, 0); // int dup2(int oldfd, int newfd) - заменяем ввод из heredoc(?) на стандартный ввод
		close(command->heredoc);	// закрываем heredoc
	}
}

void	redirection_handler(t_command *command, t_envlist *lst)
{
	int	file_out;

	file_out = 0; 
	if (command->files != NULL) // идем по списку файлов при редиректах
	{
		right_redirection(command, file_out); 	// обработка > и >>
		left_redirection(command, file_out);	// обработка < и <<
		command->files = command->files->next;  // переходим на следующий файл
		redirection_handler(command, lst); 		// рекурсия
	}
}
