/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:20:08 by fabet             #+#    #+#             */
/*   Updated: 2022/03/25 17:40:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_parse_one_str(char **argv)
{
	char	**arguments;

	arguments = ft_split(argv[1], ' ');
	if (arguments == NULL)
		ft_error();
	return (arguments);
}

static char	**ft_parse_several_str(int argc, char **argv)
{
	char	**arguments;
	int		i;

	arguments = (char **)malloc(sizeof(char *) * argc);
	if (arguments == NULL)
		ft_error();
	i = 0;
	while (i < (argc - 1))
	{
		arguments[i] = ft_strdup(argv[i + 1]);
		if (arguments[i] == NULL)
			ft_error();
		i++;
	}
	arguments[i] = NULL;
	return (arguments);
}

char	**ft_init_arguments(int argc, char **argv)
{
	char	**arguments;

	if (argc < 2)
		ft_error();
	if (argc == 2)
		arguments = ft_parse_one_str(argv);
	if (argc > 2)
		arguments = ft_parse_several_str(argc, argv);
	return (arguments);
}
