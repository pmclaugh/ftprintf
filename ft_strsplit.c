/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:40:22 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/09 23:38:20 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	delim_wc(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		count++;
	}
	return (count);
}

static int	delim_strlen(const char *s, char c)
{
	int i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**output;
	char	**outputhead;
	char	*word;

	if (!s)
		return (NULL);
	output = (char **)malloc(sizeof(char *) * (delim_wc(s, c) + 1));
	if (!output)
		return (NULL);
	outputhead = output;
	output[delim_wc(s, c)] = NULL;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		word = (char *)malloc(delim_strlen(s, c) + 1);
		word[delim_strlen(s, c)] = '\0';
		ft_strncpy(word, (char *)s, delim_strlen(s, c));
		s = s + delim_strlen(s, c);
		*output++ = word;
	}
	return (outputhead);
}
