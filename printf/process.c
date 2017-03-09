/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:46:45 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:49:00 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setup_process(void)
{
	g_process[0] = pr_char;
	g_process[1] = pr_str;
	g_process[2] = pr_int;
	g_process[3] = pr_int;
	g_process[4] = pr_oct;
	g_process[5] = pr_int;
	g_process[6] = pr_int;//X
	g_process[7] = pr_int;
	g_process[8] = pr_double;
	g_process[9] = pr_double;
	g_process[10] = pr_double;
	g_process[11] = pr_double;
	g_process[12] = pr_double;
	g_process[13] = pr_double;//A
	g_process[14] = pr_double;
	g_process[15] = pr_double;
	g_process[16] = pr_point;
	g_process[17] = pr_pct;
	g_process[18] = pr_n;
	g_process[19] = pr_int;
	g_process[20] = pr_char;
	g_process[21] = pr_str;
	g_process[22] = pr_int;
	g_process[23] = pr_oct;
}

void	pr_char(t_conv *conv)
{
	int i;

	i = 1;
	while (i++ < conv->width)
		conv->str = insert_at(conv->str, ' ', conv->minus * ft_strlen(conv->str));
	if (conv->width == 0)
		conv->width = 1;
}

void	pre_int(t_conv *conv)
{
	if (conv->str[0] == '-')
	{
		conv->plus = 0;
		conv->space = 0;
	}
	if (conv->precision_on && conv->precision == 0 && ft_atoi(conv->str) == 0)
	{
		conv->plus = 0;
		conv->space = 0;
		free(conv->str);
		conv->str = ft_strdup("");
		if (conv->specifier == 'x' || conv->specifier == 'X')
			return ;
	}
	if (conv->hash && (ft_atoi(conv->str) != 0 || conv->str[0] == 0))
	{
		conv->plus = 0;
		conv->space = 0;
		conv->str = insert_at(conv->str, '0', 0);
		if (conv->specifier == 'x' || conv->specifier == 'X')
			conv->str = insert_at(conv->str, conv->specifier, 1);
	}
}

void	pr_int(t_conv *conv)
{
	int		signoffset;
	char	fillchar;

	pre_int(conv);
	if (conv->precision_on || conv->minus)
		conv->zero = 0;
	fillchar = conv->zero && !conv->minus ? '0' : ' ';
	signoffset = fillchar == '0' && (conv->str[0] == '-' || conv->plus || conv->space) ? 1 : 0;
	while (conv->precision_on && ft_strlen(conv->str) < \
			conv->precision + (conv->str[0] == '-'))
		conv->str = insert_at(conv->str, '0', (conv->str[0] == '-'));
	if (conv->plus)
		conv->str = insert_at(conv->str, '+', 0);
	else if (conv->space)
		conv->str = insert_at(conv->str, ' ', 0);
	if ((conv->specifier == 'x' || conv->specifier == 'X') && conv->hash && fillchar == '0')
		signoffset = 2;
	while (ft_strlen(conv->str) < conv->width)
		conv->str = insert_at(conv->str, fillchar, signoffset + conv->minus * ft_strlen(conv->str));
}

void	pr_str(t_conv *conv)
{
	char fillchar;

	if (conv->precision_on)
		conv->str[conv->precision] = 0;
	if (conv->minus == 0)
	{
		fillchar = conv->zero ? '0' : ' ';
		while (conv->width > ft_strlen(conv->str))
			conv->str = insert_at(conv->str, fillchar, 0);
	}
	else
	{
		fillchar = ' ';
		while (conv->width > ft_strlen(conv->str))
			conv->str = insert_at(conv->str, fillchar, ft_strlen(conv->str));
	}
}

void	pr_oct(t_conv *conv)
{
	conv->plus = 0;
	pr_int(conv);
}

void	pr_double(t_conv *conv)
{
}

void	pr_point(t_conv *conv)
{
	int i;

	i = -1;
	if (conv->precision_on && conv->precision == 0 && conv->str[0] == '0')
		conv->str = ft_strdup("");
	else
		while (conv->str[++i])
			conv->str[i] = ft_tolower(conv->str[i]);
	while (conv->precision_on && ft_strlen(conv->str) < conv->precision)
		conv->str = insert_at(conv->str, '0', 0);
	conv->str = insert_at(conv->str, 'x', 0);
	conv->str = insert_at(conv->str, '0', 0);
	while (ft_strlen(conv->str) < conv->width)
		conv->str = insert_at(conv->str, ' ', 0);
}

void	pr_pct(t_conv *conv)
{
	char fillchar;

	fillchar = conv->zero ? '0' : ' ';
	while (ft_strlen(conv->str) < conv->width)
		conv->str = insert_at(conv->str, fillchar, \
				conv->minus * ft_strlen(conv->str));
}

void	pr_n(t_conv *conv)
{

}

void	pr_nope(t_conv *conv)
{

}

void	process(t_conv *conv)
{
	setup_process();
	if (conv->specifier != 0)
		g_process[chr_at(SPECIFIER, conv->specifier)](conv);
}
