/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:45:25 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 12:12:09 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char *pwd;

	pwd = malloc(1024);
	getcwd(pwd, 1024);
	printf("%s\n", pwd);
	free(pwd);
}

void	echo(char **str)
{
	int	i;
	int	flag;
	
	i = 1;
	flag = ft_strcmp(str[1], "-n");
	if (flag == 0)
		i = 2;
	while (str[i])
	{
		if (!str[i + 1] && flag != 0)
			printf("%s\n", str[i++]);
		else if (!str[i + 1] && flag == 0)
			printf("%s", str[i++]);
		else
			printf("%s ", str[i++]);
	}
}