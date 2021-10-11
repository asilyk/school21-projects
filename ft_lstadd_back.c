/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:29:57 by fabet             #+#    #+#             */
/*   Updated: 2021/10/11 18:31:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	last_elem = *lst;
	if (last_elem == NULL)
	{
		*lst = ft_lstnew(new);
	}
	else
	{
		ft_lstadd_back(&(last_elem->next), new);
	}
}
