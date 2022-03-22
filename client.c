/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:48:58 by fabet             #+#    #+#             */
/*   Updated: 2022/03/21 15:48:23 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_check_arguments(int argc, char *pid)
{
	size_t	i;

	if (argc != 3)
	{
		ft_printf("\nError! Invalid number of arguments.\n");
		exit(1);
	}
	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("\nError! PID is not valid.\n");
			exit(1);
		}
		i++;
	}
}

static void	ft_send_message(int pid, char *message)
{
	size_t	n;
	int		sig;

	while (*message)
	{
		n = 0;
		while (n < 8)
		{
			if ((*message << n) & 128)
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			if (kill(pid, sig) != 0)
			{
				ft_printf("\nError!\n");
				exit(1);
			}
			pause();
			n++;
		}
		message++;
	}
	ft_printf("The message has been sent\n");
}

static void	ft_sig_action(int sig, siginfo_t *sig_info, void *context)
{
	(void)sig;
	(void)sig_info;
	(void)context;
	return ;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig_action;

	ft_check_arguments(argc, argv[1]);
	pid = ft_atoi(argv[1]);
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = ft_sig_action;
	sigemptyset(&sig_action.sa_mask);
	sigaddset(&sig_action.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sig_action, NULL);
	ft_send_message(pid, argv[2]);
	return (0);
}
