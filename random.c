/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:32:21 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/01/13 22:04:35 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rand_lcg(void)
{
	static int		*seed;
	unsigned long	a;
	unsigned long	c;

	a = 1664525;
	c = 1013904223;
	if (seed == NULL)
	{
		seed = (int *)malloc(sizeof(int));
		*seed = (int)seed;
	}
	*seed = (int)(a * (*seed) + c);
	return (*seed);
}

int			ft_rand(int max)
{
	return (rand_lcg() % max);
}
