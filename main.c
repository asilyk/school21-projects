/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:23:39 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 19:30:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char			**arguments;
	t_stack_elem	*head_a;

	arguments = ft_init_arguments(argc, argv);
	ft_check_arguments(arguments);
	head_a = ft_init_stack(arguments);
	ft_sort_stack(&head_a);
	ft_free_arguments(arguments);
	ft_free_stack(head_a);
	return (0);
}
