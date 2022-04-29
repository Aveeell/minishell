/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:02:53 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/04/29 11:31:26 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cltr_c(int sig)
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
