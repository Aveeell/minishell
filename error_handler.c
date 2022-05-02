
#include "minishell.h"

void	set_error(char *s) //сообщение об ошибке
{
	printf("\x1b[31m%s: command not found\n\x1b[37m", s);
	g_variable.g_exites = 1;
	return ;
}

void	put_error(char **buff, int x)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	x = ft_strlen("  Minishell $ ");
	while (buff[i])
		len += ft_strlen(buff[i++]) + 1;
	i = x;
	while (x--)
		write(1, " ", 1);
	while (len--)
		write(1, "\x1b[32m~", ft_strlen("\x1b[32m~"));
	write(1, "\n", 1);
	while (i--)
		write(1, " ", 1);
	printf("\x1b[31mInvalid syntax:\n\x1b[37m\n");
}

bool	is_redirection(char *str)
{
	return (!ft_strcmp(str, RED_APPEND) || !ft_strcmp(str, ">") || \
		!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || \
		!ft_strcmp(str, ">>") || \
		!ft_strcmp(str, "<<") || !ft_strcmp(str, "||"));
}

bool	error_checker(char **buff)
{
	int	i;

	i = 0;
	if (buff == NULL)
		return (false);
	if (buff[0] && !ft_strcmp(buff[0], "|"))
		return (put_error(buff, 0), false);
	while (buff[i])
	{
		if (!ft_strcmp(buff[i], "&&") || !ft_strcmp(buff[i], "||")) //заглушка, чтобы не обрабатывались как пайпы
			return (printf("\x1b[31mError:\n\tCompile bonus \
part to use \"%s\"\x1b[37m\n\n", buff[i]), false);
		if (is_redirection(buff[i]) && buff[i + 1] == NULL)
			return (put_error(buff, 0), false);
		if (is_redirection(buff[i]) && is_redirection(buff[i + 1]))
			if (!(buff[i][0] == '|' && (buff[i + 1][0] == '>'
				|| buff[i + 1][0] == '<')))
				return (put_error(buff, 0), false);
		i++;
	}
	return (true);
}
