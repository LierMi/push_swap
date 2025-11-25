/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:46:09 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 19:15:31 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

static int	tok_next(const char *s, int i, int *st, int *len)
{
	int	j;

	while (s[i] && is_space(s[i]))
		i++;
	j = 0;
	*st = i;
	while (s[i] && !is_space(s[i]) && j < 31)
	{
		i++;
		j++;
	}
	*len = j;
	if (j == 0 && s[i] == '\0')
		return (-1);
	return (i);
}

static bool	push_back_keep_order(t_stack *a, int v)
{
	return (stack_push_top(a, v));
}

static bool	split_and_push(t_stack *a, const char *arg)
{
	int		i;
	int		st;
	int		len;
	char	buf[32];
	bool	ok;
	long	x;

	i = 0;
	while (1)
	{
		i = tok_next(arg, i, &st, &len);
		if (i == -1)
			break ;
		if (len == 0)
			return (false);
		buf[len] = '\0';
		while (len--)
			buf[len] = arg[st + len];
		x = ft_atol_strict(buf, &ok);
		if (!ok || exists_dup(a, (int)x))
			return (false);
		if (!push_back_keep_order(a, (int)x))
			return (false);
	}
	return (true);
}

bool	parse_args_to_stack(int argc, char **argv, t_stack *a)
{
	int	i;

	if (argc < 2)
		return (true);
	i = 1;
	while (i < argc)
	{
		if (!split_and_push(a, argv[i]))
			return (false);
		i++;
	}
	stack_reverse(a);
	return (true);
}
