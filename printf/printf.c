/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:34:44 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:51:06 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insert_at(char *str, char c, int index)
{
	char	*newstr;
	int		i;

	newstr = (char *)ft_memalloc(ft_strlen(str) + 2);
	i = 0;
	ft_memcpy(newstr, str, index);
	newstr[index] = c;
	ft_memcpy(newstr + index + 1, str + index, ft_strlen(str) - index + 1);
	free(str);
	return (newstr);
}

char	*stitch(t_conv *c, char *output, int *olen)
{
	char	*temp;

	if (c->specifier != 'c' && c->specifier != 'C')
	{
		temp = output;
		output = (char *)ft_memalloc(*olen + ft_strlen(c->str) + 1);
		ft_memcpy(output, temp, *olen);
		ft_memcpy(output + *olen, c->str, ft_strlen(c->str));
		free(temp);
		*olen = *olen + ft_strlen(c->str);
	}
	else
	{
		temp = output;
		output = (char *)ft_memalloc(*olen + c->width + 1);
		ft_memcpy(output, temp, *olen);
		ft_memcpy(output + *olen, c->str, c->width);
		*olen = *olen + c->width;
		free(temp);
	}
	return (output);
}

char	*append(char *str, int len, char c)
{
	char *out;

	out = (char *)malloc(len + 2);
	out[len + 1] = 0;
	out[len] = c;
	ft_memcpy(out, str, len);
	free(str);
	return (out);
}

char	*prepend(char *str, int len, char c)
{
	char *out;

	out = (char *)malloc(len + 2);
	out[len + 1] = 0;
	out[0] = c;
	ft_memcpy(out + 1, str, len);
	free(str);
	return (out);
}

void	do_it(t_conv *c, char **output, int *olen, va_list ap)
{
	if (c->specifier == 'n')
		c->str = ft_itoa(*olen);
	import(c, ap);
	process(c);
	*output = stitch(c, *output, olen);
	free_conv(c);
}

int		ft_printf(char *str, ...)
{
	va_list ap;
	char	*output;
	int		olen;
	t_conv	*c;

	va_start(ap, str);
	output = ft_strdup("");
	olen = 0;
	while (*str)
		if (*str != '%')
			output = append(output, olen++, *str++);
		else
		{
			str++;
			c = new_conv(str);
			if (c->specifier == 0)
				continue ;
			do_it(c, &output, &olen, ap);
			while (*str && !ft_strchr(SPECIFIER, *str))
				str++;
			str++;
		}
	write(1, output, olen);
	free(output);
	return (olen);
}
