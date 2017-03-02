/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:14:31 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/01 22:30:09 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newstr;

	newstr = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (newstr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_memcpy(newstr, (char *)s1, ft_strlen((char *)s1) + 1));
}
