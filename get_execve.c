
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
