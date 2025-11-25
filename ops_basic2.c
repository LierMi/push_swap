/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:53:28 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 20:53:30 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a)
{
	t_node	*first;
	t_node	*cur;

	if (a == NULL || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	cur = a->top;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (a == NULL || a->size < 2)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}
