/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:56:56 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 15:54:52 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_presort_triple(t_stack_elem **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->value;
	second = (*head)->next->value;
	third = (*head)->next->next->value;
	if (second > third && second > first && third > first)
		ft_sa_action(head, 1);
	if (third > first && third > second && first > second)
		ft_sa_action(head, 1);
	if (first > third && first > second && second > third)
		ft_sa_action(head, 1);
}

t_stack_elem	*ft_fill_stack_b(t_stack_elem **head)
{
	t_stack_elem	*head_b;
	int				min;
	int				max;
	int				med;
	int				size;

	ft_find_triple(head, &min, &max, &med);
	head_b = NULL;
	size = ft_find_stack_size(*head);
	while (size > 3)
	{
		if ((*head)->value == min || (*head)->value == max
			|| (*head)->value == med)
			ft_ra_action(head, 1);
		else
		{
			ft_pb_action(head, &head_b, 1);
			size--;
		}
	}
	ft_presort_triple(head);
	return (head_b);
}
