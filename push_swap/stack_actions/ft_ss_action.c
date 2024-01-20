/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:27:31 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 08:27:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ss_action_output(int flag)
{
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	if (flag == 2)
		ft_putstr_fd("sb\n", 1);
	if (flag == 3)
		ft_putstr_fd("ss\n", 1);
}

void	ft_ss_action(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*next;
	int				flag;

	flag = 0;
	p = *head_a;
	if (*head_a && (*head_a)->next)
	{
		next = (*head_a)->next;
		(*head_a)->next = next->next;
		next->next = p;
		(*head_a) = next;
		flag = 1;
	}
	p = *head_b;
	if (*head_b && (*head_b)->next)
	{
		next = (*head_b)->next;
		(*head_b)->next = next->next;
		next->next = p;
		(*head_b) = next;
		flag += 2;
	}
	if (output)
		ft_ss_action_output(flag);
}
