/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:43:10 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 20:32:13 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_min_pos(t_stack *a)
{
	int		pos;
	int		i;
	int		minv;
	t_node	*p;

	if (!a || !a->top)
		return (0);
	pos = 0;
	i = 0;
	p = a->top;
	if (!p)
		return (0);
	minv = p->val;
	while (p)
	{
		if (p->val < minv)
		{
			minv = p->val;
			pos = i;
		}
		i++;
		p = p->next;
	}
	return (pos);
}

static void	rotate_a_to_top(t_stack *a, int pos)
{
	int	cnt;

	if (!a || a->size < 2 || pos <= 0 || pos >= a->size)
		return ;
	if (pos <= a->size / 2)
	{
		cnt = pos;
		while (cnt > 0)
		{
			op_ra(a);
			cnt--;
		}
	}
	else
	{
		cnt = a->size - pos;
		while (cnt > 0)
		{
			op_rra(a);
			cnt--;
		}
	}
}

void	sort_2(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->top->val > a->top->next->val)
		op_sa(a);
}

void	sort_3(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	if (!a || a->size < 2)
		return ;
	a1 = a->top->val;
	a2 = a->top->next->val;
	if (a->size == 2)
	{
		if (a1 > a2)
			op_sa(a);
		return ;
	}
	a3 = a->top->next->next->val;
	if (a1 > a2 && a1 > a3)
		op_ra(a);
	else if (a2 > a1 && a2 > a3)
		op_rra(a);
	if (a->top->val > a->top->next->val)
		op_sa(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	if (a->size <= 3)
	{
		if (a->size == 2)
			sort_2(a);
		else if (a->size == 3)
			sort_3(a);
		return ;
	}
	pos = stack_min_pos(a);
	rotate_a_to_top(a, pos);
	op_pb(a, b);
	pos = stack_min_pos(a);
	rotate_a_to_top(a, pos);
	op_pb(a, b);
	sort_3(a);
	op_pa(a, b);
	op_pa(a, b);
	if (a->top && a->top->next && a->top->val > a->top->next->val)
		op_sa(a);
}
