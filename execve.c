
#include "minishell.h"

char	**get_execve(char **buff, int i)
{
	int		len;
	char	**execve;
	int		j;

	j = 0;
	len = i;
	while (buff[len] && !ft_strchr("|><", buff[len][0])) //# define REDIRECTIONS ">|<"
		len ++;  // определяем длину char **buff
	if (!buff[len] && i == 0)
		return (buff);
	execve = malloc(sizeof(char *) * (len - i) + 1);
	while (j <= len - i)
		execve[j++] = ft_strdup(buff[i++]); // переприсваиваем строки 
	execve[j] = NULL;
	return (execve);
}

static char	**linked_double(t_envlist *lst)
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
		tmp = tmp->next; 
	}
	buff = malloc(sizeof(char *) * len + 1); //маллочим память под двумерный массив
	len = 0;
	while (lst)
	{
		buff[len++] = lst->stock; // строка в формате "перем. окружения = значение"
		lst = lst->next;
	}
	buff[len] = NULL;
	return (buff);
}

static char	*execve_handler(t_command *command, t_envlist *lst)
{
	char	**buff;
	int		pid;
	int		exit_status;
	int		i;

	i = 0;
	buff = linked_double(lst); //buff = массив строк в формате "перем. окружения = значение"
	pid = fork(); // запускаем дочерний процесс для запуска бинарника
	if (pid == 0)
		execve(command->program, command->execve, buff); 
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
	free(buff);
	return (NULL);
}

void	execve_builtin_binary(t_command *com, t_envlist *lst)
{
	if (!com->program) //запуск билтинов или бинаркников
		return ;
	else if (ft_strchr(com->program, '/') && access(com->program, F_OK) == -1) //задан путь и нет доступа
		printf("%s: file/program not found\n", com->program);
	else if (!ft_strcmp(com->program, "cd"))
		g_variable.g_exites = cd_builtin(com, lst);				//cd
	else if (!ft_strcmp(com->program, "pwd"))
		g_variable.g_exites = pwd_builtin();						//pwd
	else if (!ft_strcmp(com->program, "echo"))
		g_variable.g_exites = echo_builtin(com);				//echo
	else if (!ft_strcmp(com->program, "env"))
		g_variable.g_exites = env_builtin(lst);						//env
	else if (!ft_strcmp(com->program, "export"))
		g_variable.g_exites = export_builtin(lst, com);			//export
	else if (!ft_strcmp(com->program, "unset"))
		g_variable.g_exites = unset_builtin(com, lst);			//unset
	else if (com->program)
		execve_handler(com, lst); //если не билтин, то вызываем бинарник
}
