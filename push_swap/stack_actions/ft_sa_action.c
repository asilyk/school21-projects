/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:22:48 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 11:04:44 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_action(t_stack_elem **head, int output)
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
			ft_putstr_fd("sa\n", 1);
	}
}
