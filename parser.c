/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:20:01 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:20:04 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *command, char **buff, int *i, int *j)
{
	if (buff[*i] && *i == 1 && !ft_strcmp(buff[*i], "-n")
		&& !ft_strcmp("echo", command->program))
		command->options = ft_strdup(buff[*i]);
	else if (buff[*i] && *i > 0 && !ft_strchr("|><", buff[*i][0]))
	{
		command->args[*j] = ft_strdup(buff[*i]);
		*j += 1;
		command->args[*j] = NULL;
	}
}

int	check_quotes(char	*str)
{
	int	count1;
	int	count2;
	int	i;

	count2 = 0;
	count1 = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\"' && count1 % 2 == 0)
			count2++;
		if (str[i] == '\'' && count2 % 2 == 0)
			count1++;
		i++;
	}
	if (count1 % 2 != 0 || count2 % 2 != 0)
	{
		printf("Error: expected \" or '\n");
		return (0);
	}
	return (1);
}
