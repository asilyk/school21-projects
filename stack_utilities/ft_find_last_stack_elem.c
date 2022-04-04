/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last_stack_elem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:56:56 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:41:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*ft_find_last_stack_elem(t_stack_elem *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	else
		return (ft_find_last_stack_elem(stack->next));
}
