/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:38:57 by liemi             #+#    #+#             */
/*   Updated: 2025/11/25 20:54:22 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* parse.c */
bool	parse_args_to_stack(int argc, char **argv, t_stack *a);

/* stack.c */
void	stack_init(t_stack *s);
bool	stack_push_top(t_stack *s, int v);
bool	stack_pop_top(t_stack *s, int *out);
void	stack_clear(t_stack *s);
void	stack_reverse(t_stack *a);

/* ops_basic.c */
void	op_sa(t_stack *a);
void	op_pb(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rra(t_stack *a);

/* tool.c */
long	ft_atol_strict(const char *s, bool *ok);
bool	exists_dup(t_stack *a, int v);

/* sort */
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	index_compress(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);

/* arr_utils.c */
int		*arr_dup_from_stack(t_stack *a);
void	arr_isort(int *arr, int n);
int		arr_index_of(int *arr, int n, int v);

#endif
