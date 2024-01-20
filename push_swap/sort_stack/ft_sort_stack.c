/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:53:47 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 15:51:31 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_presorted(t_stack_elem *head)
{
	t_stack_elem	*p;
	int				flag;

	flag = 0;
	p = head;
	while (head && head->next)
	{
		if (head->value > head->next->value && flag)
			return (0);
		if (head->value > head->next->value)
			flag = 1;
		head = head->next;
	}
	if (head && head->value > p->value && flag)
		return (0);
	return (1);
}

t_stack_elem	*ft_sort_stack(t_stack_elem **head)
{
	t_stack_elem	*head_b;

	if (!ft_is_presorted(*head))
	{
		head_b = ft_fill_stack_b(head);
		while (head_b)
			ft_push_to_a(head, &head_b);
	}
	ft_final_sort_stack(head);
	return (NULL);
}
