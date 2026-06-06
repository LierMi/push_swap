# push_swap

A sorting algorithm project: order a stack of integers using only a **limited set of stack operations**, while keeping the total number of operations as low as possible.

## The problem

You start with two stacks:

- **Stack `a`** — filled with a set of unique integers in random order.
- **Stack `b`** — empty.

The goal is to sort stack `a` in **ascending order**. The catch: you can't access elements freely. You may only manipulate the stacks through the operations below, and the quality of a solution is measured by **how few operations** it uses.

## Allowed operations

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of the other stack onto `a` / `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | Reverse-rotate `a` / `b` / both down (last element becomes first) |

The program prints the sequence of operations that sorts the stack.

## Approach

The solver scales its strategy to the input size:

- **Small inputs** are handled with hard-coded optimal move sequences.
- **Larger inputs** use a chunk/greedy strategy: numbers are pushed to stack `b` in ranges, then inserted back into `a` at the cheapest position, minimizing rotations.

## Build & usage

```bash
make
./push_swap 3 2 5 1 4
```

Output (example):

```
sa
pb
ra
...
```

Each line is one operation; applying them in order sorts the input.

---

# push_swap

一个排序算法项目：在**只能使用一组受限的栈操作**的前提下，把一组整数排好序，并尽可能减少操作总数。

## 问题描述

初始有两个栈：

- **栈 `a`** —— 装着一组互不相同、顺序随机的整数。
- **栈 `b`** —— 空栈。

目标是把栈 `a` 按**升序**排好。难点在于：不能随意访问任意元素，只能通过下面的操作来移动数据，而解法的好坏由**使用的操作数多少**来衡量——越少越好。

## 允许的操作

| 操作 | 作用 |
|------|------|
| `sa` / `sb` / `ss` | 交换 `a` / `b` / 两个栈顶部的两个元素 |
| `pa` / `pb` | 把另一个栈的栈顶压入 `a` / `b` |
| `ra` / `rb` / `rr` | 把 `a` / `b` / 两个栈整体上移（首元素变为末元素） |
| `rra` / `rrb` / `rrr` | 把 `a` / `b` / 两个栈整体下移（末元素变为首元素） |

程序最终会输出一串能将栈排好序的操作序列。

## 思路

解法会根据输入规模选择不同策略：

- **小规模输入**：直接使用预先设计好的最优操作序列。
- **较大规模输入**：采用分块 / 贪心策略——按区间将数字压入栈 `b`，再以「代价最小」的位置插回栈 `a`，从而减少旋转次数。

## 编译与运行

```bash
make
./push_swap 3 2 5 1 4
```

输出示例：

```
sa
pb
ra
...
```

每行是一个操作，按顺序执行即可将输入排好序。
