/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:20:29 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:20:32 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cltr_c(int sig)
{
	printf("\n");
	g_variable.g_exites = 128 + sig;
	if (!g_variable.is_running)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	signal_handler(void)
{
	signal(SIGINT, cltr_c);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
