/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:57:47 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 19:19:11 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}
