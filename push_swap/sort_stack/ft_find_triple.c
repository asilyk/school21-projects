/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_triple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:38:00 by fabet            #+#    #+#             */
/*   Updated: 2022/03/26 04:59:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sort_array(int *array, int size, t_stack_elem *head)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
	}
	return (array);
}

static void	ft_add_positions(t_stack_elem *head, int *array)
{
	int	i;

	while (head)
	{
		i = 0;
		while (array[i] != head->value)
			i++;
		head->position = i;
		head = head->next;
	}
}

void	ft_find_triple(t_stack_elem **head, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = ft_find_stack_size(*head);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		ft_free_stack(*head);
		ft_error();
	}
	array = ft_sort_array(array, size, *head);
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	ft_add_positions(*head, array);
	free(array);
}
