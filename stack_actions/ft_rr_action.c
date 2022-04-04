/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:25:13 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr_action_output(int flag)
{
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	if (flag == 2)
		ft_putstr_fd("rb\n", 1);
	if (flag == 3)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rr_action(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*tmp;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = NULL;
		ft_add_back(head_a, tmp);
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = NULL;
		ft_add_back(head_b, tmp);
		flag += 2;
	}
	if (output)
		ft_rr_action_output(flag);
}
