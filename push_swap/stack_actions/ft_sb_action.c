/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:27:03 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:39:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb_action(t_stack_elem **head, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*next;

	p = *head;
	if (*head && (*head)->next)
	{
		next = (*head)->next;
		(*head)->next = next->next;
		next->next = p;
		(*head) = next;
		if (output)
			ft_putstr_fd("sb\n", 1);
	}
}
