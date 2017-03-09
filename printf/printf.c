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

int		chr_at(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (*str ? i : -1);
}

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

t_conv	*new_conv(char *str)
{
	t_conv *conv;

	conv = new_blank_conv();
	while (ft_strchr(FLAG, *str))
	{
		set_flag(conv, *str);
		str++;
	}
	if (ft_atoi(str) != 0 || *str == '*')
	{
		if (*str == '*')
		{
			conv->width = -1;
			str++;
		}
		else
		{
			conv->width = ft_atoi(str);
			while (ft_isdigit(*str) || *str == '*')
				str++;
		}
	}
	else
		conv->width = 0;
	if (*str == '.')
	{
		conv->precision_on = 1;
		str++;
		conv->precision = *str == '*' ? -1 : ft_atoi(str);
		while (ft_isdigit(*str) || *str == '*')
			str++;
	}
	if (ft_strchr(LENGTH, *str))
	{
		conv->length[0] = *str;
		str++;
	}
	if (ft_strchr(LENGTH, *str))
	{
		conv->length[1] = *str;
		str++;
	}
	if (ft_strchr(SPECIFIER, *str))
	{
		conv->specifier = *str;
		str++;
	}
	return (conv);
}

void	print_conv(t_conv *conv)
{
	printf("\n");
	printf("flags: - %d, + %d, space %d, hash %d, zero %d\n", \
		conv->minus, conv->plus, conv->space, conv->hash, conv->zero);
	printf("width %d\n", conv->width);
	printf("precision is on/off: %d\n", conv->precision_on);
	if (conv->precision_on)
		printf("precision is %d\n", conv->precision);
	printf("length is %s\n", conv->length);
	printf("and specifier is %c\n", conv->specifier);
}

int		ft_printf(char *str, ...)
{
	va_list ap;
	char	*output;
	char	*temp;
	int		olen;
	t_conv	*c;

	va_start(ap, str);
	output = ft_strdup("");
	olen = 0;
	while (*str)
	{
		if (*str != '%')
		{
			output = insert_at(output, *str++, ft_strlen(output));
			olen++;
		}
		else
		{
			str++;
			c = new_conv(str);
			while (*str && !ft_strchr(SPECIFIER, *str))
				str++;
			import(c, ap);
			process(c);
			if (c->specifier != 'c')
			{
				temp = output;
				output = (char *)ft_memalloc(olen + ft_strlen(c->str) + 1);
				ft_memcpy(output, temp, olen);
				ft_memcpy(output + olen, c->str, ft_strlen(c->str));
				free(temp);
				olen += ft_strlen(c->str);
			}
			else
			{
				temp = output;
				output = (char *)ft_memalloc(olen + c->width + 1);
				ft_memcpy(output, temp, olen);
				ft_memcpy(output + olen, c->str, c->width);
				olen += c->width;
				free(temp);
			}
			str++;
		}
	}
	write(1, output, olen);
	return (olen);
}
