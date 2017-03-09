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
	g_import[0] = im_char;//c
	g_import[1] = im_str;//s
	g_import[2] = im_int;//d
	g_import[3] = im_int;//i
	g_import[4] = im_oct;//o
	g_import[5] = im_hex;//x
	g_import[6] = im_hex;//X
	g_import[7] = im_uint;//u
	g_import[8] = im_double;
	g_import[9] = im_double;
	g_import[10] = im_double;
	g_import[11] = im_double;
	g_import[12] = im_double;
	g_import[13] = im_double;//A
	g_import[14] = im_double;
	g_import[15] = im_double;
	g_import[16] = im_point;
	g_import[17] = im_pct;
	g_import[18] = im_n;
	g_import[19] = im_uint;
	g_import[20] = im_wchar;
	g_import[21] = im_wstr;
	g_import[22] = im_lint;
}

void	im_char(t_conv *conv, va_list va)
{
	char c;

	if(!conv->specifier)
		return ;
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
	conv->str = ft_strdup(va_arg(va, char *));
	if (conv->str == NULL)
		conv->str = ft_strdup("(null)");
}

void	im_int(t_conv *conv, va_list va)
{
	if (conv->length[0] == 0)
		conv->str = ft_itoa(va_arg(va, int));
	if (ft_strcmp(conv->length, "hh") == 0)
		conv->str = ft_itoa((signed char)va_arg(va, int));
	if (ft_strcmp(conv->length, "h") == 0)
		conv->str = ft_itoa((short int)va_arg(va, int));
	if (ft_strcmp(conv->length, "l") == 0)
		conv->str = ft_ltoa(va_arg(va, long int));
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_lltoa(va_arg(va, long long int));
	if (ft_strcmp(conv->length, "j") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, intmax_t), 10);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, size_t), 10);
}

void	im_uint(t_conv *conv, va_list va)
{
	conv->space = 0;
	conv->plus = 0;
	if (conv->specifier == 'U')
	{
		conv->length[0] = 'l';
		conv->length[1] = 0;
	}
	if (conv->length[0] == 0)
		conv->str = ft_utoa_base((unsigned int)va_arg(va, int), 10);
	if (ft_strcmp(conv->length, "hh") == 0)
		conv->str = ft_utoa_base((unsigned char)va_arg(va, int), 10);
	if (ft_strcmp(conv->length, "h") == 0)
		conv->str = ft_utoa_base((unsigned short int)va_arg(va, int), 10);
	if (ft_strcmp(conv->length, "l") == 0)
		conv->str = ft_ulltoa_base((unsigned long long int)va_arg(va, long int), 10);
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, unsigned long long int), 10);
	if (ft_strcmp(conv->length, "j") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, intmax_t), 10);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, size_t), 10);
}

void	im_double(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("NYI");
}

void	im_point(t_conv *conv, va_list va)
{
	conv->str = ft_ultoa_base((unsigned long)va_arg(va, long int), 16);
}

void	im_oct(t_conv *conv, va_list va)
{
	if (conv->length[0] == 0)
		conv->str = ft_utoa_base(va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "hh") == 0)
		conv->str = ft_utoa_base((signed char)va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "h") == 0)
		conv->str = ft_utoa_base((short int)va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "l") == 0)
		conv->str = ft_ultoa_base(va_arg(va, long int), 8);
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, long long int), 8);
	if (ft_strcmp(conv->length, "j") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, intmax_t), 8);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, size_t), 8);
}

void	im_hex(t_conv *conv, va_list va)
{
	int i;

	if (conv->length[0] == 0)
		conv->str = ft_utoa_base(va_arg(va, unsigned int), 16);
	if (ft_strcmp(conv->length, "hh") == 0)
		conv->str = ft_utoa_base((unsigned char)va_arg(va, int), 16);
	if (ft_strcmp(conv->length, "h") == 0)
		conv->str = ft_utoa_base((unsigned short int)va_arg(va, int), 16);
	if (ft_strcmp(conv->length, "l") == 0)
		conv->str = ft_ultoa_base((unsigned long int)va_arg(va, long int), 16);
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, long long int), 16);
	if (ft_strcmp(conv->length, "j") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, intmax_t), 16);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, size_t), 16);
	i = -1;
	if (conv->specifier == 'x')
		while (conv->str[++i])
			conv->str[i] = ft_tolower(conv->str[i]);
}

void	im_pct(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("%");
}

void	im_n(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("NYI");
}

void	im_nope(t_conv *conv, va_list va)
{
	conv->str = ft_strdup("NYI");
}

void	im_wchar(t_conv *conv, va_list va)
{
	conv->str = wint_to_str(va_arg(va, wint_t));
}

void	im_wstr(t_conv *conv, va_list va)
{
	conv->str = wstr_to_str(va_arg(va, wchar_t *));
}

void	im_lint(t_conv *conv, va_list va)
{
	conv->specifier = 'd';
	conv->length[0] = 'l';
	conv->length[1] = 0;
	im_int(conv, va);
}

void	import(t_conv *conv, va_list va)
{
	setup_import();
	if (conv->specifier == 0)
		conv->str = ft_strdup("");
	else
	{
		if (conv->width == -1)
			conv->width = va_arg(va, int);
		if (conv->precision == -1)
			conv->precision = va_arg(va, int);
		g_import[chr_at(SPECIFIER, conv->specifier)](conv, va);
	}
}
