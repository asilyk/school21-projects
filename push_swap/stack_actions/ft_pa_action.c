/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:23:58 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:14 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_action(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_b)
	{
		p = *head_a;
		p2 = *head_b;
		(*head_b) = (*head_b)->next;
		(*head_a) = p2;
		(*head_a)->next = p;
		if (output)
			ft_putstr_fd("pa\n", 1);
	}
}
