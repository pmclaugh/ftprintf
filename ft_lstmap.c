/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:04:41 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/11/30 17:40:50 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *newlisthead;

	if (!lst)
		return (NULL);
	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	ft_memcpy(newlist, f(lst), sizeof(t_list));
	newlist->next = NULL;
	newlisthead = newlist;
	while (lst->next)
	{
		newlist->next = (t_list *)malloc(sizeof(t_list));
		if (!newlist->next)
			return (NULL);
		ft_memcpy(newlist->next, f(lst->next), sizeof(t_list));
		newlist->next->next = NULL;
		newlist = newlist->next;
		lst = lst->next;
	}
	return (newlisthead);
}
