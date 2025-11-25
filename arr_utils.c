/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:32:55 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 20:43:24 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_dup_from_stack(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*p;

	if (!a || a->size <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	p = a->top;
	while (p)
	{
		arr[i++] = p->val;
		p = p->next;
	}
	return (arr);
}

void	arr_isort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	if (!arr || n <= 1)
		return ;
	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	arr_index_of(int *arr, int n, int v)
{
	int	i;

	if (!arr || n <= 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (arr[i] == v)
			return (i);
		i++;
	}
	return (-1);
}
