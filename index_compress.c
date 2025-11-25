/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:46:02 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 21:52:35 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_compress(t_stack *a)
{
	int		*arr;
	int		size;
	t_node	*cur;
	int		idx;

	size = a->size;
	arr = arr_dup_from_stack(a);
	if (arr == NULL)
		exit(1);
	arr_isort(arr, size);
	cur = a->top;
	while (cur != NULL)
	{
		idx = arr_index_of(arr, size, cur->val);
		cur->val = idx;
		cur = cur->next;
	}
	free(arr);
}

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_round(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;
	int	num;

	size = a->size;
	i = 0;
	while (i < size)
	{
		num = a->top->val;
		if (((num >> bit) & 1) == 0)
			op_pb(a, b);
		else
			op_ra(a);
		i++;
	}
	while (b->size > 0)
		op_pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_round(a, b, bit);
		bit++;
	}
}
