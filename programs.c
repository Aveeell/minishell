/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:25 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/22 14:10:43 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void) //убрал маллок, сделал статический массив, исчезла необходимость маллок проверять
{
	char pwd[1024];

	getcwd(pwd, 1024);
	printf("%s\n", pwd);
}

static void	print_echo(char **str, int i, int flag)
{
	if(str[i][0] == '$')
		printf("%s", getenv(&str[i][1]));
	else
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
	}
	if (!str[i + 1] && flag != 0)
		printf("\n");
}

void	echo(char **str) // echo $PATH PATH $PATH
{
	int	i;
	int	flag;

	flag = ft_strcmp(str[1], "-n");
	if (flag == 0)
		i = 2;
	i = 1;
	if (!str[1])
	{
		printf("\n");
		return ;
	}
	else
		while (str[i])
		{
			print_echo(str, i++, flag);
			if (str[i + 1])
				printf(" ");
		}
}

void	unset(char **str)
{
	int	i;

	i = 1;
	while(str[i])
		unlink(str[i++]);
}

void	env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}