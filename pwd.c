/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:20:11 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:20:13 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_builtin(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		chdir("..");
		pwd = getcwd(NULL, 0);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}
