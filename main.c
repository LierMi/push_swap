//src/main.c
#include "push_swap.h"
//从栈顶往下看，出现逆序就return false
static bool	is_sorted(t_stack *a)//指向t_stack的指针a
{
	t_node	*p;//指向栈顶定义一个指针 p，用来遍历链表（栈）

	if (!a)
		return (true);
	p = a->top;//从栈顶开始检查
	while (p && p->next)
	{
		if (p->val > p->next->val)//比较相邻两个结点的值 a[i] > a[i + 1]
		// 如果前一个值大于后一个值，则出现了下降对（inversion），说明整个序列不是按非降序（从小到大）排列。
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

int	main(int argc, int **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);//初始化
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
