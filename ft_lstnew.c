/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:57:43 by fabet             #+#    #+#             */
/*   Updated: 2021/10/11 18:04:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (NULL == elem)
	{
		return (NULL);
	}
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
