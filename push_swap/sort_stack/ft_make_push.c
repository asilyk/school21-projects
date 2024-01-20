/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:10:53 by fabet            #+#    #+#             */
/*   Updated: 2022/03/26 04:59:44 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_push1(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int push_type)
{
	if (push_type == 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			ft_rr_action(head_a, head_b, 1);
		while (elem->b_score-- > 0)
			ft_rb_action(head_b, 1);
	}
	if (push_type == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			ft_rr_action(head_a, head_b, 1);
		while (elem->a_score-- > 0)
			ft_ra_action(head_a, 1);
	}
	if (push_type == 3)
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore--)
			ft_rrr_action(head_a, head_b, 1);
		while (elem->b_rscore-- > 0)
			ft_rrb_action(head_b, 1);
	}
}

static void	ft_make_push2(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int push_type)
{
	if (push_type == 4)
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore--)
			ft_rrr_action(head_a, head_b, 1);
		while (elem->a_rscore-- > 0)
			ft_rra_action(head_a, 1);
	}
	if (push_type == 5)
	{
		while (elem->b_score-- > 0)
			ft_rb_action(head_b, 1);
		while (elem->a_rscore-- > 0)
			ft_rra_action(head_a, 1);
	}
	if (push_type == 6)
	{
		while (elem->b_rscore-- > 0)
			ft_rrb_action(head_b, 1);
		while (elem->a_score-- > 0)
			ft_ra_action(head_a, 1);
	}
}

void	ft_make_push(t_stack_elem **head_a,
			t_stack_elem **head_b, t_stack_elem *elem, int push_type)
{
	if (push_type < 4)
		ft_make_push1(head_a, head_b, elem, push_type);
	if (push_type > 3)
		ft_make_push2(head_a, head_b, elem, push_type);
	ft_pa_action(head_a, head_b, 1);
}
