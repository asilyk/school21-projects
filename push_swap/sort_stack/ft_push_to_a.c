/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 02:40:01 by fabet            #+#    #+#             */
/*   Updated: 2022/03/26 04:59:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_scores_in_b(t_stack_elem *head_b)
{
	int	size;
	int	i;

	size = ft_find_stack_size(head_b);
	i = 0;
	while (head_b)
	{
		head_b->b_score = i;
		head_b->b_rscore = size - i;
		i++;
		head_b = head_b->next;
	}
}

static void	ft_get_scores_in_a(t_stack_elem *head_a, t_stack_elem *head_b)
{
	t_stack_elem	*ptr;
	int				size;
	int				i;
	int				last_value;

	size = ft_find_stack_size(head_a);
	ptr = head_a;
	while (head_b)
	{
		head_a = ptr;
		i = 0;
		last_value = ft_find_last_stack_elem(head_a)->value;
		while (head_a)
		{
			if (last_value < head_b->value && head_a->value > head_b->value)
			{
				head_b->a_score = i;
				head_b->a_rscore = size - i;
			}
			i++;
			last_value = head_a->value;
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}

void	ft_push_to_a(t_stack_elem **head_a, t_stack_elem **head_b)
{
	t_stack_elem	*best_elem;
	int				push_type;

	ft_get_scores_in_b(*head_b);
	ft_get_scores_in_a(*head_a, *head_b);
	best_elem = ft_choose_best_elem(*head_b, &push_type);
	ft_make_push(head_a, head_b, best_elem, push_type);
}
