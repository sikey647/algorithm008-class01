# 学习笔记

## 数据结构

### 一维

* 基础：数组（array）、链表（linked list）
* 高级：栈（stack）、队列（queue）、双端队列（deque）、集合（set）、映射（map）

### 二维

* 基础：树（tree）、图（graph）
* 高级：二叉搜索树（binary search tree）[red-black tree、AVL]、堆（heap）、并查集（disjoint set）、字典数（Trie）

### 特殊

* 位运算（Bitwise）、布隆过滤器（BloomFiler）
* LRU Cache

## 算法

* if-else、switch -> brach
* for、while loop -> iteration
* 递归（Recursion）： Divide & Conquer, Backtrace
* 搜索（Search）：深度优先搜索（Depth first search）、广度优先搜索（Breadth first search）
* 动态规划（Dynamic Programming）
* 二分查找（Binary Search）
* 贪心（Greedy）
* 数学（Math）、几何（Geometry）

**注意：根据脑图来想 算法思想 与 代码模板。**

## Leetcode练习步骤

* 1、5~10分钟：读题和思考。
* 2、如有思路，则写代码；不然，看解析。
* 3、默写、熟记
* 4、闭卷写

## 数组、链表、跳表

### 一、数组（Array）

* prepend: O(1)
* append: O(1)
* lookup: O(1)
* insert: O(n)
* delete: O(n)

### 二、链表（Linked List）

prepend: O(1)
append: O(1)
lookup: O(n)
insert: O(1)
delete: O(1)

### 三、跳表（Skip List）[以理解工作原理为主]

* 为了弥补链表的缺陷，即查找复杂度为O(n)。
* 如何提高链表线性查找效率？
  * 升维、空间换时间

* 跳表查询的时间复杂度分析：
  * n/2、n/4、n/8、第k级索引节点的个数为n/(2^k)
  * 假设索引有h级，最高级的索引有2个节点，n/(2^h)=2，从而得到h=log2(n)-1
  * 因此，索引的高度为logn，每层索引最多遍历3个结点
  * 在跳表查询任意数据的时间复杂度为O(logn)

* 跳表的空间复杂度分析：
  * 原始链表大小为n，每2个节点抽取1个，每层索引的结点数：n/2, n/4, n/8, ..., 8, 4, 2
  * 原始链表大小为n，每3个节点抽取1个，每层索引的结点数：n/3, n/9, n/27, ..., 9, 3, 1
  * 空间复杂度为O(n)

### 四、工程中的应用

LRU Cache: Linked List
Redis: Skip List

## 栈、队列、双端队列、优先队列

### 一、栈(Stack)

* 先入后出
* 添加、删除都为O(1)

### 二、队列(Queue)

* 先入先出
* 添加、删除都为O(1)。

### 三、双端队列(Deque)：Double-End Queue

* 双端都可以进出的Queue
* 插入和删除都是O(1)操作

### 四、Stack、Queue、Deque的工程实现

### 五、优先队列(Priority Queue)

* 插入操作：O(1)
* 取出操作：O(logN)-按照元素的优先级取出
* 底层具体实现的数据结构较为多样和复杂：heap、bst、treap
