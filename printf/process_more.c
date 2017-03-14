/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 03:47:26 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/14 03:47:28 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	pr_dummy(t_conv *conv)
{
	;
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
		conv->str = insert_at(conv->str, ' ', \
			conv->minus * ft_strlen(conv->str));
}

void	pr_pct(t_conv *conv)
{
	char fillchar;

	fillchar = conv->zero ? '0' : ' ';
	while (ft_strlen(conv->str) < conv->width)
		conv->str = insert_at(conv->str, fillchar, \
				conv->minus * ft_strlen(conv->str));
}
