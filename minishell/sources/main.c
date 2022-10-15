/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:30:13 by fabet             #+#    #+#             */
/*   Updated: 2022/10/15 13:05:25 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	(void)argv;
	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	tools.envp = ft_arrdup(envp);
	// while (*tools.envp)
	// {
	// 	printf("%s\n", *tools.envp);
	// 	tools.envp++;
	// }
	return (0);
}
