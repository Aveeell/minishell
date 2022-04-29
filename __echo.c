/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:47:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/04/28 15:28:27 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	__echo(t_command *commad)
{
	int	i;
	int	tablen;

	tablen = ft_tab_len(commad->args);
	i = 0;
	if (!commad->args[0]) //если нет аргументов
	{
		if (!commad->options) //если нет флагов
			printf("\n");
	}
	else if (commad->options && !ft_strcmp(commad->options, "-n")) //если есть аргументы, и есть флаг
	{
		while (i < tablen - 1) //печатаем аргументы с пробелом
			printf("%s ", commad->args[i++]);
		if (tablen >= 1) //когда 1 остается печатаем без пробела
			printf("%s", commad->args[i]);
	}
	else if (!commad->options && commad->args) //если нет флага и есть аргументы
	{
		while (i < tablen - 1)
			printf("%s ", commad->args[i++]);
		if (tablen >= 1)
			printf("%s\n", commad->args[i]);
	}
	return (0);
}
