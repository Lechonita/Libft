/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:24:49 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:35 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newbis;

	if (!lst || !f || !del)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (!newlst)
		return (NULL);
	newbis = newlst;
	while (lst->next)
	{
		newbis->next = ft_lstnew((*f)(lst->next->content));
		if (!newbis->next)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
		newbis = newbis->next;
	}
	return (newlst);
}
