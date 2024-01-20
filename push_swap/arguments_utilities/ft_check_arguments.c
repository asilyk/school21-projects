/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:38:28 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 17:32:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_are_numbers(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if ((ft_isdigit(arguments[i][j]) == 0)
				&& (arguments[i][j] != 43) && (arguments[i][j] != 45))
			{
				ft_free_arguments(arguments);
				ft_error();
			}
			if (((arguments[i][j] == 43) || (arguments[i][j] == 45))
				&& (ft_isdigit(arguments[i][j + 1]) == 0))
			{
				ft_free_arguments(arguments);
				ft_error();
			}
			j++;
		}
		i++;
	}
}

static void	ft_are_integers(char **arguments)
{
	long long int	number;
	int				i;

	i = 0;
	while (arguments[i])
	{
		if (ft_strlen(arguments[i]) > 11)
		{
			ft_free_arguments(arguments);
			ft_error();
		}
		number = ft_atoi(arguments[i]);
		if ((number > 2147483647) || (number < -2147483648))
		{
			ft_free_arguments(arguments);
			ft_error();
		}
		i++;
	}
}

static void	ft_are_unique(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = i + 1;
		while (arguments[j])
		{
			if (ft_strcmp(arguments[i], arguments[j]) == 0)
			{
				ft_free_arguments(arguments);
				ft_error();
			}
			j++;
		}
		i++;
	}
}

void	ft_check_arguments(char **arguments)
{
	if (!arguments[0])
	{
		free(arguments);
		exit(1);
	}
	ft_are_numbers(arguments);
	ft_are_integers(arguments);
	ft_are_unique(arguments);
}
