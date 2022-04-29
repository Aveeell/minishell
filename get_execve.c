/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:15:48 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/04/28 18:23:06 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_execve(char **buff, int i)
{
	int		len;
	char	**execve;
	int		j;

	j = 0;
	len = i;
	while (buff[len] && !ft_strchr(REDIRECTIONS, buff[len][0])) //# define REDIRECTIONS ">|<"
		len ++;  // определяем длину char **buff
	if (buff[len] == NULL && i == 0)
		return (buff);
	execve = (char **) malloc (((len - i) + 1) * sizeof(char *));
	while (j <= len - i)
		execve[j++] = ft_strdup(buff[i++]); // переприсваиваем строки 
	execve[j] = NULL;
	return (execve);
}
