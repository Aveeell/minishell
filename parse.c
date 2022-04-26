/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:52 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/22 15:22:05 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	choose_func(char **str, char **envp)
{
	//(void)envp;
	char *env;

void	cd(char **str)
{
	int	i;
	char	*dest;
	
	i = 1;
	dest = str[1];
	if (str[i + 1])
	{
		while (str[i + 1])
		{
			dest = ft_strjoin(ft_strjoin(dest, " "), str[i + 1]);
			i++;
		}
	}
	if (chdir(dest) == -1)
		printf("%s: No such file or directory\n", str[1]);
	free(dest);
}

void	choose_func(char **str, char **envp)
{
	if(!ft_strcmp(str[0], "echo"))
		echo(str); // -n -n -n
	else if(!ft_strcmp(str[0], "cd"))
		cd(str);
	else if(!ft_strcmp(str[0], "pwd"))
		pwd();
	else if(!ft_strcmp(str[0], "export"))
		printf("export\n"); //execve??????????????????
	else if(!ft_strcmp(str[0], "unset"))
		unset(str);
	else if(!ft_strcmp(str[0], "env"))

	{
		env = getenv("USER");
		printf("%s\n", env);
	}
	// else if(str[0][0] == -1)
	// 	printf("keks");

		env(envp);
	else if (!ft_strcmp(str[0], "exit"))
		exit(0);
	else
		binary_exec(str, envp);
	// else
	// 	printf("wrong command\n");
}