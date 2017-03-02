/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:32:07 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:34:54 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(long long nbr, int base)
{
	int digits;

	digits = 0;
	while (nbr)
	{
		digits++;
		nbr /= base;
	}
	return (digits);
}

static void	translate(char *str)
{
	while (*str)
	{
		if (*str > 57)
			*str += 7;
		str++;
	}
}

char		*ft_lltoa_base(long long value, int base)
{
	char	*output;
	int		digits;
	int		neg;
	int		negoffset;

	neg = 1;
	negoffset = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (value < 0)
	{
		neg = -1;
		negoffset = 1;
	}
	digits = count_digits(value, base);
	output = (char *)malloc(digits + 1 + negoffset);
	output[digits + negoffset] = '\0';
	while (digits--)
	{
		output[digits + negoffset] = (value % base) * neg + 48;
		value /= base;
	}
	output[0] = negoffset ? '-' : output[0];
	translate(output);
	return (output);
}

char		*ft_itoa_base(int value, int base)
{
	return (ft_lltoa_base((long long)value, base));
}

char		*ft_ltoa_base(long value, int base)
{
	return (ft_lltoa_base((long long)value, base));
}
