/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:18:32 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:18:34 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(t_command *command)
{
	int	i;
	int	tablen;

	tablen = ft_tab_len(command->args);
	i = 0;
	if (!command->args[0] && !command->options)
		printf("\n");
	else if (command->options && !ft_strcmp(command->options, "-n"))
	{
		while (!ft_strcmp(command->args[i], "-n"))
			i++;
		while (i < tablen - 1)
			printf("%s ", command->args[i++]);
		if (tablen >= 1)
			printf("%s", command->args[i]);
	}
	else if (!command->options && command->args)
	{
		while (i < tablen - 1)
			printf("%s ", command->args[i++]);
		if (tablen >= 1)
			printf("%s\n", command->args[i]);
	}
	return (0);
}
