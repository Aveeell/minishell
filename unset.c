/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:20:37 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:20:40 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_var_from_env(t_envlist *lst, char *tab)
{
	while (lst != NULL)
	{
		if (lst->next && !ft_strcmp(lst->next->var_name, tab))
		{
			free(lst->next);
			lst->next = lst->next->next;
			return ;
		}
		lst = lst->next;
	}
}

int	unset_builtin(t_command *commad, t_envlist *lst)
{
	int			tablen;
	int			i;
	t_envlist	*tmp;

	if (!commad->args)
		return (1);
	i = 0;
	tablen = ft_tab_len(commad->args);
	while (i < tablen)
	{
		tmp = lst;
		del_var_from_env(tmp, commad->args[i]);
		i++;
	}
	return (0);
}
