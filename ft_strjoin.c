/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:16:30 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 17:03:38 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*output;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	output = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!output)
		return (NULL);
	while (*s1)
		output[i++] = *s1++;
	while (*s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}
