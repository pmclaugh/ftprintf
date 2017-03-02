/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:37:57 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:39:41 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(unsigned long long nbr, int base)
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

char		*ft_ulltoa_base(unsigned long long value, int base)
{
	char	*output;
	int		digits;

	if (value == 0)
		return (ft_strdup("0"));
	digits = count_digits(value, base);
	output = (char *)malloc(digits + 1);
	output[digits] = '\0';
	while (digits--)
	{
		output[digits] = (value % base) + 48;
		value /= base;
	}
	translate(output);
	return (output);
}

char		*ft_utoa_base(unsigned int value, int base)
{
	return (ft_lltoa_base((unsigned long long)value, base));
}

char		*ft_ultoa_base(unsigned long value, int base)
{
	return (ft_lltoa_base((unsigned long long)value, base));
}
