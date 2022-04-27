/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:52 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/27 13:19:29 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	cd(char *str)
// {
// 	// int	i;
// 	char	*dest;

// 	dest = ft_strtrim(str, " ");
// 	// i = 1;
// 	// dest = str[1];
// 	// if (str[i + 1])
// 	// {
// 	// 	while (str[i + 1])
// 	// 	{
// 	// 		dest = ft_strjoin(ft_strjoin(dest, " "), str[i + 1]);
// 	// 		i++;
// 	// 	}
// 	// }
// 	if (chdir(dest == -1))
// 		printf("%s: No such file or directory\n", str);
// 	free(dest);
// }

char *get_command(char *str)
{
	int i = 0;
	char *command;

	while (str[i] != ' ')
		i++;
	command = ft_calloc(i, 1);
	if (!command)
		return NULL;
	while (i--)
		command[i] = str[i];
	return command;
}

// void	choose_func(char **str, char **envp)
void	choose_func(t_str *str, char **envp)
{
	int	i;
	char *command;

	i = 0;
	// for (int i = 0; ft_strchr(str->input, ' ')[i]; i++)
	// 	printf("%c\n", ft_strchr(str->input, ' ')[i]);
	while (str->split_pipe[i])
	{
		command = get_command(str->split_pipe[i]);
		// printf("arg - %s\n", ft_strchr(str->input, ' '));
		if(!ft_strcmp(command, "echo"))
			echo(str->split_pipe[i]); // -n -n -n
		// else if(!ft_strcmp(command, "cd"))
		// 	cd(ft_strchr(str->input, ' '));
		else if(!ft_strcmp(command, "pwd"))
			pwd();
		// else if(!ft_strcmp(command, "export"))
		// 	printf("export\n"); //execve??????????????????
		// else if(!ft_strcmp(command, "unset"))
		// 	unset(ft_strchr(str->input, ' '));
		if(!ft_strcmp(command, "env"))
			env(envp);
		else if (!ft_strcmp(command, "exit"))
			exit(0);
		else
			binary_exec(str->split_pipe[i], envp);
		// else
		// 	printf("wrong command\n");
		i++;
	}
}