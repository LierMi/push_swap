#include "push_swap.h"

static bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}
//要解析的字符串，当前读到的位置下标i，这次token的起始下班，这次token的长度
static int	tok_next(const char *s, int i, int *st, int *len)
{
	int	j;//计数器

	while (s[i] && is_space(s[i]))
		i++;
	j = 0;
	*st = i;//起始位置记录下来，本次token从i开始
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
/* 3) 暂用头插（保持输入顺序：最后调用 stack_reverse） */
static bool	push_back_keep_order(t_stack *a, int v)
{
	return (stack_push_top(a, v));
}
/* 4) 切分 + 转数 + 查重 + 入栈（只处理一个 argv） */
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
/* 5) 主入口：支持 ./push_swap "3 2 1" 和 ./push_swap 3 2 1 */

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
