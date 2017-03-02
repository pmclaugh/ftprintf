/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:05:32 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/01/12 18:41:25 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	heapify_down(t_heap *heap)
{
	int index;

	index = 0;
	while (heap->items[index] > h_left_val(heap, index) || \
			heap->items[index] > h_right_val(heap, index))
	{
		if (h_left_val(heap, index) < h_right_val(heap, index))
		{
			h_swap(heap, index, h_left_ind(index));
			index = h_left_ind(index);
		}
		else
		{
			h_swap(heap, index, h_right_ind(index));
			index = h_right_ind(index);
		}
	}
}

void	heapify_up(t_heap *heap)
{
	int index;

	index = heap->size - 1;
	while (index != 0 && h_parent_val(heap, index) > heap->items[index])
	{
		h_swap(heap, index, h_parent_ind(index));
		index = h_parent_ind(index);
	}
}

void	h_add(t_heap *heap, int elem)
{
	ensure_capacity(heap);
	heap->items[heap->size] = elem;
	heap->size += 1;
	heapify_up(heap);
}

int		h_pop(t_heap *heap)
{
	int ret;

	ret = heap->items[0];
	heap->items[0] = heap->items[heap->size - 1];
	heap->size -= 1;
	heapify_down(heap);
	return (ret);
}

void	heap_sort(int *data, int n)
{
	t_heap	*theheap;
	int		i;

	theheap = new_heap(data, n);
	i = -1;
	while (++i < n)
		data[i] = h_pop(theheap);
}
