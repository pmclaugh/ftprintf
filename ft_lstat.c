/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:31:06 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/01 22:34:17 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int i)
{
	while (i)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
		i--;
	}
	return (begin_list);
}
