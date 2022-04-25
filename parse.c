/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:52 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/25 15:43:58 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choose_func(char **str, char **envp)
{
	//(void)envp;
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
	// else if(str[0][0] == -1)
	// 	printf("keks");
	else if (!ft_strcmp(str[0], "exit"))
		exit(0);
	else
		binary_exec(str, envp);
	// else
	// 	printf("wrong command\n");
}