/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:52 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 12:11:49 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choose_func(char **str)
{
	char *env;

	if(!ft_strcmp(str[0], "echo"))
		echo(str);
	else if(!ft_strcmp(str[0], "cd"))
		chdir(str[1]);
	else if(!ft_strcmp(str[0], "pwd"))
		pwd();
	else if(!ft_strcmp(str[0], "export"))
		printf("export\n");
	else if(!ft_strcmp(str[0], "unset"))
		printf("unset\n");
	else if(!ft_strcmp(str[0], "env"))
	{
		env = getenv("USER");
		printf("%s\n", env);
	}
	else if (!ft_strcmp(str[0], "exit"))
		exit(0);
	else
		printf("wrong command\n");
}