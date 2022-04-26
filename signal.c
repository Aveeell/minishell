/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:41:39 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 12:51:07 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sighandler(int sig, siginfo_t *siginfo, void *context)
{
	static char	b = -1;
	static int	bits = 0;

	(void) context;
	if (sig == SIGUSR1)
		b |= 128 >> bits;
	else if (sig == SIGUSR2)
		b ^= 128 >> bits;
	bits++;
	if (bits == 8)
	{
		bits = 0;
		if (b == '\n')
			kill(siginfo->si_pid, 31);
		else
			kill(siginfo->si_pid, 30);
		write(1, &b, 1);
		b = -1;
	}
}

int	sig(void)
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}