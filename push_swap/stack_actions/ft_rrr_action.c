/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:26:36 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_action(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*before_last;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		before_last = ft_find_penult_stack_elem(*head_a);
		ft_add_front(head_a, before_last->next);
		before_last->next = NULL;
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		before_last = ft_find_penult_stack_elem(*head_b);
		ft_add_front(head_b, before_last->next);
		before_last->next = NULL;
		flag += 2;
	}
	if (flag == 1 && output)
		ft_putstr_fd("rra\n", 1);
	if (flag == 2 && output)
		ft_putstr_fd("rrb\n", 1);
	if (flag == 3 && output)
		ft_putstr_fd("rrr\n", 1);
}
