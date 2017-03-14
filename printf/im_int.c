/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 03:56:51 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/14 03:56:54 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		conv->str = ft_lltoa_base(va_arg(va, intmax_t), 10);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_lltoa_base(va_arg(va, size_t), 10);
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
		conv->str = ft_ulltoa_base((unsigned long long int)\
			va_arg(va, long int), 10);
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, unsigned long long int), 10);
	if (ft_strcmp(conv->length, "j") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, intmax_t), 10);
	if (ft_strcmp(conv->length, "z") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, size_t), 10);
}

void	im_oct(t_conv *conv, va_list va)
{
	if (conv->specifier == 'O')
	{
		conv->length[0] = 'l';
		conv->length[1] = 0;
	}
	if (conv->length[0] == 0)
		conv->str = ft_utoa_base(va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "hh") == 0)
		conv->str = ft_utoa_base((unsigned char)va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "h") == 0)
		conv->str = ft_utoa_base((unsigned short int)va_arg(va, int), 8);
	if (ft_strcmp(conv->length, "l") == 0)
		conv->str = ft_ulltoa_base((unsigned long long int)\
			va_arg(va, long int), 8);
	if (ft_strcmp(conv->length, "ll") == 0)
		conv->str = ft_ulltoa_base(va_arg(va, unsigned long long int), 8);
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
		conv->str = ft_ulltoa_base((unsigned long long int)\
			va_arg(va, long int), 16);
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

void	im_lint(t_conv *conv, va_list va)
{
	conv->specifier = 'd';
	conv->length[0] = 'l';
	conv->length[1] = 0;
	im_int(conv, va);
}
