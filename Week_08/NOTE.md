# 学习笔记

## 排序算法

### 比较类排序

通过比较来决定元素间的相对次序，由于其时间复杂度不能突破 O(nlogn)，因此也称为非线性时间比较类排序。

* 交换排序
  * 冒泡排序
  * **快速排序**
* 插入排序
  * 简单插入排序
  * 希尔排序
* 选择排序
  * 简单选择排序
  * **堆排序**
* 归并排序
  * **二路并归排序**
  * 多路并归排序

### 非比较类排序

不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。

* 计数排序
* 桶排序
* 基数排序

### 初级排序 O(n^2)

* 选择排序

  每次找最小值，然后放到待排序数组的起始位置。

* 插入排序

  从前到后逐步构建有序序列；

  对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

* 冒泡排序

  嵌套循环，每次查看相邻的元素，如果逆序，则交换。

### 高级排序 O(n*logn)

* 快速排序

  数组取标杆 pivot，将小元素放在 pivot 左边，大元素放在 pivot 右侧，然后依次对左边和右边的子数组继续快排；

  以达到整个序列有序。

  ```c++
  void quickSort(vector<int> &nums, int begin, int end) {
      if (begin > end) return;

      int pivot = partition(nums, begin, end);
      quickSort(nums, begin, pivot - 1);
      quickSort(nums, pivot + 1, end);
  }
  
  int partition(vector<int> &nums, int begin, int end) {
      int pivot = end, counter = begin;
  
      for (int i = 0; i < end; i++) {
          if (nums[i] < nums[pivot]) {
              swap(nums[i], nums[counter]);
              counter++;
          }
      }
  
      swap(nums[counter], nums[pivot]);
  
      return counter;
  }
  ```

* 归并排序 （分治）

  * 把长度为n的输入序列分成两个长度为n/2的子序列；
  * 对这两个子序列分别进行采用归并排序；
  * 将两个排序好的子序列合并成一个最终的排序序列。

  ```c++
  void mergeSort(vector<int> &nums, int left, int right) {
      if (left > right) return;
  
      int mid = (left + right) >> 1;  // (left + right) / 2
      mergeSort(nums, left, mid);
      mergeSort(nums, mid + 1, right);
      merge(nums, left, mid, right);
  }
  
  void merge(vector<int> &nums, int left, int mid, int right) {
      vector<int> temp(right - left + 1);
      int i = left, j = mid + 1, k = 0;
  
      while (i <= mid && j <= right)
          temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
  
      while (i <= mid) temp[k++] = temp[i++];
      while (j <= right) temp[k++] = temp[j++];
  
      for (int p = 0; p < temp.size(); p++) {
          nums[left + p] = temp[p];
      }
  }
  ```

* 快排与归并比较

  * 归并和快排具有相似性，但步骤顺序相反；
  * 归并：先排序左右子数组，然后再合并两个有序子数组；
  * 快排：先分配出左右子数组，然后再对左右子数组进行排序。

* 堆排序

  堆插入 O(logn)，取最大/小值 O(1)

  * 数组元素依次建立小顶堆
  * 依次取堆顶元素，并删除

  ```c++
  void heapSort(vector<int> &nums) {
      priority_queue<int, vector<int>, greater<int> > q;
  
      for (int num : nums) {
          q.push(num);
      }
  
      for (int i = 0; i < nums.size(); i++) {
          nums[i] = q.top();
          q.pop();
      }
  }
  ```
  