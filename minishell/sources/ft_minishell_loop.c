/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:31:01 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 13:53:54 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline("ms$ ");
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;
	if (!tools->args)
	{
		printf("wtf");
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	printf("ARGS: %s |\n", tools->args);
	return (1);
}
