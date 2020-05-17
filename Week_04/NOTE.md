# 学习笔记

## 深度优先搜索和广度优先搜索

* DFS 代码模板

  * 递归写法

    ```c++
    set<Node *> visited;
    void dfs(Node *root, set<int> &visited) {
        // terminator
        if (visited[root])
            return;

        visited.insert(root);

        for (auto node : root.children) {
            dfs(node, visited);
        }
    }
    ```

  * 非递归写法

    ```c++
    void dfs(Node *root) {
        if (!root)
            return;

        stack<Node*> _stack;
        _stack.push(root);
        while (!_stack.empty()) {
            Node *node = _stack.top();
            _stack.pop();

            process(node);
            for (auto& e : node.children) {
                _stack.push(e);
            }
        }
    }
    ```

* BFS 代码模板

  ```c++
  void bfs(Node *root) {
      if (!root)
          return;

      queue<Node*> _queue;
      _queue.push(root);

      while (!_queue.empty()) {
          Node *node = _queue.front();
          _queue.pop();

          process(node);
          for (auto& e : node.children) {
              _queue.push(e);
          }
      }
  }
  ```

## 贪心算法（Greedy）

* 贪心算法是一种在每一步选择中多采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法
* 贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能

## 二分查找

* 前提

  * 目标函数单调性
  * 存在上下界
  * 能够通过索引访问

* 代码模板

  ```c++
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
          return res;
      } else if (nums[mid] < target) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  ```

* 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
  * 比较 midVa l与左右边界值 leftVal、rightVal
  * 如果 midval > rightVal，说明旋转点在右侧，需要更新做左边界，即 left = mid + 1
  * 否则旋转点在左侧，需要更新做右边界，即 right = mid
