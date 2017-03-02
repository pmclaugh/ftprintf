/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:47:02 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/02 17:05:43 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_wspace(const char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

static int	til_endspace(const char *s)
{
	int i;
	int	lastnon;

	i = 0;
	lastnon = 0;
	while (*s)
	{
		i++;
		if (!is_wspace(*s))
			lastnon = i;
		s++;
	}
	return (lastnon);
}

char		*ft_strtrim(const char *s)
{
	char	*trimmed;

	if (!s)
		return (NULL);
	while (is_wspace(*s))
		s++;
	trimmed = (char *)malloc(til_endspace(s) + 1);
	if (trimmed == NULL)
		return (NULL);
	trimmed[til_endspace(s)] = '\0';
	ft_strncpy(trimmed, (char *)s, til_endspace(s));
	return (trimmed);
}
