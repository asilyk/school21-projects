/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:41:58 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:41:03 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack_elem **stack, t_stack_elem *new)
{
	t_stack_elem	*p;

	if (*stack == NULL)
		*stack = new;
	else
	{
		p = ft_find_last_stack_elem(*stack);
		p->next = new;
	}
}
