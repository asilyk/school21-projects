/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:50:07 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 16:12:18 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_sort_stack(t_stack_elem **head)
{
	t_stack_elem	*ptr;
	int				min;
	int				max;
	int				med;
	int				steps;

	ft_find_triple(head, &min, &max, &med);
	ptr = *head;
	steps = 0;
	while (ptr->value != min)
	{
		steps++;
		ptr = ptr->next;
	}
	if (steps <= ft_find_stack_size(*head) - steps)
		while (steps-- > 0)
			ft_ra_action(head, 1);
	else
		while (steps++ < ft_find_stack_size(*head))
			ft_rra_action(head, 1);
}
