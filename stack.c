#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;//置空
}
//把元素压到栈顶（LIFO）
bool	stack_push_top(t_stack *s, int v)//目标栈，要压入的值
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (false);
	n->val = v;
	n->next = s->top;//新节点的 next 指向当前栈顶，为“头插法”做准备
	s->top = n;
	s->size++;
	return (true);
}
//弹出栈顶元素（可选取出值）
//从栈顶弹出一个元素；若 out 非空，则把弹出的值写到 *out 里。
bool	stack_pop_top(t_stack *s, int *out)
{
	t_node	*n;

	if (!s || s->size == 0 || !s->top)
		return (false);
	n = s->top;//取出当前栈顶结点。
	if (out != NULL)
		*out = n->val;
	s->top = n->next;//栈顶下移到下一个结点。
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
//把“头插导致的逆序”翻回原输入顺序；解析完成后调用。
void	stack_reverse(t_stack *a)
{
	t_stack	tmp;//在栈帧里创建一个临时的栈对象 tmp（不是指针，是一个结构体变量）
	int		v;

	stack_init(&tmp);
	while (stack_pop_top(a, &v))
		stack_push_top(&tmp, v);
	*a = tmp;
}
