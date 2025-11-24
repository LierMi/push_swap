#include "push_swap.h"
// 把栈里的值拷贝成一个 int 数组
int	*arr_dup_from_stack(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*p;

	if (!a || a->size <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;//从栈顶开始拷贝，数组从下标 0 填起。
	p = a->top;
	while (p)
	{
		arr[i++] = p->val;
		p = p->next;
	}
	return (arr);
}
// 对 int 数组做排序（升序）
//经典的插入排序（Insertion Sort），对整型数组 arr 做原地升序排序
void	arr_isort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	if (!arr || n <= 1)
		return;
	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}
// 找 value 在数组里的下标
//线性查找函数：在数组里找值 v 的下标
int	arr_index_of(int *arr, int n, int v)
{
	int	i;

	if (!arr || n <= 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (arr[i] == v)
			return (i);
		i++;
	}
	return (-1);
}
