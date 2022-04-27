/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:36:44 by mkoch             #+#    #+#             */
/*   Updated: 2022/04/25 15:18:37 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int binary_exec(char **split_input, char **envp)
{
	(void)envp;
	char 			*command;
	char			**dir_paths;
	DIR				*dir;
	struct dirent 	*entity;
	pid_t			pid;
	char			source_dir[1024];
	char			bin_dir[1024];
	char 			*bin_file;
	int				i;

	command = split_input[0];
	getcwd(source_dir, 1024);
	dir_paths = ft_split(getenv("PATH"), ':'); //check return values 
	i = 0;
	while (dir_paths[i])
	{
		chdir(dir_paths[i]); //check return values
		dir = opendir(dir_paths[i]);
		if (dir == NULL)
			return (1);
		entity = readdir(dir); //check return values
		
		while (entity != NULL)
		{
			if ((entity->d_type == DT_REG) && (ft_strncmp(entity->d_name, command, ft_strlen(command) + 1) == 0))
			// if ((entity->d_type == DT_REG) && (ft_strcmp(entity->d_name, command)))
			{
				pid = fork();
				if (pid == 0)
				{
					getcwd(bin_dir, 1024);
					bin_file = ft_strjoin(ft_strjoin(bin_dir, "/"), entity->d_name);
					chdir(source_dir);
					execve(bin_file, split_input, envp);
				}
				else
					wait(NULL);
			}
			entity = readdir(dir);
		}
		chdir(source_dir);
		dir = opendir(dir_paths[i]);
		i++;
	}
	closedir(dir);
	free(bin_file);
	i = 0;
	while (dir_paths[i])
		free(dir_paths[i++]);
	free(dir_paths);
	return (0);
}