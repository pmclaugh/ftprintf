/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:40:41 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:46:05 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setup_import(void)
{
	g_import[0] = im_char;
	g_import[1] = im_str;
	g_import[2] = im_int;
	g_import[3] = im_int;
	g_import[4] = im_oct;
	g_import[5] = im_hex;
	g_import[6] = im_hex;
	g_import[7] = im_uint;
	g_import[8] = im_double;
	g_import[9] = im_double;
	g_import[10] = im_double;
	g_import[11] = im_double;
	g_import[12] = im_double;
	g_import[13] = im_double;
	g_import[14] = im_double;
	g_import[15] = im_double;
	g_import[16] = im_point;
	g_import[17] = im_pct;
	g_import[18] = im_n;
	g_import[19] = im_uint;
	g_import[20] = im_wchar;
	g_import[21] = im_wstr;
	g_import[22] = im_lint;
	g_import[23] = im_oct;
}

void	im_point(t_conv *conv, va_list va)
{
	conv->str = ft_ultoa_base((unsigned long)va_arg(va, long int), 16);
}

void	im_pct(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("%");
}

void	im_n(t_conv *conv, va_list va)
{
	int *addr;

	addr = va_arg(va, int *);
	*addr = ft_atoi(conv->str);
	free(conv->str);
	conv->str = ft_strdup("");
}

void	import(t_conv *conv, va_list va)
{
	setup_import();
	if (conv->specifier == 0)
	{
		conv->str = ft_strnew(conv->width);
		ft_memset(conv->str, ' ', conv->width);
	}
	else
	{
		if (conv->width == -1)
		{
			conv->width = va_arg(va, int);
			if (conv->width < 0)
			{
				conv->width = conv->width * -1;
				conv->minus = 1;
			}
		}
		if (conv->precision == -1)
		{
			conv->precision = va_arg(va, int);
			if (conv->precision < 0)
				conv->precision = 0;
		}
		g_import[chr_at(SPECIFIER, conv->specifier)](conv, va);
	}
}
