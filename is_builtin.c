/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:14:10 by majjig            #+#    #+#             */
/*   Updated: 2022/04/28 15:34:22 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_builtin(char *cmd) //является билтином
{
	static char	*all[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
		if (ft_strcmp(all[i++], cmd) == 0)
			return (all[--i]);
	return (NULL);
}
