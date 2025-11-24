#include "push_swap.h"
//交换栈 a 顶部两个元素
void	op_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a == NULL || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

static void	push_one(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (from == NULL || from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	from->size--;
	node->next = to->top;
	to->top = node;
	to->size++;
}

void	op_pb(t_stack *a, t_stack *b)
{
	push_one(a, b);
	write(1, "pb\n", 3);
}

void	op_pa(t_stack *a, t_stack *b)
{
	push_one(b, a);
	write(1, "pa\n", 3);
}
