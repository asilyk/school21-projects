/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:26:11 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:32 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_action(t_stack_elem **head, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = ft_find_penult_stack_elem(*head);
		ft_add_front(head, before_last->next);
		before_last->next = NULL;
		if (output)
			ft_putstr_fd("rrb\n", 1);
	}
}
