/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:23:22 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_action(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_a)
	{
		p = *head_b;
		p2 = *head_a;
		(*head_a) = (*head_a)->next;
		(*head_b) = p2;
		(*head_b)->next = p;
		if (output)
			ft_putstr_fd("pb\n", 1);
	}
}
