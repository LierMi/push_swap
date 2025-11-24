//索引压缩
//目标：把栈 a 里面的每个 node->val 变成它在“升序数组”里的位置（排名）
//作用：就地修改这个栈里每个节点的值
#include "push_swap.h"

void	index_compress(t_stack *a)
{
	int		*arr;//用来指向一个「数组」——这个数组里会存栈里的所有值
	int		size;//栈的大小（有多少个元素）
	t_node	*cur;//用来遍历栈的指针（当前节点）
	int		idx;//临时存放「当前节点的值在数组里对应的下标」

	size = a->size;
	arr = arr_dup_from_stack(a);
	if (arr == NULL)
		exit(1);//
	arr_isort(arr, size);
	cur = a->top;
	while (cur != NULL)
	{
		idx = arr_index_of(arr, size, cur->val);
		cur->val = idx;
		cur = cur->next;
	}
	free(arr);
}

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

//对某一位 bit 做一轮基数排序
static void	radix_round(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;
	int	num;//暂存当前栈顶元素的值（那个 0..n-1 的索引）

	size = a->size;
	i = 0;
	while (i < size)
	{
		num = a->top->val;//取当前栈顶元素的编号（0..n-1)
		if (((num >> bit) & 1) == 0)
			op_pb(a, b);//如果这一位是 0：把栈顶元素推到栈 B 中
		else
			op_ra(a);//如果这一位是 1：在栈 A 里做一个 ra
		i++;
	}
	while (b->size > 0)
		op_pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_round(a, b, bit);
		bit++;
	}
}
