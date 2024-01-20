/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:24:20 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:40:45 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_action(t_stack_elem **head, int output)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		ft_add_back(head, tmp);
		if (output)
			ft_putstr_fd("ra\n", 1);
	}
}
