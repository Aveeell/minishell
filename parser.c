/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:20:20 by majjig            #+#    #+#             */
/*   Updated: 2022/04/28 15:59:34 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *command, char **buff, int *i, int *ai)
{
	if (buff[*i] && *i == 1 && !ft_strcmp(buff[*i], "-n") 
		&& !ft_strcmp(_ECHO, command -> program)) //проверяем наличие аргументов и флагов
	{
		command -> options = ft_strdup(buff[*i]); //копируем флаг
	}
	else if (buff[*i] && *i > 0 && !ft_strchr(REDIRECTIONS, buff[*i][0]))
	{
		command -> args[*ai] = ft_strdup(buff[*i]); //копируем аргументы
		*ai += 1;
		command -> args[*ai] = NULL;
	}
}
