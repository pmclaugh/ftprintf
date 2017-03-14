/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 03:41:17 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/14 03:41:18 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*new_blank_conv(void)
{
	t_conv *conv;

	conv = (t_conv *)malloc(sizeof(t_conv));
	ft_bzero(conv, sizeof(t_conv));
	return (conv);
}

void	set_flag(t_conv *conv, char c)
{
	if (c == '-')
		conv->minus = 1;
	if (c == '+')
		conv->plus = 1;
	if (c == '#')
		conv->hash = 1;
	if (c == ' ')
		conv->space = 1;
	if (c == '0')
		conv->zero = 1;
}

void	more_conv(t_conv *conv, char *str)
{
	if (*str == '.')
	{
		conv->precision_on = 1;
		str++;
		conv->precision = *str == '*' ? -1 : ft_atoi(str);
		while (ft_isdigit(*str) || *str == '*')
			str++;
	}
	if (ft_strchr(LENGTH, *str))
		conv->length[0] = *str++;
	if (ft_strchr(LENGTH, *str))
		conv->length[1] = *str++;
	if (ft_strchr(SPECIFIER, *str))
		conv->specifier = *str++;
}

t_conv	*new_conv(char *str)
{
	t_conv *conv;

	conv = new_blank_conv();
	if (!*str)
		return (conv);
	while (ft_strchr(FLAG, *str))
		set_flag(conv, *str++);
	if (ft_atoi(str) != 0 || *str == '*')
	{
		if (*str == '*' && str++)
			conv->width = -1;
		else
		{
			conv->width = ft_atoi(str);
			while (ft_isdigit(*str) || *str == '*')
				str++;
		}
	}
	else
		conv->width = 0;
	more_conv(conv, str);
	return (conv);
}

void	free_conv(t_conv *c)
{
	if (c->str)
		free(c->str);
	free(c);
}
