/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_best_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:56:39 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 15:59:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_result(int result, t_stack_elem *head, int *push_type)
{
	if (head->b_score + head->a_rscore < result)
	{
		result = head->b_score + head->a_rscore;
		*push_type = 5;
	}
	if (head->b_rscore + head->a_score < result)
	{
		result = head->b_rscore + head->a_score;
		*push_type = 6;
	}
	return (result);
}

static int	ft_get_best_score(t_stack_elem *head, int *push_type)
{
	int	result;
	int	biggest_rscore;

	result = head->b_score;
	*push_type = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		*push_type = 2;
	}
	biggest_rscore = head->a_rscore;
	if (head->b_rscore > biggest_rscore)
		biggest_rscore = head->b_rscore;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (head->b_rscore > head->a_rscore)
			*push_type = 3;
		else
			*push_type = 4;
	}
	return (ft_get_result(result, head, push_type));
}

t_stack_elem	*ft_choose_best_elem(t_stack_elem *head, int *push_type)
{
	t_stack_elem	*ptr;
	int				best_score;
	int				best_position;
	int				best_push_type;

	best_score = ft_get_best_score(head, push_type);
	best_position = head->position;
	best_push_type = *push_type;
	ptr = head;
	while (head)
	{
		if (ft_get_best_score(head, push_type) < best_score
			|| (ft_get_best_score(head, push_type) == best_score
				&& head->position >= best_position))
		{
			best_score = ft_get_best_score(head, push_type);
			best_position = head->position;
			best_push_type = *push_type;
		}
		head = head->next;
	}
	*push_type = best_push_type;
	while (ptr->position != best_position)
		ptr = ptr->next;
	return (ptr);
}
