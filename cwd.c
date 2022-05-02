
#include "minishell.h"

int	cwd_builtin(void)
{
	char	*cwd;
/*
При вызове функции getcwd() с параметром dir, равным NULL, функция getcwd() 
автоматичес­ки размещает буфер с использованием функции malloc() и 
возвращает указатель на этот буфер
*/
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		chdir("..");
		cwd = getcwd(NULL, 0);
	}
	ft_putendl_fd(cwd, STDOUT_FILENO);
	free(cwd);
	return (0);
}
