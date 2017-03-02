/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:49:33 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 16:49:48 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*with_static_array(void *dest, const void *src, size_t n)
{
	char temp[n];

	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char *temp;

	temp = (char *)malloc(n);
	if (!temp)
		return (with_static_array(dest, src, n));
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}
