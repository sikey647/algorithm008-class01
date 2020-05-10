# 学习笔记

## 递归（Recursion）

* 递归 -> 循环

* 通过函数体来进行的循环

* 递归代码模版

  ```c++
  void recursion(int level, void param1, void param2, ...) {
      // recursion terminator 递归终止条件
      if (level > MAX_LEVEL) {
          process_result();
          return ;
      }

      // process logic in current level 处理当前层逻辑
      process(level, data, ...);

      // drill down 下探到下一层
      recursion(level + 1, p1, ...);

      # reverse the current level status if needed 清理当前层
  
  }
  ```

* 思维要点

  * 不要人肉进行递归（最大误区）
  * 找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）
  * 数学归纳法

## 分治

* 分治代码模板

  ```c++
  Result DivideConquer(void problem, void param1, void param2, ...) {
      // recursion terminator
      if (!problem) {
          PrintResult();
          return;
      }

      // prepare data
      void data = PrepareData(problem);
      void subProblems = SplitProblem(problem, data);

      // conquer subproblems
      void subResult1 = DivideConquer(subProblems[0], p1, ...);
      void subResult2 = DivideConquer(subProblems[1], p1, ...);
      void subResult3 = DivideConquer(subProblems[2], p1, ...);
      // ...

      // process and generate the final result
      result = ProcessResult(subResult1, subResult2, subResult3, ...)
      return result;
  }
  ```

## 回溯

* 回溯法采用试错的思想，它尝试分步地去解决一个问题。
* 在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效的正确解答时，它将取消上一步甚至是上几步的计算，再通过其它可能的分步解答再次尝试寻找问题的答案。
* 回溯法通常用最简单的递归方案来实现，在反复重复上述的步骤后，可能出现两种情况：
  * 找到一个可能存在的正确答案；
  * 在尝试了所有可能分步的方法后，宣告该问题没有答案；
* 在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。
