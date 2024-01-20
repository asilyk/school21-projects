/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:40:09 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:48:25 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_elem	*ft_create_elem(int value)
{
	t_stack_elem	*p;

	p = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (p == NULL)
		return (NULL);
	p->value = value;
	p->a_score = -1;
	p->b_score = -1;
	p->a_rscore = -1;
	p->b_rscore = -1;
	p->position = -1;
	p->next = NULL;
	return (p);
}

t_stack_elem	*ft_init_stack(char **arguments)
{
	int				i;
	t_stack_elem	*head;

	i = 0;
	head = NULL;
	while (arguments[i])
	{
		ft_add_back(&head, ft_create_elem(ft_atoi(arguments[i])));
		i++;
	}
	return (head);
}
