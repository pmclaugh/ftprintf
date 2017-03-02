/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:50:21 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 17:04:08 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		i;

	if (!s)
		return (NULL);
	output = (char *)malloc(ft_strlen((char *)s) + 1);
	if (output == NULL)
		return (NULL);
	output[ft_strlen((char *)s)] = 0;
	i = 0;
	while (*s)
	{
		output[i] = f(i, *s++);
		i++;
	}
	return (output);
}
