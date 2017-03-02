/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:29:47 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/11/28 14:07:15 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*thing;

	thing = (char *)malloc(size);
	if (!thing)
		return (NULL);
	while (size--)
		thing[size] = 0;
	return ((void *)thing);
}
