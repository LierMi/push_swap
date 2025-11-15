#include "push_swap.h"
//从栈顶开始往下走，找出最小的那个数值，并且把它的**位置（从 0 起算）**返回。
static int  stack_min_pos(t_stack *a)
{
	int     pos;   // 当前已知“最小值”的下标（位置）
	int     i;     // 遍历到第几个节点的计数器（从 0 开始）
	int     minv;  // 当前已知“最小值”的数值
	t_node  *p;    // 遍历指针：指向当前节点

	if (!a || !a->top)
		return (0);
	pos = 0;       // 先假设最小值在位置 0
	i = 0;         // 遍历下标从 0 开始（栈顶就是 0）
	p = a->top;    // 从栈顶（链表头）开始
	if (!p)        // 如果栈是空的（没有任何节点）
		return (0);// 直接返回 0（约定：空栈时返回 0）
	minv = p->val; // 先把第一个节点当作“当前最小值”
	while (p)      // 只要还有节点，就继续循环
	{
		if (p->val < minv) // 如果发现更小的值
		{
			minv = p->val; // 更新“最小值”
			pos = i;       // 记录它所在的位置
		}
		i++;               // 走到下一个位置
		p = p->next;       // 指针后移到下一个节点
	}
	return (pos);   // 返回全程找到的最小值的位置
}
/* 2) 把 a 中索引为 pos 的元素转到栈顶（选更近的方向） */
static void	rotate_a_to_top(t_stack *a, int pos)
{
	int	cnt; //临时计数器，表示要转几次。

	if (!a || a->size < 2 || pos <= 0 || pos >= a->size)
		return ;
	if (pos <= a->size / 2)
	{
		cnt = pos;
		while (cnt > 0)
		{
			op_ra(a); //正向旋转ra，反向旋转rra
			cnt--;
		}
	}
	else
	{
		cnt = a->size - pos;
		while (cnt > 0)
		{
			op_rra(a);
			cnt--;
		}
	}
}

/* 3) 两个数：若逆序就交换 */
void	sort_2(t_stack *a) //a 是栈（单链表）的指针
{
	if (!a || a->size < 2)
		return ;
	if (a->size < 2)
		return ;
	if (a->top->val > a->top->next->val)
		op_sa(a);
}
//如果第 1 个值 > 第 2 个值，说明是逆序（例如 5、3），需要交换。

void	sort_3(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	if (!a || a->size < 2)
		return ;
	a1 = a->top->val;
	a2 = a->top->next->val;
	if (a->size == 2)
	{
		if (a1 > a2)
			op_sa(a);
		return ;
	}
	a3 = a->top->next->next->val;
	if (a1 > a2 && a1 > a3)
		op_ra(a);
	else if (a2 > a1 && a2 > a3)
		op_rra(a);
	if (a->top->val > a->top->next->val)
		op_sa(a);
}
/* 5) 五个数：推出两次最小值 → sort_3 → 再 pa 回来并必要时 sa */
//“小规模排序”策略：把最小的两个数暂时丢到 b，
//把 a 里剩下的 3 个排好，再把这两个最小值按顺序放回 a 顶部
void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	if (a->size <= 3)
	{
		if (a->size == 2)
			sort_2(a);
		else if (a->size == 3)
			sort_3(a);
		return ;
	}
	pos = stack_min_pos(a);//找到当前最小值在 a 里的位置（从栈顶起算，栈顶是 0）。
	rotate_a_to_top(a, pos);//把这个最小值旋到栈顶
	op_pb(a, b);//把 a 的栈顶（也就是刚才的最小值）推到 b,现在 b 的栈顶就是全局最小值
	pos = stack_min_pos(a);
	rotate_a_to_top(a, pos);
	op_pb(a, b);
	sort_3(a);
	op_pa(a, b);
	op_pa(a, b);
	if (a->top && a->top->next && a->top->val > a->top->next->val)
		op_sa(a);
}
