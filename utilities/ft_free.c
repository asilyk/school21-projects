/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:32:42 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:35:07 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	ft_free_stack(t_stack_elem *head)
{
	t_stack_elem	*elem;

	while (head)
	{
		elem = head;
		head = head->next;
		free(elem);
	}
}
