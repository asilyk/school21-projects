/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:35 by fabet             #+#    #+#             */
/*   Updated: 2022/03/21 15:38:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sig_action(int sig, siginfo_t *sig_info, void *context)
{
	static size_t	bits_count = 0;
	static char		c = 0;
	static int		pid = 0;

	(void)context;
	if (sig_info->si_pid != 0)
		pid = sig_info->si_pid;
	if (sig == SIGUSR1)
		c = c | (1 << (7 - bits_count));
	bits_count++;
	if (bits_count == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		bits_count = 0;
	}
	usleep(100);
	if (kill(pid, SIGUSR1) != 0)
	{
		ft_printf("\nError!\n");
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	sig_action;

	ft_printf("Process ID: %d\n", getpid());
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = ft_sig_action;
	sigemptyset(&sig_action.sa_mask);
	sigaddset(&sig_action.sa_mask, SIGUSR1);
	sigaddset(&sig_action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (1)
		pause();
	return (0);
}
