/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:10:26 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:37:27 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	return (ft_lltoa_base((long long)n, 10));
}

char	*ft_ltoa(long n)
{
	return (ft_lltoa_base((long long)n, 10));
}

char	*ft_lltoa(long long n)
{
	return (ft_lltoa_base(n, 10));
}
