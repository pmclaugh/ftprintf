/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:02:51 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 17:05:22 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL);
	while (i < len)
	{
		output[i] = s[start + i];
		i++;
	}
	output[len] = '\0';
	return (output);
}
