/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:59:55 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/01/12 17:05:48 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		h_parent_ind(int ind)
{
	return ((ind - 1) / 2);
}

int		h_left_ind(int ind)
{
	return (2 * ind + 1);
}

int		h_right_ind(int ind)
{
	return (2 * ind + 2);
}

int		h_left_val(t_heap *heap, int ind)
{
	if (h_left_ind(ind) < heap->size)
		return (heap->items[h_left_ind(ind)]);
	return ((heap->items)[ind]);
}

int		h_right_val(t_heap *heap, int ind)
{
	if (h_right_ind(ind) < heap->size)
		return (heap->items[h_right_ind(ind)]);
	return ((heap->items)[ind]);
}
