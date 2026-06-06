# push_swap

A sorting algorithm project: order a stack of integers using only a **limited set of stack operations**, while keeping the number of operations low. The solver uses **binary radix sort** on rank-compressed values, with hard-coded routines for small inputs.

## The problem

You're given two stacks:

- **Stack `a`** — filled with unique integers in random order.
- **Stack `b`** — empty.

The goal is to sort `a` in **ascending order**. Elements can't be accessed freely — the stacks may only be manipulated through a fixed vocabulary of operations, and the program must print the sequence of operations that sorts the input.

## Operations

This solver emits 5 of the standard push_swap operations:

| Op | Effect |
|----|--------|
| `sa` | Swap the top two elements of `a` |
| `pa` / `pb` | Push the top element from one stack onto the other |
| `ra` | Rotate `a` up (first element becomes last) |
| `rra` | Reverse-rotate `a` down (last element becomes first) |

## How it works

1. **Parse & validate.** Arguments are tokenized and converted with a strict `atol` that rejects non-numeric input, integer overflow (beyond `INT_MAX` / `INT_MIN`), and duplicates. Invalid input prints `Error`.
2. **Index compression.** Values are replaced by their rank (`0 … n-1`). After this step only the *binary digits* of each index matter, so value range no longer affects the algorithm.
3. **Sort by size:**
   - **2 / 3 elements** — hard-coded optimal moves.
   - **≤ 5 elements** — push the two smallest to `b`, sort the remaining three, push back.
   - **Larger** — **binary radix sort**: for each bit from least to most significant, elements with a `0` at that bit are pushed to `b` (`pb`) and elements with a `1` stay in `a` (`ra`); after each pass, `b` is pushed back onto `a` (`pa`). After ⌈log₂n⌉ passes the stack is sorted.

The stacks are implemented as singly linked lists with a cached `size`, giving O(1) length queries.

## Performance

Verified correct against thousands of random inputs per size. Because radix sort makes a fixed number of passes over the normalized indices, **the operation count depends only on the input size, not on its initial order** — the move count is fully deterministic.

| Input size | Operations |
|-----------:|-----------:|
| 5 | ≤ 10 |
| 100 | 1084 |
| 500 | 6784 |

## Build & run

```bash
make
./push_swap 3 2 5 1 4
```

Output is one operation per line; applying them in order sorts the input.

```
$ ./push_swap 3 2 5 1 4
pb
pb
...
```

Edge cases (empty input, a single value, an already-sorted stack) produce no output. Invalid input prints `Error` to stderr.

---

# push_swap

一个排序算法项目：在**只能使用一组受限的栈操作**的前提下，把一组整数排好序，并尽量减少操作数。本实现对「排名压缩」后的值采用**二进制基数排序**，小规模输入用硬编码处理。

## 问题描述

给定两个栈：

- **栈 `a`** —— 装着一组互不相同、顺序随机的整数。
- **栈 `b`** —— 空栈。

目标是把 `a` 按**升序**排好。不能随意访问元素，只能通过一组固定的操作来移动数据，程序最终输出能将输入排好序的操作序列。

## 操作

本实现只用到标准操作中的 5 个：

| 操作 | 作用 |
|------|------|
| `sa` | 交换栈 `a` 顶部两个元素 |
| `pa` / `pb` | 把一个栈的栈顶压入另一个栈 |
| `ra` | 栈 `a` 整体上移（首元素变末元素） |
| `rra` | 栈 `a` 整体下移（末元素变首元素） |

## 实现思路

1. **解析与校验。** 用严格的 `atol` 处理参数，拒绝非数字、整数溢出（超出 `INT_MAX` / `INT_MIN`）和重复值；非法输入输出 `Error`。
2. **索引压缩。** 把每个数替换成它的排名（`0 … n-1`）。此后只需关心索引的**二进制位**，数值范围不再影响算法。
3. **按规模分流排序：**
   - **2 / 3 个**：硬编码最优解。
   - **≤ 5 个**：把两个最小值推到 `b`，剩下三个排好，再推回。
   - **更大规模**：**二进制基数排序**——从最低位到最高位，每一位上该位为 `0` 的元素 `pb` 推入 `b`、为 `1` 的 `ra` 留在 `a`；每轮结束把 `b` 全部 `pa` 推回 `a`。共 ⌈log₂n⌉ 轮，结束即排好序。

栈用带 `size` 缓存的单链表实现，取长度为 O(1)。

## 性能表现

每种规模都用数千组随机输入验证过正确性。由于基数排序对归一化后的索引固定走若干轮，**操作数只取决于输入规模，与初始乱序程度无关**——步数完全确定。

| 数据量 | 操作数 |
|-----:|-----:|
| 5 | ≤ 10 |
| 100 | 1084 |
| 500 | 6784 |

## 编译与运行

```bash
make
./push_swap 3 2 5 1 4
```

每行一个操作，按顺序执行即可排好序。空输入、单个数、已排序的栈不产生输出；非法输入向 stderr 输出 `Error`。
