/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:19:29 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:19:32 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_builtin(char *cmd)
{
	int			i;
	static char	*all[] = {"echo", "cd", "pwd", "export", "unset", "env",
		"exit"};

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(all[i], cmd))
			return (all[i]);
		i++;
	}
	return (NULL);
}
