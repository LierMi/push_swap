/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:40:16 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 21:56:26 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_stack *a)
{
	t_node	*p;

	if (!a)
		return (true);
	p = a->top;
	while (p && p->next)
	{
		if (p->val > p->next->val)
			return (false);
		p = p->next;
	}
	return (true);
}

static bool	handle_parse(int argc, char **argv, t_stack *a)
{
	if (!parse_args_to_stack(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}

static void	choose_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	if (!handle_parse(argc, argv, &a))
	{
		stack_clear(&a);
		stack_clear(&b);
		return (1);
	}
	if (!is_sorted(&a))
	{
		index_compress(&a);
		choose_sort(&a, &b);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
