/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:24:07 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 17:03:55 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
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
	while (s[i])
	{
		output[i] = f(s[i]);
		i++;
	}
	return (output);
}
