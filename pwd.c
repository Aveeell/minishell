
#include "minishell.h"

int	pwd_builtin(void)
{
	char	*pwd;
/*
При вызове функции getcwd() с параметром dir, равным NULL, функция getcwd() 
автоматичес­ки размещает буфер с использованием функции malloc() и 
возвращает указатель на этот буфер
*/
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		chdir("..");
		pwd = getcwd(NULL, 0);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}
