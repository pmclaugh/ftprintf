/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_ch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 03:57:04 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/14 03:57:05 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	im_char(t_conv *conv, va_list va)
{
	char c;

	if (!conv->specifier)
		return ;
	if (ft_strcmp(conv->length, "l") == 0)
	{
		im_wchar(conv, va);
		return ;
	}
	c = (char)va_arg(va, int);
	if (!c)
		conv->str = ft_strnew(0);
	else
	{
		conv->str = ft_strnew(1);
		conv->str[0] = c;
	}
}

void	im_str(t_conv *conv, va_list va)
{
	if (ft_strcmp(conv->length, "l") == 0)
	{
		conv->length[0] = 0;
		im_wstr(conv, va);
		return ;
	}
	conv->str = ft_strdup(va_arg(va, char *));
	if (conv->str == NULL)
		conv->str = ft_strdup("(null)");
}

void	im_wchar(t_conv *conv, va_list va)
{
	if (ft_strcmp(conv->length, "hh") == 0)
	{
		im_char(conv, va);
		return ;
	}
	if (MB_CUR_MAX > 1)
		conv->str = wint_to_str(va_arg(va, wint_t));
	else
		im_char(conv, va);
}

void	im_wstr(t_conv *conv, va_list va)
{
	conv->str = wstr_to_str(va_arg(va, wint_t *));
	if (conv->str == NULL)
		conv->str = ft_strdup("(null)");
}

void	im_double(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("NYI");
	va_arg(va, double);
}
