/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:30:13 by fabet             #+#    #+#             */
/*   Updated: 2022/10/15 19:21:22 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	(void)argv;
	if (argc != 1)
	{
		printf("Error! Invalid number of arguments.\n");
		exit(0);
	}
	tools.envp = ft_arrdup(envp);
	ft_find_pwd(&tools);
	ft_implement_tools(&tools);

	return (0);
}
