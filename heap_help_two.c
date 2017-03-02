/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_help_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:05:28 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/01/12 18:38:09 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		h_parent_val(t_heap *heap, int ind)
{
	return ((heap->items)[h_parent_ind(ind)]);
}

int		h_peek(t_heap *heap)
{
	return (heap->items[0]);
}

void	h_swap(t_heap *heap, int a, int b)
{
	int temp;

	temp = (heap->items)[a];
	(heap->items)[a] = (heap->items)[b];
	(heap->items)[b] = temp;
}

t_heap	*new_heap(int *items, int size)
{
	t_heap	*heap;
	int		i;

	heap = (t_heap *)malloc(sizeof(t_heap));
	heap->size = 0;
	heap->items = (int *)malloc(sizeof(int));
	heap->capacity = 1;
	i = 0;
	while (i < size)
	{
		h_add(heap, items[i]);
		i++;
	}
	return (heap);
}

void	ensure_capacity(t_heap *heap)
{
	int *newitems;

	if (heap->size == heap->capacity)
	{
		newitems = (int *)malloc(sizeof(int) * heap->capacity * 2);
		heap->capacity *= 2;
		ft_memcpy(newitems, heap->items, heap->size * sizeof(int));
		free(heap->items);
		heap->items = newitems;
	}
}
