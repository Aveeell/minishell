
#include "minishell.h"

char	**linked_double(t_envlist *lst)
{
	int			len;
	t_envlist	*tmp;
	char		**buff;

	if (!lst)
		return (NULL);
	len = 0;
	tmp = lst;
	while (tmp)
	{
		len++; //определяем длину списка с переменными окружения
		tmp = tmp -> next; 
	}
	buff = (char **) malloc ((len + 1) * sizeof(char *)); //маллочим память под двумерный массив
	len = 0;
	while (lst)
	{
		buff[len++] = lst -> stock; // строка в формате "перем. окружения = значение"
		lst = lst -> next;
	}
	buff[len] = NULL;
	return (buff);
}

char	*exeve_handler(t_command *command, t_envlist *lst)
{
	char	**buff;
	int		pid;
	int		exit_status;
	int		i;

	i = 0;
	buff = linked_double(lst); //buff = массив строк в формате "перем. окружения = значение"
	pid = fork(); // запускаем дочерний процесс для запуска бинарника
	if (pid == 0)
		execve(command -> program, command -> execve, buff); 
		//char	*program - команда; char **execve - ??; buff - двумерный массив переменных окружения
	wait(&exit_status); // pid_t wait(int *status);
	if (WIFSIGNALED(exit_status)) //возвращает истинное значение, если дочерний процесс завершился из-за необработанного сигнала
	{
		if (WTERMSIG(exit_status) != 13) //возвращает номер сигнала, который привел к завершению дочернего процесса. 
								   //Этот макрос можно использовать, только если WIFSIGNALED вернул ненулевое значение.
								   //13 - SIGPIPE - Terminate - Write on a pipe with no one to read it
			g_variable.g_exites = 128 + WTERMSIG(exit_status);
		if (WTERMSIG(exit_status) == SIGQUIT)
			printf(" Quit\n");
	}
	else
		g_variable.g_exites = WEXITSTATUS(exit_status); 
		// WEXITSTATUS(status) возвращает восемь младших битов значения, которое вернул завершившийся дочерний процесс. 
		// Эти биты могли быть установлены в аргументе функции exit() или в аргументе оператора return функции main(). 
		// Этот макрос можно использовать, только если WIFEXITED вернул ненулевое значение. (!!!!!)
	return (free(buff), NULL);
}
