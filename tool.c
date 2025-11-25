/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:42:17 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 21:54:18 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*parse_sign(const char *s, long *sign)
{
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

static bool	is_overflow(long num, long sign)
{
	if (sign == 1 && num > (long)INT_MAX)
		return (true);
	if (sign == -1 && -num < (long)INT_MIN)
		return (true);
	return (false);
}

long	ft_atol_strict(const char *s, bool *ok)
{
	long	sign;
	long	num;

	*ok = false;
	sign = 1;
	num = 0;
	s = parse_sign(s, &sign);
	if (!*s)
		return (0);
	while (*s)
	{
		if (!is_digit(*s))
			return (0);
		num = num * 10 + (*s - '0');
		if (is_overflow(num, sign))
			return (0);
		s++;
	}
	*ok = true;
	return (sign * num);
}

bool	exists_dup(t_stack *a, int v)
{
	t_node	*p;

	if (!a)
		return (false);
	p = a->top;
	while (p)
	{
		if (p->val == v)
			return (true);
		p = p->next;
	}
	return (false);
}
