/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:39 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 18:20:41 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

bool	stack_push_top(t_stack *s, int v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (false);
	n->val = v;
	n->next = s->top;
	s->top = n;
	s->size++;
	return (true);
}

bool	stack_pop_top(t_stack *s, int *out)
{
	t_node	*n;

	if (!s || s->size == 0 || !s->top)
		return (false);
	n = s->top;
	if (out != NULL)
		*out = n->val;
	s->top = n->next;
	s->size--;
	free(n);
	return (true);
}

void	stack_clear(t_stack *s)
{
	int	tmp;

	if (!s)
		return ;
	while (stack_pop_top(s, &tmp))
		;
}

void	stack_reverse(t_stack *a)
{
	t_stack	tmp;
	int		v;

	stack_init(&tmp);
	while (stack_pop_top(a, &v))
		stack_push_top(&tmp, v);
	*a = tmp;
}
