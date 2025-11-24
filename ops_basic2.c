#include "push_swap.h"

void	op_ra(t_stack *a)
{
	t_node	*first;
	t_node	*cur;//用来从新栈顶开始一路走到链表尾部（栈底）

	if (a == NULL || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	cur = a->top;
	while (cur->next != NULL)//从新的 a->top 开始，一直往下走到链表的最后一个节点
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	t_node	*prev;//永远指向 last 的前一个节点（倒数第二个）
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
