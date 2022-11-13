/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:17:36 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:17:37 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = 0;
	}
	(*del)((*lst)->content);
	free(*lst);
	*lst = 0;
}
