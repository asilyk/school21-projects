/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_stack_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:48:47 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 14:48:52 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_stack_size(t_stack_elem *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + ft_find_stack_size(stack->next));
}
