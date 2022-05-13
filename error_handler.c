/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:18:41 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:18:44 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_error(char *s)
{
	printf("%s: command not found\n", s);
	g_variable.g_exites = 1;
}

static void	put_error(char **buff, int x)
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
		write(1, "~", ft_strlen("~"));
	write(1, "\n", 1);
	while (i--)
		write(1, " ", 1);
	printf("Invalid syntax\n");
}

int	is_redir(char *str)
{
	return (!ft_strcmp(str, ">>") || !ft_strcmp(str, ">") || \
		!ft_strcmp(str, "|") || !ft_strcmp(str, "||") || \
		!ft_strcmp(str, "<<") || !ft_strcmp(str, "<"));
}

int	error_return(char **buff)
{
	put_error(buff, 0);
	return (0);
}

int	check_error(char **buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	if (buff[0] && !ft_strcmp(buff[0], "|"))
		return (error_return(buff));
	while (buff[i])
	{
		if (!ft_strcmp(buff[i], "&&") || !ft_strcmp(buff[i], "||"))
		{
			printf("project without bonuses\n");
			return (0);
		}
		if (is_redir(buff[i]) && !buff[i + 1])
			return (error_return(buff));
		if (is_redir(buff[i]) && is_redir(buff[i + 1]))
			if (!(buff[i][0] == '|' && (buff[i + 1][0] == '>' || \
				buff[i + 1][0] == '<')))
				return (error_return(buff));
		i++;
	}
	return (1);
}
