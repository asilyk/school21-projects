/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:30:13 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 10:20:03 by fabet            ###   ########.fr       */
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
	ft_init_tools(&tools);
	// printf("\033[0;31mARGS:\033[0m\n%s\n", tools.args);
	// printf("\n\033[0;31mPATHS:\033[0m\n");
	// while (*tools.paths)
	// {
	// 	printf("%s\n", *tools.paths);
	// 	tools.paths++;
	// }
	// printf("\n\033[0;31mENVP:\033[0m\n");
	// while (*tools.envp)
	// {
	// 	printf("%s\n", *tools.envp);
	// 	tools.envp++;
	// }
	// printf("\n\033[0;31mPWD:\033[0m\n%s\n", tools.pwd);
	// printf("\n\033[0;31mPWD:\033[0m\n%s\n", tools.old_pwd);
	return (0);
}
