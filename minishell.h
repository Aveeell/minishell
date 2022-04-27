/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:31:32 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/27 13:20:43 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"
# include <dirent.h>

typedef struct	s_str
{
	char	*input;
	char	**split_pipe;
	int		signle_q;
	int		double_q;
	int		pipes;
}				t_str;

// void	choose_func(char **str, char **envp);
void	choose_func(t_str *str, char **envp);
void	echo(char *str);
void	pwd(void);
// int		binary_exec(char **split_input, char **envp);
int binary_exec(char *input, char **envp);

// int		signals(int signal);
void	unset(char **str);
void	env(char **envp);

#endif