/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:58:27 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/01 20:32:56 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*s)
		return (c == 0 ? (char *)s : NULL);
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (j)
		return ((char *)s + j);
	else if (*s == c)
		return ((char *)s);
	else if (c == 0)
		return ((char *)s + i);
	else
		return (NULL);
}
