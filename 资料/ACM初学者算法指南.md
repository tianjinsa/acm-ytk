# ACM算法指南（零基础详解版）

## 目录
1. [基础数据结构](#基础数据结构)
   - [并查集](#并查集)
   - [单调栈/单调队列](#单调栈和单调队列)
   - [线段树](#线段树)
2. [搜索算法](#搜索算法)
   - [深度优先搜索(DFS)](#深度优先搜索)
   - [广度优先搜索(BFS)](#广度优先搜索)
   - [二分查找](#二分查找)
   - [回溯法](#回溯法)
3. [图论算法](#图论算法)
   - [图的表示](#图的表示)
   - [最短路径算法](#最短路径算法)
   - [最小生成树](#最小生成树)
   - [拓扑排序](#拓扑排序)
4. [动态规划](#动态规划)
   - [动态规划基础](#动态规划基础)
   - [背包问题](#背包问题)
   - [最长公共子序列](#最长公共子序列)
   - [最长递增子序列](#最长递增子序列)
5. [字符串算法](#字符串算法)
   - [字符串匹配](#字符串匹配)
   - [KMP算法](#kmp算法)
   - [字典树(Trie)](#字典树)
6. [数学算法](#数学算法)
   - [素数筛法](#素数筛法)
   - [快速幂](#快速幂)
   - [最大公约数与最小公倍数](#最大公约数与最小公倍数)
7. [高级数据结构](#高级数据结构)
   - [树状数组](#树状数组)
   - [ST表](#st表)
   - [平衡树](#平衡树)
8. [技巧与优化](#技巧与优化)
   - [位运算技巧](#位运算技巧)
   - [STL使用技巧](#stl使用技巧)
   - [常见算法优化思路](#常见算法优化思路)
9. [实战练习指导](#实战练习指导)
    - [如何分析问题](#如何分析问题)
    - [常见解题模板](#常见解题模板)
    - [算法比赛技巧](#算法比赛技巧)

## 基础数据结构

### 并查集

**基本概念**：
并查集(Disjoint Set Union, DSU)是一种树形数据结构，用于高效处理**元素分组**和**查询元素所属组**的问题。

**特点**：
- 可以快速**合并**两个集合
- 可以快速**判断**两个元素是否在同一集合
- 适用于处理无向图的连通性问题

**主要操作**：
- **查找(find)**：确定元素属于哪个集合
- **合并(union)**：将两个集合合并成一个
- **判断(connected)**：判断两个元素是否在同一集合

**基本实现**：
```cpp
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;  // 记录每个节点的父节点
    vector<int> rank;    // 用于按秩合并，优化树的高度
    
public:
    // 初始化n个元素的并查集，每个元素自成一组
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // 初始化，每个元素的父节点是自己
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // 查找操作，返回x所在集合的代表元素（路径压缩）
    int find(int x) {
        // 路径压缩：将x到根节点路径上的所有节点直接连接到根节点
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // 合并操作，将包含x和y的两个集合合并（按秩合并）
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // 如果x和y已经在同一集合中，不需要合并
        if (rootX == rootY) {
            return;
        }
        
        // 按秩合并：将较小的树连接到较大的树下
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // 秩相同时，任选一个作为根，并增加其秩
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    // 判断两个元素是否在同一个集合中
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 10;  // 元素个数
    DisjointSet ds(n);
    
    // 合并一些元素
    ds.unionSets(1, 2);
    ds.unionSets(2, 3);
    ds.unionSets(4, 5);
    ds.unionSets(6, 7);
    ds.unionSets(5, 6);
    
    // 检查连通性
    cout << "1和3是否连通: " << (ds.isConnected(1, 3) ? "是" : "否") << endl;
    cout << "1和4是否连通: " << (ds.isConnected(1, 4) ? "是" : "否") << endl;
    cout << "4和6是否连通: " << (ds.isConnected(4, 6) ? "是" : "否") << endl;
    
    // 再合并一些元素
    ds.unionSets(3, 4);
    
    // 再次检查连通性
    cout << "合并后1和4是否连通: " << (ds.isConnected(1, 4) ? "是" : "否") << endl;
    
    return 0;
}
```

**并查集的优化**：
1. **路径压缩**：在查找操作中，将路径上的所有节点直接连接到根节点，降低树的高度
2. **按秩合并**：总是将较小的树连接到较大的树下，避免树变高

**并查集的应用场景**：
1. **网络连接判断**：判断网络中的节点是否连通
2. **最小生成树的Kruskal算法**：用于判断加入一条边后是否会形成环
3. **等价类划分**：如整数集的等价类划分
4. **动态连通性**：处理动态添加连接的场景

**朋友圈问题示例**：
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 朋友圈问题：给定一个N*N的矩阵M，表示班上N个人的朋友关系。
// 如果M[i][j]=1，表示i和j是朋友，求班上有多少个朋友圈。

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    DisjointSet ds(n);
    
    // 遍历朋友关系矩阵，将朋友关系合并
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1) {
                ds.unionSets(i, j);
            }
        }
    }
    
    // 计算朋友圈数量
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds.find(i) == i) {  // 如果i是集合的代表元素，说明有一个朋友圈
            count++;
        }
    }
    
    return count;
}

int main() {
    // 示例：朋友关系矩阵
    // 1表示两人是朋友，0表示不是
    vector<vector<int>> M = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    cout << "朋友圈数量: " << findCircleNum(M) << endl;  // 应该输出2
    
    return 0;
}
```

### 单调栈和单调队列

#### 单调栈 (Monotonic Stack)

**基本概念**：
单调栈是一种特殊的栈，在这个栈中的元素要么单调递增，要么单调递减。每当新元素入栈时，通过弹出栈中不满足单调性的元素来保持栈的单调性。

**特点**：
- 可以在O(n)时间内解决一类"下一个更大/更小元素"的问题
- 每个元素最多入栈和出栈一次，因此时间复杂度为O(n)

**单调递增栈**：
栈中的元素从栈底到栈顶单调递增。入栈时，如果新元素小于栈顶元素，直接入栈；如果大于或等于栈顶元素，则弹出栈顶元素，直到满足条件或栈为空。

**单调递减栈**：
栈中的元素从栈底到栈顶单调递减。入栈时，如果新元素大于栈顶元素，直接入栈；如果小于或等于栈顶元素，则弹出栈顶元素，直到满足条件或栈为空。

**示例实现 - 下一个更大元素**：
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 找出数组中每个元素的下一个更大元素
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // 初始化为-1，表示没有更大的元素
    stack<int> s;  // 存储元素的索引
    
    for (int i = 0; i < n; i++) {
        // 当栈不为空且当前元素大于栈顶元素时
        // 说明找到了栈顶元素的下一个更大元素
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];  // 记录下一个更大元素
            s.pop();  // 弹出栈顶元素
        }
        s.push(i);  // 将当前元素的索引入栈
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 5, 3};
    vector<int> result = nextGreaterElement(nums);
    
    cout << "原数组: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "下一个更大元素: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}
```

**单调栈的应用场景**：
1. **下一个更大/更小元素**：快速找出数组中每个元素的下一个更大/更小元素
2. **柱状图中最大的矩形**：利用单调栈找出能形成的最大矩形
3. **接雨水问题**：利用单调栈计算能接的雨水量
4. **股票跨度问题**：计算当前股票价格连续多少天小于或等于今天的价格

**柱状图中最大的矩形示例**：
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 计算柱状图中能够形成的最大矩形面积
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;  // 存储柱子的索引
    int maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        // 当到达数组末尾或当前柱子高度小于栈顶柱子高度时
        // 计算以栈顶柱子为高的矩形面积
        while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
            int height = heights[s.top()];
            s.pop();
            
            int width;
            if (s.empty()) {
                width = i;  // 如果栈为空，说明左边没有比它更矮的柱子
            } else {
                width = i - s.top() - 1;  // 右边界i减去左边界s.top()再减1
            }
            
            maxArea = max(maxArea, height * width);
        }
        
        s.push(i);  // 将当前柱子索引入栈
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "柱状图中的最大矩形面积: " << largestRectangleArea(heights) << endl;  // 输出10
    
    return 0;
}
```

#### 单调队列 (Monotonic Queue)

**基本概念**：
单调队列是一种特殊的队列，其中的元素要么单调递增，要么单调递减。与单调栈类似，通过弹出不满足单调性的元素来保持队列的单调性。

**特点**：
- 可以在O(n)时间内解决"滑动窗口最大/最小值"类问题
- 队列头部的元素总是当前窗口中的最大/最小值

**常见操作**：
- **入队**：在保持单调性的前提下添加元素
- **出队**：移除队首元素（如果它是窗口中最早的元素）
- **获取最值**：直接读取队首元素

**示例实现 - 滑动窗口最大值**：
```cpp
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 求滑动窗口中的最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    deque<int> dq;  // 双端队列，存储元素的索引
    
    for (int i = 0; i < n; i++) {
        // 移除队列中不在当前窗口的元素
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // 移除队列中所有小于当前元素的值，保持队列单调递减
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // 将当前元素的索引加入队列
        dq.push_back(i);
        
        // 当窗口大小达到k时，才开始收集结果
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);  // 队首元素是窗口中的最大值
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;  // 窗口大小
    
    vector<int> result = maxSlidingWindow(nums, k);
    
    cout << "原数组: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "大小为" << k << "的滑动窗口最大值: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}
```

**单调队列的详细实现**：
```cpp
#include <iostream>
#include <deque>
using namespace std;

// 单调递减队列（队首元素最大）
class MonotonicQueue {
private:
    deque<int> data;  // 存储元素值
    
public:
    // 入队操作，维持队列单调递减
    void push(int val) {
        // 移除队尾所有小于当前值的元素，保持单调性
        while (!data.empty() && data.back() < val) {
            data.pop_back();
        }
        data.push_back(val);
    }
    
    // 出队操作，仅当队首元素等于val时才移除
    void pop(int val) {
        if (!data.empty() && data.front() == val) {
            data.pop_front();
        }
    }
    
    // 获取队列中的最大值
    int max() {
        if (data.empty()) {
            throw runtime_error("Queue is empty");
        }
        return data.front();
    }
    
    // 队列是否为空
    bool empty() {
        return data.empty();
    }
};

// 使用单调队列解决滑动窗口最大值问题
vector<int> maxSlidingWindowUsingClass(vector<int>& nums, int k) {
    vector<int> result;
    MonotonicQueue q;
    
    for (int i = 0; i < nums.size(); i++) {
        // 添加当前元素
        q.push(nums[i]);
        
        // 窗口还未形成，继续
        if (i < k - 1) continue;
        
        // 窗口形成，获取最大值
        result.push_back(q.max());
        
        // 移除窗口最左边的元素（如果它是最大值）
        q.pop(nums[i - k + 1]);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindowUsingClass(nums, k);
    
    cout << "滑动窗口最大值: ";
    for (int num : result) cout << num << " ";  // 输出: 3 3 5 5 6 7
    cout << endl;
    
    return 0;
}
```

**单调队列的应用场景**：
1. **滑动窗口最大/最小值**：O(n)时间内求解
2. **队列中的最大/最小值**：维护一个有添加和删除操作的队列的最值
3. **最大/最小值差不超过限制的子数组**：使用两个单调队列分别维护最大值和最小值
4. **区间最值查询**：类似于稀疏表的应用但更适合动态数据

**滑动窗口的另一个示例 - 最小值**：
```cpp
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 求滑动窗口中的最小值
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    deque<int> dq;
    
    for (int i = 0; i < n; i++) {
        // 移除不在当前窗口的元素
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // 保持单调递增队列（队首最小）
        while (!dq.empty() && nums[dq.back()] > nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = minSlidingWindow(nums, k);
    
    cout << "滑动窗口最小值: ";
    for (int num : result) cout << num << " ";  // 输出: -1 -3 -3 -3 3 3
    cout << endl;
    
    return 0;
}
```

### 线段树

**基本概念**：
线段树是一种用于处理**区间查询**和**区间更新**问题的树形数据结构。每个节点代表一个区间，根节点代表整个数组区间，叶节点代表单个元素。

**特点**：
- 查询和更新操作的时间复杂度均为O(log n)
- 适用于频繁进行区间查询和更新的场景
- 树的结构能够有效处理区间信息

**线段树支持的操作**：
1. **构建**：根据原始数组构建线段树，O(n)时间
2. **查询**：查询某个区间的聚合值（如和、最大值、最小值等），O(log n)时间
3. **更新**：更新某个元素或区间，O(log n)时间

**线段树实现（区间求和）**：
```cpp
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;  // 存储线段树的数组
    vector<int> lazy;  // 懒标记数组，用于延迟更新
    vector<int> arr;   // 原始数组
    int n;            // 原始数组大小
    
    // 构建线段树
    void build(int node, int start, int end) {
        if (start == end) {
            // 叶节点，直接存储原始数组中的值
            tree[node] = arr[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;   // 左子节点的索引
        int rightNode = 2 * node + 2;  // 右子节点的索引
        
        // 递归构建左右子树
        build(leftNode, start, mid);
        build(rightNode, mid + 1, end);
        
        // 当前节点的值是两个子节点值的和
        tree[node] = tree[leftNode] + tree[rightNode];
    }
    
    // 处理懒标记，将更新传递给子节点
    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            // 更新当前节点的值
            tree[node] += lazy[node] * (end - start + 1);
            
            // 如果不是叶节点，将懒标记传递给子节点
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            
            // 清除当前节点的懒标记
            lazy[node] = 0;
        }
    }
    
    // 区间查询的内部实现
    int queryRange(int node, int start, int end, int left, int right) {
        // 先处理懒标记
        updateLazy(node, start, end);
        
        // 当前区间完全在查询区间外
        if (start > right || end < left) {
            return 0;
        }
        
        // 当前区间完全在查询区间内
        if (left <= start && end <= right) {
            return tree[node];
        }
        
        // 部分重反，需要进一步查询子区间
        int mid = start + (end - start) / 2;
        int leftSum = queryRange(2 * node + 1, start, mid, left, right);
        int rightSum = queryRange(2 * node + 2, mid + 1, end, left, right);
        
        return leftSum + rightSum;
    }
    
    // 单点更新的内部实现
    void updatePoint(int node, int start, int end, int idx, int val) {
        // 找到对应的叶节点
        if (start == end) {
            arr[idx] = val;  // 更新原始数组
            tree[node] = val;  // 更新线段树节点
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        
        // 根据idx位置决定更新左子树还是右子树
        if (idx <= mid) {
            updatePoint(leftNode, start, mid, idx, val);
        } else {
            updatePoint(rightNode, mid + 1, end, idx, val);
        }
        
        // 更新当前节点的值
        tree[node] = tree[leftNode] + tree[rightNode];
    }
    
    // 区间更新的内部实现（范围增加值）
    void updateRange(int node, int start, int end, int left, int right, int val) {
        // 先处理当前节点的懒标记
        updateLazy(node, start, end);
        
        // 当前区间完全在更新区间外
        if (start > right || end < left) {
            return;
        }
        
        // 当前区间完全在更新区间内，直接更新当前节点并添加懒标记
        if (left <= start && end <= right) {
            tree[node] += val * (end - start + 1);
            
            // 如果不是叶节点，为子节点添加懒标记
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            
            return;
        }
        
        // 部分重反，递归更新子区间
        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, left, right, val);
        updateRange(2 * node + 2, mid + 1, end, left, right, val);
        
        // 更新当前节点的值
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
public:
    // 构造函数，初始化线段树
    SegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        // 线段树数组大小至少为4n
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        
        // 构建线段树
        build(0, 0, n - 1);
    }
    
    // 公开的查询接口
    int query(int left, int right) {
        return queryRange(0, 0, n - 1, left, right);
    }
    
    // 公开的单点更新接口
    void update(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
    
    // 公开的区间更新接口（区间内所有元素增加val）
    void updateRange(int left, int right, int val) {
        updateRange(0, 0, n - 1, left, right, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);
    
    // 查询区间和
    cout << "区间[1,3]的和: " << segTree.query(1, 3) << endl;  // 输出: 15 (3+5+7)
    
    // 更新单点值
    segTree.update(2, 10);  // 将arr[2]从5更新为10
    cout << "更新后区间[1,3]的和: " << segTree.query(1, 3) << endl;  // 输出: 20 (3+10+7)
    
    // 区间更新
    segTree.updateRange(0, 2, 2);  // 区间[0,2]中每个元素增加2
    cout << "区间更新后[0,2]的和: " << segTree.query(0, 2) << endl;  // 输出: 18 (3+5+10)
    
    return 0;
}
```

**线段树的其他变种 - 区间最值**：
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 实现区间最大值查询的线段树
class MaxSegmentTree {
private:
    vector<int> tree;  // 存储线段树的数组
    vector<int> arr;   // 原始数组
    int n;            // 原始数组大小
    
    // 构建线段树
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        
        build(leftNode, start, mid);
        build(rightNode, mid + 1, end);
        
        // 当前节点的值是两个子节点中的较大值
        tree[node] = max(tree[leftNode], tree[rightNode]);
    }
    
    // 区间查询的内部实现
    int queryMax(int node, int start, int end, int left, int right) {
        // 当前区间完全在查询区间外
        if (start > right || end < left) {
            return INT_MIN;  // 返回一个极小值
        }
        
        // 当前区间完全在查询区间内
        if (left <= start && end <= right) {
            return tree[node];
        }
        
        // 部分重反，需要进一步查询子区间
        int mid = start + (end - start) / 2;
        int leftMax = queryMax(2 * node + 1, start, mid, left, right);
        int rightMax = queryMax(2 * node + 2, mid + 1, end, left, right);
        
        return max(leftMax, rightMax);
    }
    
    // 单点更新的内部实现
    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        
        if (idx <= mid) {
            updatePoint(2 * node + 1, start, mid, idx, val);
        } else {
            updatePoint(2 * node + 2, mid + 1, end, idx, val);
        }
        
        // 更新当前节点的值
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
public:
    MaxSegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        
        build(0, 0, n - 1);
    }
    
    int queryMax(int left, int right) {
        return queryMax(0, 0, n - 1, left, right);
    }
    
    void update(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    MaxSegmentTree segTree(arr);
    
    // 查询区间最大值
    cout << "区间[1,4]的最大值: " << segTree.queryMax(1, 4) << endl;  // 输出: 9
    
    // 更新单点值
    segTree.update(2, 10);  // 将arr[2]从5更新为10
    cout << "更新后区间[1,4]的最大值: " << segTree.queryMax(1, 4) << endl;  // 输出: 10
    
    return 0;
}
```

**线段树的应用场景**：
1. **区间查询**：如求和、最大/最小值、乘积等
2. **区间更新**：单点更新或区间批量更新
3. **动态规划优化**：某些DP问题可以用线段树优化查询操作
4. **计算几何**：处理一维区间重叠问题
5. **范围搜索**：在排序数组中查找符合条件的范围

**线段树与其他数据结构的对比**：
1. **线段树vs树状数组**：线段树更通用，支持更多种类的查询；树状数组实现更简单，内存占用更少
2. **线段树vsST表**：线段树支持动态更新；ST表只支持静态查询但速度更快
3. **线段树vs平衡树**：线段树专注于区间操作；平衡树更适合有序集合的操作

**实际应用示例 - 区间最大子数组和**：
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 线段树节点存储区间信息
struct Node {
    int sum;      // 区间和
    int maxSum;   // 区间内的最大子数组和
    int prefixSum; // 从左端点开始的最大前缀和
    int suffixSum; // 到右端点结束的最大后缀和
};

class SegmentTree {
private:
    vector<Node> tree;
    vector<int> arr;
    int n;
    
    // 合并两个节点的结果
    Node merge(const Node& left, const Node& right) {
        Node result;
        result.sum = left.sum + right.sum;
        result.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
        result.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
        result.maxSum = max(max(left.maxSum, right.maxSum), left.suffixSum + right.prefixSum);
        
        return result;
    }
    
    // 构建线段树
    void build(int node, int start, int end) {
        if (start == end) {
            // 叶节点，初始化
            tree[node].sum = arr[start];
            tree[node].maxSum = arr[start];
            tree[node].prefixSum = arr[start];
            tree[node].suffixSum = arr[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        
        build(leftNode, start, mid);
        build(rightNode, mid + 1, end);
        
        // 合并两个子节点的信息
        tree[node] = merge(tree[leftNode], tree[rightNode]);
    }
    
    // 区间查询
    Node query(int node, int start, int end, int left, int right) {
        // 完全不重反
        if (start > right || end < left) {
            // 返回不影响合并结果的值
            Node nullNode;
            nullNode.sum = 0;
            nullNode.maxSum = INT_MIN;
            nullNode.prefixSum = INT_MIN;
            nullNode.suffixSum = INT_MIN;
            return nullNode;
        }
        
        // 完全重反
        if (left <= start && end <= right) {
            return tree[node];
        }
        
        // 部分重反
        int mid = start + (end - start) / 2;
        Node leftResult = query(2 * node + 1, start, mid, left, right);
        Node rightResult = query(2 * node + 2, mid + 1, end, left, right);
        
        // 合并结果
        if (leftResult.maxSum == INT_MIN) return rightResult;
        if (rightResult.maxSum == INT_MIN) return leftResult;
        
        return merge(leftResult, rightResult);
    }
    
public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        
        build(0, 0, n - 1);
    }
    
    int queryMaxSubarraySum(int left, int right) {
        return query(0, 0, n - 1, left, right).maxSum;
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    SegmentTree segTree(arr);
    
    // 查询区间[0,8]内的最大子数组和
    cout << "区间[0,8]的最大子数组和: " << segTree.queryMaxSubarraySum(0, 8) << endl;  // 输出: 6
    
    // 查询区间[3,7]内的最大子数组和
    cout << "区间[3,7]的最大子数组和: " << segTree.queryMaxSubarraySum(3, 7) << endl;  // 输出: 6
    
    return 0;
}
```

**总结**：
线段树是一种功能强大的数据结构，特别适合解决区间查询和更新问题。虽然实现稍显复杂，但它的高效率和灵活性使其成为竞争性编程中的重要工具。通过在构建树时预计算区间信息，线段树能够在对数时间内完成查询和更新操作，大大提高了算法的效率。

## 搜索算法

### 深度优先搜索

**基本概念**：
深度优先搜索(DFS)是一种图形搜索算法，它沿着一条路径尽可能深入地搜索，直到无法继续前进时才回溯到上一个节点，尝试另一条路径。

**算法思想**：
1. 从起点开始，选择一条路径前进
2. 沿着这条路径一直走到无法继续（叶节点或已访问的节点）
3. 回溯到上一个节点，选择另一条未探索的路径继续
4. 重复2-3步，直到遍历完整个图

**实现方式**：
DFS通常使用递归或栈实现。由于递归本质上使用了系统栈，两种方式本质相同。

**比赛中的DFS模板（递归版）**：
```cpp
// 使用邻接表表示图
vector<vector<int>> graph; // graph[u]表示顶点u的所有邻接点
vector<bool> visited;      // 标记节点是否被访问过

void dfs(int u) {
    // 标记当前节点已访问
    visited[u] = true;
    cout << "访问节点: " << u << endl; // 处理当前节点
    
    // 访问所有未访问过的邻接节点
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    // 回溯前的操作（如果需要）
}

// 在main函数中调用
void solve() {
    int n = 5; // 节点数量
    graph.resize(n);
    visited.resize(n, false);
    
    // 添加边
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    
    // 从节点0开始DFS
    dfs(0);
}
```

**迷宫问题DFS实现**：
```cpp
// 迷宫问题：找到从起点到终点的路径
// 0表示空地，1表示墙壁
int maze[100][100];
int n, m; // 迷宫大小
bool visited[100][100]; // 访问标记
bool found = false; // 是否找到路径

// 四个方向：上、右、下、左
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 检查坐标是否有效
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}

void dfs(int x, int y, int endX, int endY) {
    // 如果已经找到路径，或已经到达终点，则返回
    if (found || (x == endX && y == endY)) {
        found = true;
        cout << "找到从(" << x << "," << y << ")到终点的路径!" << endl;
        return;
    }
    
    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (isValid(nx, ny)) {
            visited[nx][ny] = true; // 标记为已访问
            dfs(nx, ny, endX, endY); // 递归搜索
            
            // 如果已经找到路径，不需要回溯
            if (found) return;
            
            // 否则回溯
            // visited[nx][ny] = false; // 取消注释以获取所有可能的路径
        }
    }
}

// 在比赛中使用
void solve() {
    cin >> n >> m;
    
    // 读入迷宫
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }
    
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    visited[startX][startY] = true;
    dfs(startX, startY, endX, endY);
    
    if (!found) {
        cout << "没有找到路径!" << endl;
    }
}
```

**DFS优化技巧**：
1. **剪枝**：通过判断当前状态是否有必要继续搜索，减少搜索空间。
2. **记忆化**：存储已计算的状态，避免重复计算。
3. **状态压缩**：使用位运算表示状态，节省空间和时间。
4. **启发式搜索**：优先搜索更有可能得到解的分支。

**记忆化DFS示例（计算到达每个点的路径数）**：
```cpp
// 计算从起点到每个点的路径数
vector<vector<int>> graph;
vector<int> memo; // 记忆数组，-1表示未计算

// 记忆化DFS计算从start到end的路径数
int dfs(int u, int end) {
    // 已经到达终点
    if (u == end) return 1;
    
    // 已经计算过，直接返回结果
    if (memo[u] != -1) return memo[u];
    
    int paths = 0;
    // 遍历所有邻接点
    for (int v : graph[u]) {
        paths += dfs(v, end);
    }
    
    // 存储结果
    memo[u] = paths;
    return paths;
}

// 初始化并调用
void solve() {
    int n, m; // n个节点，m条边
    cin >> n >> m;
    
    graph.resize(n);
    memo.assign(n, -1);
    
    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    int start = 0, end = n - 1;
    cout << "路径数: " << dfs(start, end) << endl;
}
```

**应用场景**：
1. 寻找所有可能的解（排列、组合、子集等）
2. 连通块问题（找出图中所有连通的部分）
3. 拓扑排序
4. 环检测
5. 二叉树遍历（前序、中序、后序）

### 广度优先搜索

**基本概念**：
广度优先搜索(BFS)是一种图形搜索算法，它逐层扩展，首先访问起点的所有邻接点，然后再访问下一层，以此类推。

**算法思想**：
1. 从起点开始，将起点加入队列
2. 访问队列中的第一个节点，并将其未访问过的邻接点加入队列
3. 重复第2步，直到队列为空

**实现方式**：
BFS通常使用队列实现。

**比赛中的BFS模板**：
```cpp
// 使用邻接表表示图
vector<vector<int>> graph; // graph[u]表示顶点u的所有邻接点
vector<bool> visited;      // 标记节点是否被访问过
vector<int> distance;      // 记录从起点到每个节点的距离

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // 处理当前节点
        cout << "访问节点: " << u << ", 距离: " << distance[u] << endl;
        
        // 将所有未访问的邻接点加入队列
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1; // 更新距离
                q.push(v);
            }
        }
    }
}

// 在比赛中使用
void solve() {
    int n = 5; // 节点数量
    graph.resize(n);
    visited.resize(n, false);
    distance.resize(n, -1);
    
    // 添加边
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(3);
    
    // 从节点0开始BFS
    bfs(0);
}
```

**迷宫问题BFS实现（最短路径）**：
```cpp
// 迷宫问题：找到从起点到终点的最短路径
// 0表示空地，1表示墙壁
int maze[100][100];
int n, m; // 迷宫大小
bool visited[100][100]; // 访问标记
int distance[100][100]; // 距离

// 四个方向：上、右、下、左
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 检查坐标是否有效
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    distance[startX][startY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

// 在比赛中使用
void solve() {
    cin >> n >> m;
    
    // 读入迷宫
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
            distance[i][j] = -1;
        }
    }
    
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    bfs(startX, startY);
    
    if (distance[endX][endY] != -1) {
        cout << "最短路径长度: " << distance[endX][endY] << endl;
    } else {
        cout << "没有找到路径!" << endl;
    }
}
```

**多源BFS（求每个点到最近污染源的距离）**：
```cpp
// 多源BFS：求每个点到最近污染源的距离
int grid[100][100]; // 0表示空地，1表示污染源
int n, m; // 网格大小
int dist[100][100]; // 距离
bool visited[100][100]; // 访问标记

// 四个方向：上、右、下、左
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 多源BFS
void multiBFS() {
    queue<pair<int, int>> q;
    
    // 先将所有污染源加入队列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
                dist[i][j] = 0; // 污染源距离为0
            }
        }
    }
    
    // BFS扩展
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

// 在比赛中使用
void solve() {
    cin >> n >> m;
    
    // 读入网格
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
            dist[i][j] = -1;
        }
    }
    
    multiBFS();
    
    // 输出每个点到最近污染源的距离
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
```

**BFS优化技巧**：
1. **方向数组**：使用dx/dy数组简化方向遍历。
2. **双端队列优化**：某些情况下，可以使用deque代替queue，优先处理某些情况。
3. **A*算法**：结合启发式函数，优先扩展更有希望的状态。
4. **状态压缩**：使用位运算表示状态，节省空间和时间。

**应用场景**：
1. 寻找最短路径（无权图）
2. 连通性问题
3. 拓扑排序
4. 层次遍历（如二叉树的层序遍历）
5. 网络爬虫（Web爬虫）

### 二分查找

**基本概念**：
二分查找是一种在有序数组中查找特定元素的高效算法。每次将查找区间分成两半，通过判断中间元素与目标元素的大小关系，舍弃一半区间。

**算法思想**：
1. 选择有序数组的中间元素
2. 将目标值与中间元素比较
3. 如果目标值等于中间元素，查找成功
4. 如果目标值小于中间元素，在左半部分继续查找
5. 如果目标值大于中间元素，在右半部分继续查找
6. 重复2-5步，直到找到目标值或区间为空

**比赛中的二分查找模板（基础版）**：
```cpp
// 在有序数组中查找目标值，返回索引，不存在则返回-1
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止整数溢出
        
        if (nums[mid] == target) {
            return mid; // 找到目标值
        } else if (nums[mid] < target) {
            left = mid + 1; // 在右半部分继续查找
        } else {
            right = mid - 1; // 在左半部分继续查找
        }
    }
    
    return -1; // 未找到
}
```

**查找第一个大于等于目标值的位置（lower_bound）**：
```cpp
// 查找第一个大于等于target的元素的索引
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // 注意right设为nums.size()
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] >= target) {
            right = mid; // 可能是解，继续在左半部分查找
        } else {
            left = mid + 1; // 在右半部分查找
        }
    }
    
    // left等于right时退出循环，如果数组中存在>=target的值，则left指向第一个
    return left < nums.size() ? left : -1;
}
```

**查找第一个大于目标值的位置（upper_bound）**：
```cpp
// 查找第一个大于target的元素的索引
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // 注意right设为nums.size()
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > target) {
            right = mid; // 可能是解，继续在左半部分查找
        } else {
            left = mid + 1; // 在右半部分查找
        }
    }
    
    // left等于right时退出循环，如果数组中存在>target的值，则left指向第一个
    return left < nums.size() ? left : -1;
}
```

**二分查找浮点数（查找平方根）**：
```cpp
// 计算x的平方根（精确到1e-6）
double sqrt(double x) {
    if (x <= 0) return 0;
    
    double left = 0, right = x;
    
    // 当区间足够小时停止
    while (right - left > 1e-6) {
        double mid = left + (right - left) / 2;
        
        if (mid * mid > x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return left;
}
```

**二分答案（最大值最小化问题）**：
```cpp
// 二分答案：找到满足某条件的最大/最小值
// 例：在数组中找出最小的值h，使得所有数除以h的和不超过m

// 检查是否满足条件
bool check(vector<int>& nums, int h, int m) {
    int sum = 0;
    for (int num : nums) {
        sum += (num + h - 1) / h; // 向上取整
        if (sum > m) return false;
    }
    return true;
}

// 主函数
int minMaxDivision(vector<int>& nums, int m) {
    // 二分查找的左右边界
    int left = 1; // 最小可能值
    int right = *max_element(nums.begin(), nums.end()); // 最大可能值
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (check(nums, mid, m)) {
            // mid可能是解，继续尝试更小的值
            right = mid;
        } else {
            // mid不满足条件，必须尝试更大的值
            left = mid + 1;
        }
    }
    
    return left;
}
```

**二分查找优化技巧**：
1. **避免整数溢出**：使用`mid = left + (right - left) / 2`而不是`mid = (left + right) / 2`。
2. **选择合适的循环条件**：`while (left <= right)`用于查找特定值，`while (left < right)`用于找边界。
3. **边界处理**：注意索引的边界条件，特别是当目标不存在时的返回值。
4. **浮点数二分**：对于浮点数，通过区间大小控制精度。

**应用场景**：
1. 在有序数组中查找元素
2. 求解单调函数的零点
3. 二分答案（在答案空间中二分查找）
4. 近似计算（如平方根、立方根等）
5. 资源分配（如尽可能平均地分配资源）

### 回溯法

**基本概念**：
回溯法是一种通过系统地尝试所有可能的解来解决问题的算法。它通过构建解的一部分，然后检查它是否能扩展成完整的解，如果不能则"回溯"并尝试其他路径。

**算法思想**：
1. 选择：在当前位置做出一个选择
2. 约束：检查这个选择是否满足问题的约束条件
3. 目标：检查是否已经达到问题的目标
4. 递归：如果选择合法但未达到目标，则递归探索下一步
5. 回溯：如果当前路径无法得到解，则回退到上一步，尝试其他选择

**比赛中的回溯模板（求子集）**：
```cpp
// 求数组的所有子集
vector<vector<int>> result; // 存储所有子集
vector<int> current;        // 当前构建的子集

void backtrack(vector<int>& nums, int start) {
    // 每个状态都是一个有效的子集，直接添加
    result.push_back(current);
    
    // 从start开始，避免重复
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        current.push_back(nums[i]);
        
        // 递归到下一层
        backtrack(nums, i + 1);
        
        // 回溯，撤销选择
        current.pop_back();
    }
}

// 在比赛中调用
void solve() {
    vector<int> nums = {1, 2, 3};
    backtrack(nums, 0);
    
    // 输出所有子集
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}
```

**求排列的回溯实现**：
```cpp
// 求数组的所有排列
vector<vector<int>> result; // 存储所有排列
vector<int> current;        // 当前构建的排列
vector<bool> used;          // 标记元素是否已使用

void backtrack(vector<int>& nums) {
    // 如果当前排列长度等于数组长度，加入结果
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        // 如果元素已使用，跳过
        if (used[i]) continue;
        
        // 做选择
        current.push_back(nums[i]);
        used[i] = true;
        
        // 递归到下一层
        backtrack(nums);
        
        // 回溯，撤销选择
        current.pop_back();
        used[i] = false;
    }
}

// 在比赛中调用
void solve() {
    vector<int> nums = {1, 2, 3};
    used.resize(nums.size(), false);
    backtrack(nums);
    
    // 输出所有排列
    for (const auto& perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}
```

**N皇后问题**：
```cpp
// N皇后问题：在N×N的棋盘上放置N个皇后，使得它们互不攻击
int n;                      // 棋盘大小
vector<vector<string>> result; // 存储所有可行解
vector<string> board;         // 当前棋盘状态

// 检查在(row,col)位置放置皇后是否安全
bool isSafe(int row, int col) {
    // 检查列
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    // 检查左上对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // 检查右上对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void backtrack(int row) {
    // 如果已经放置了n个皇后，将当前解加入结果
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            // 做选择
            board[row][col] = 'Q';
            
            // 递归处理下一行
            backtrack(row + 1);
            
            // 回溯，撤销选择
            board[row][col] = '.';
        }
    }
}

// 在比赛中调用
void solve() {
    cin >> n;
    
    // 初始化棋盘
    board.resize(n, string(n, '.'));
    
    backtrack(0);
    
    cout << "共找到" << result.size() << "种解法" << endl;
    
    // 输出第一个解（如果存在）
    if (!result.empty()) {
        cout << "第一个解：" << endl;
        for (const string& row : result[0]) {
            cout << row << endl;
        }
    }
}
```

**回溯法优化技巧**：
1. **剪枝**：尽早判断无效分支，避免不必要的探索。
2. **排序**：在某些问题中，先对输入数据排序可以帮助更早地剪枝。
3. **位运算**：对于如N皇后等问题，可以使用位运算加速冲突检测。
4. **存储中间结果**：在某些问题中，可以存储和重用中间计算结果。

**应用场景**：
1. 组合问题：从n个数中选k个的所有可能组合
2. 排列问题：n个数的所有可能排列
3. 子集问题：求一个集合的所有子集
4. 搜索问题：如迷宫求解、单词搜索
5. 约束满足问题：如数独、N皇后
6. 分割问题：将字符串分割成满足特定条件的部分

## 字符串算法

### 字符串匹配

**基本概念**：
字符串匹配是在文本串中查找模式串出现位置的过程。给定文本串T和模式串P，目标是找出T中所有P出现的起始位置。

**朴素字符串匹配算法**：
最直观的方法是将模式串P与文本串T的每个可能位置进行比较。

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 朴素字符串匹配算法
// 时间复杂度：O(n*m)，其中n是文本串长度，m是模式串长度
vector<int> naiveStringMatch(string text, string pattern) {
    vector<int> positions; // 存储模式串出现的所有位置
    int n = text.length();
    int m = pattern.length();
    
    // 枚举文本串中每个可能的起始位置
    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        
        // 从当前位置开始，逐字符比较
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break; // 不匹配，直接退出内层循环
            }
        }
        
        // 如果完全匹配，记录位置
        if (match) {
            positions.push_back(i);
        }
    }
    
    return positions;
}

// 在比赛中使用
void solve() {
    string text = "ABABCABABCABCABC";
    string pattern = "ABC";
    
    vector<int> matches = naiveStringMatch(text, pattern);
    
    cout << "模式串出现在以下位置：";
    for (int pos : matches) {
        cout << pos << " "; // 输出：2 7 10 13
    }
    cout << endl;
}
```

### KMP算法

**基本概念**：
KMP（Knuth-Morris-Pratt）算法是一种高效的字符串匹配算法，通过预处理模式串，避免不必要的比较，从而将时间复杂度降低到O(n+m)。

**算法核心思想**：
1. 预处理模式串，计算"部分匹配表"（也称为"失败函数"或"next数组"）
2. 当匹配失败时，利用部分匹配表快速移动模式串，跳过已知不匹配的部分

**部分匹配表的含义**：
部分匹配表记录了模式串中每个位置的"前缀"和"后缀"的最长共有元素长度。当匹配失败时，这个信息可以帮助我们知道模式串应该向右移动多少位。

**KMP算法的实现**：

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 计算部分匹配表（next数组）
// next[i]表示P[0...i-1]的前缀和后缀的最长公共部分长度
vector<int> computeLPSArray(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // lps: Longest Prefix Suffix
    
    // lps[0]总是0
    int len = 0; // 前一个位置的lps值
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            // 如果当前字符匹配
            len++; // 增加匹配长度
            lps[i] = len; // 设置lps[i]为当前匹配长度
            i++; // 移动到下一个位置
        } else {
            if (len != 0) {
                // 如果有部分匹配，回退到上一个匹配位置
                len = lps[len - 1];
                // 注意：这里不增加i，因为我们需要重新比较
            } else {
                // 完全不匹配，lps[i]设为0
                lps[i] = 0;
                i++; // 移动到下一个位置
            }
        }
    }
    
    return lps;
}

// KMP算法实现
// 时间复杂度：O(n+m)，其中n是文本串长度，m是模式串长度
vector<int> KMPSearch(string text, string pattern) {
    vector<int> positions; // 存储模式串出现的所有位置
    int n = text.length();
    int m = pattern.length();
    
    // 如果模式串为空，直接返回
    if (m == 0) return positions;
    
    // 计算部分匹配表
    vector<int> lps = computeLPSArray(pattern);
    
    int i = 0; // 文本串中当前位置
    int j = 0; // 模式串中当前位置
    
    while (i < n) {
        // 当前字符匹配
        if (pattern[j] == text[i]) {
            j++; // 移动模式串指针
            i++; // 移动文本串指针
        }
        
        // 找到一个完全匹配
        if (j == m) {
            positions.push_back(i - j); // 记录模式串起始位置
            j = lps[j - 1]; // 跳转到部分匹配位置继续搜索
        }
        // 当前字符不匹配
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                // 部分匹配，根据lps跳转
                j = lps[j - 1];
            } else {
                // 完全不匹配，移动文本串指针
                i++;
            }
        }
    }
    
    return positions;
}

// 在比赛中使用
void solveKMP() {
    string text = "ABABCABABCABCABC";
    string pattern = "ABABC";
    
    vector<int> matches = KMPSearch(text, pattern);
    
    cout << "模式串出现在以下位置：";
    for (int pos : matches) {
        cout << pos << " "; // 输出：0 5
    }
    cout << endl;
    
    // 部分匹配表（lps数组）的解释
    vector<int> lps = computeLPSArray(pattern);
    cout << "模式串 " << pattern << " 的部分匹配表：";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " "; // 输出：0 0 1 2 0
    }
    cout << endl;
    
    cout << "解释：" << endl;
    cout << "lps[0] = 0: 单个字符没有前后缀" << endl;
    cout << "lps[1] = 0: \"AB\"的前缀和后缀没有匹配" << endl;
    cout << "lps[2] = 1: \"ABA\"的前缀A和后缀A匹配，长度为1" << endl;
    cout << "lps[3] = 2: \"ABAB\"的前缀AB和后缀AB匹配，长度为2" << endl;
    cout << "lps[4] = 0: \"ABABC\"的前缀和后缀没有匹配" << endl;
}
```

**复杂度分析**：
- 时间复杂度：O(n+m)，其中n是文本串长度，m是模式串长度
- 空间复杂度：O(m)，存储部分匹配表

**与朴素算法对比**：
| 算法 | 时间复杂度 | 预处理 | 适用场景 |
|------|------------|--------|----------|
| 朴素算法 | O(n*m) | 不需要 | 短文本和模式串 |
| KMP算法 | O(n+m) | 需要O(m)时间预处理 | 长文本和模式串 |

**KMP算法的关键点**：
1. **理解部分匹配表**：掌握lps数组的计算和意义
2. **匹配失败时的移动**：通过lps数组确定模式串应该移动到哪个位置
3. **预处理的重要性**：KMP的高效来源于对模式串的预处理

### 字典树(Trie)

**基本概念**：
字典树，又称前缀树，是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用，如自动补全和拼写检查。

**特点**：
- 每个节点包含多个子节点，每个子节点对应一个字符
- 从根节点到某一节点的路径上经过的字符连接起来，就是该节点对应的字符串
- 所有以同一个前缀开始的字符串，在字典树中有共同的前缀路径

**字典树的核心操作**：
1. **插入**：将一个单词添加到字典树中
2. **查找**：查询单词是否在字典树中
3. **前缀搜索**：查找具有特定前缀的所有单词

**竞赛中的Trie实现（使用数组）**：

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 字典树实现，使用数组（适用于只包含小写字母的情况）
const int ALPHABET_SIZE = 26; // 小写字母
const int MAX_NODES = 100000; // 最大节点数，根据题目调整

// 字典树节点
struct TrieNode {
    int children[ALPHABET_SIZE]; // 子节点在数组中的索引
    bool isEndOfWord;           // 标记当前节点是否是单词结尾
};

// 全局变量（在比赛中常用）
TrieNode trie[MAX_NODES];  // 存储所有节点的数组
int nodeCount;            // 当前已使用的节点数

// 初始化字典树
void initTrie() {
    // 初始化根节点
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        trie[0].children[i] = -1; // -1表示没有子节点
    }
    trie[0].isEndOfWord = false;
    nodeCount = 1; // 根节点为第一个节点
}

// 创建新节点
int createNode() {
    // 确保不会超出数组范围
    if (nodeCount >= MAX_NODES) {
        cout << "Trie节点已满！" << endl;
        return -1;
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        trie[nodeCount].children[i] = -1;
    }
    trie[nodeCount].isEndOfWord = false;
    return nodeCount++; // 返回新节点的索引，并增加节点计数
}

// 在字典树中插入一个单词
void insert(string word) {
    int current = 0; // 从根节点开始
    
    for (char c : word) {
        int index = c - 'a'; // 将字符转换为0-25的索引
        
        // 如果当前路径不存在，创建新节点
        if (trie[current].children[index] == -1) {
            trie[current].children[index] = createNode();
        }
        
        // 移动到下一个节点
        current = trie[current].children[index];
    }
    
    // 标记单词结尾
    trie[current].isEndOfWord = true;
}

// 在字典树中查找一个单词
bool search(string word) {
    int current = 0; // 从根节点开始
    
    for (char c : word) {
        int index = c - 'a';
        
        // 如果路径不存在，单词不在字典树中
        if (trie[current].children[index] == -1) {
            return false;
        }
        
        // 移动到下一个节点
        current = trie[current].children[index];
    }
    
    // 检查是否是单词结尾
    return trie[current].isEndOfWord;
}

// 检查字典树中是否存在以给定前缀开始的单词
bool startsWith(string prefix) {
    int current = 0; // 从根节点开始
    
    for (char c : prefix) {
        int index = c - 'a';
        
        // 如果路径不存在，没有以此前缀开始的单词
        if (trie[current].children[index] == -1) {
            return false;
        }
        
        // 移动到下一个节点
        current = trie[current].children[index];
    }
    
    // 前缀存在
    return true;
}

// 统计字典树中单词总数（为了展示DFS遍历）
int countWords() {
    // 使用DFS计算单词数量
    vector<bool> visited(nodeCount, false);
    int count = 0;
    
    function<void(int)> dfs = [&](int node) {
        if (visited[node]) return;
        visited[node] = true;
        
        if (trie[node].isEndOfWord) {
            count++;
        }
        
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (trie[node].children[i] != -1) {
                dfs(trie[node].children[i]);
            }
        }
    };
    
    dfs(0); // 从根节点开始遍历
    return count;
}

// 在比赛中使用
void solveTrie() {
    initTrie();
    
    // 插入单词
    vector<string> words = {"apple", "app", "banana", "ball", "bat"};
    for (const string& word : words) {
        insert(word);
    }
    
    // 查找单词
    cout << "字典树中的单词数量：" << countWords() << endl; // 输出：5
    
    cout << "查找结果：" << endl;
    cout << "apple: " << (search("apple") ? "存在" : "不存在") << endl;   // 存在
    cout << "app: " << (search("app") ? "存在" : "不存在") << endl;       // 存在
    cout << "ap: " << (search("ap") ? "存在" : "不存在") << endl;         // 不存在
    cout << "banana: " << (search("banana") ? "存在" : "不存在") << endl; // 存在
    cout << "ban: " << (search("ban") ? "存在" : "不存在") << endl;       // 不存在
    
    cout << "前缀查找结果：" << endl;
    cout << "app前缀: " << (startsWith("app") ? "存在" : "不存在") << endl;   // 存在
    cout << "ban前缀: " << (startsWith("ban") ? "存在" : "不存在") << endl;   // 存在
    cout << "cat前缀: " << (startsWith("cat") ? "存在" : "不存在") << endl;   // 不存在
}
```

**字典树的应用示例 - 最长公共前缀**：

```cpp
// 查找字符串数组中所有字符串的最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
    // 如果字符串数组为空，返回空字符串
    if (strs.empty()) return "";
    
    // 初始化字典树
    initTrie();
    
    // 插入第一个字符串
    for (char c : strs[0]) {
        int current = 0;
        int index = c - 'a';
        
        if (trie[current].children[index] == -1) {
            trie[current].children[index] = createNode();
        }
        
        current = trie[current].children[index];
    }
    trie[current].isEndOfWord = true;
    
    // 寻找最长公共前缀
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        int current = 0;
        
        // 尽可能深入地遍历，直到不匹配或达到单词末尾
        while (j < strs[i].size() && current != -1) {
            int index = strs[i][j] - 'a';
            if (trie[current].children[index] == -1) {
                break;
            }
            current = trie[current].children[index];
            j++;
        }
        
        // 更新最长公共前缀
        if (j < prefix.size()) {
            prefix = prefix.substr(0, j);
        }
    }
    
    return prefix;
}

// 在比赛中使用
void solveLCP() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "最长公共前缀：" << longestCommonPrefix(strs) << endl; // 输出："fl"
}
```

**字典树的其他应用**：
1. **自动补全**：根据用户输入的前缀，推荐可能的完整单词
2. **拼写检查**：检查单词是否存在于词典中
3. **前缀匹配**：查找所有具有相同前缀的单词
4. **字符串排序**：按字典序排列字符串
5. **IP路由**：在网络中查找最长前缀匹配的路由

**优化技巧**：
1. **压缩前缀树**：合并只有一个子节点的节点，减少空间使用
2. **动态创建节点**：只在需要时创建节点，避免预分配过多空间
3. **位图优化**：使用位运算处理字符集，减少内存使用
4. **按需调整数组大小**：根据问题规模灵活调整节点数组大小

**总结**：
字符串匹配算法和字典树是解决字符串问题的强大工具。朴素算法简单直观但效率较低，适合小规模问题；KMP算法通过预处理模式串，大幅提高匹配效率；字典树则专门为快速存储和检索字符串而设计，在处理共享前缀的多个字符串时尤为高效。根据问题特性选择合适的算法，可以显著提高解题效率。

### 数学算法

#### 素数筛法

**基本概念**：
素数（质数）是指大于1的、除了1和它本身外没有其他因子的自然数。素数筛法是高效生成素数表的算法。

**埃拉托斯特尼筛法（Sieve of Eratosthenes）**：
这是最经典的素数筛法，通过标记合数来筛选出素数。

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 埃拉托斯特尼筛法
// 时间复杂度: O(n log log n)
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // 初始假设所有数都是素数
    vector<int> primes; // 存储素数的结果
    
    // 0和1不是素数
    isPrime[0] = isPrime[1] = false;
    
    // 从2开始筛选
    for (int i = 2; i * i <= n; i++) {
        // 如果i是素数，标记i的所有倍数为非素数
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // 收集所有素数
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
```

**线性筛法（欧拉筛）**：
比埃氏筛更高效的素数筛选算法，时间复杂度为O(n)。

```cpp
// 线性筛法（欧拉筛）
// 时间复杂度：O(n)
vector<int> linearSieve(int n) {
    vector<bool> isPrime(n + 1, true); // 初始假设所有数都是素数
    vector<int> primes; // 存储素数的结果
    
    // 0和1不是素数
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        // 如果i是素数，加入素数列表
        if (isPrime[i]) {
            primes.push_back(i);
        }
        
        // 用i乘以每个素数，标记这些乘积为合数
        // 注意：j < primes.size()是隐含的，因为枚举是按递增顺序进行的
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            isPrime[i * primes[j]] = false;
            
            // 当i能被primes[j]整除时，停止循环
            // 这确保每个合数只被其最小质因数标记一次
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    
    return primes;
}
```

**在比赛中使用**：
```cpp
void solvePrimeSieve() {
    int n = 100;
    
    // 使用埃氏筛法
    vector<int> primes1 = sieveOfEratosthenes(n);
    cout << "埃氏筛法找到的素数（≤" << n << "）: ";
    for (int prime : primes1) {
        cout << prime << " ";
    }
    cout << endl;
    
    // 使用线性筛法
    vector<int> primes2 = linearSieve(n);
    cout << "线性筛法找到的素数（≤" << n << "）: ";
    for (int prime : primes2) {
        cout << prime << " ";
    }
    cout << endl;
    
    // 素数计数
    cout << "≤" << n << "的素数个数: " << primes1.size() << endl;
}
```

#### 快速幂

**基本概念**：
快速幂是一种高效计算整数或矩阵幂的算法。它能在O(log n)的时间复杂度内计算x^n的值，而普通的幂运算需要O(n)的时间。

**算法思想**：
快速幂基于分治思想，利用了指数的二进制表示:
- 如果n是偶数，则x^n = (x^(n/2))^2
- 如果n是奇数，则x^n = x * (x^(n-1))

**整数快速幂实现**：
```cpp
#include <iostream>
using namespace std;

// 计算 (a^b) % mod
// 时间复杂度: O(log b)
long long fastPow(long long a, long long b, long long mod) {
    long long result = 1;
    
    // 将a对mod取余，避免初始a过大
    a %= mod;
    
    while (b > 0) {
        // 如果b的最低位是1，乘以当前的a
        if (b & 1) {
            result = (result * a) % mod;
        }
        
        // a平方
        a = (a * a) % mod;
        
        // b右移一位（相当于除以2）
        b >>= 1;
    }
    
    return result;
}
```

**递归版快速幂**：
```cpp
// 递归版快速幂
// 计算 (a^b) % mod
long long fastPowRecursive(long long a, long long b, long long mod) {
    // 基本情况
    if (b == 0) return 1;
    
    // 计算a^(b/2)
    long long half = fastPowRecursive(a, b / 2, mod);
    
    // 如果b是偶数
    if (b % 2 == 0) {
        return (half * half) % mod;
    } 
    // 如果b是奇数
    else {
        return (((half * half) % mod) * a) % mod;
    }
}
```

**应用场景**：
1. **模幂运算**：在密码学和数论中常用
2. **大数取模**：处理无法直接用基本类型表示的大数幂
3. **矩阵快速幂**：求解线性递推关系（如斐波那契数列）
4. **组合数学**：计算排列组合数

#### 最大公约数与最小公倍数

**基本概念**：
- **最大公约数（GCD）**：两个或多个整数共有的最大因数
- **最小公倍数（LCM）**：两个或多个整数共有的最小倍数

两者关系：a * b = gcd(a, b) * lcm(a, b)

**欧几里得算法（辗转相除法）**：
基于以下性质：gcd(a, b) = gcd(b, a mod b)

```cpp
#include <iostream>
using namespace std;

// 计算最大公约数（GCD）
// 时间复杂度: O(log(min(a, b)))
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 迭代版本的GCD
int gcdIterative(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算最小公倍数（LCM）
// 避免整数溢出：先计算GCD，然后用a / gcd * b
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
```

**扩展欧几里得算法**：
用于求解方程 ax + by = gcd(a, b) 的整数解。

```cpp
// 扩展欧几里得算法
// 求解方程 ax + by = gcd(a, b) 的一组解
// 返回gcd(a, b)，并通过引用返回x和y
int extendedGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int d = extendedGcd(b, a % b, x1, y1);
    
    // 更新x和y
    x = y1;
    y = x1 - (a / b) * y1;
    
    return d;
}
```

**应用场景**：
1. **数论问题**：解决与整数最大公约数、最小公倍数相关的问题
2. **分数运算**：化简分数、加减分数
3. **密码学**：RSA算法中的互质数判定等
4. **中国剩余定理**：求解模线性方程组

## 图论算法

### 图的表示

**基本概念**：
图是由一组顶点和一组边组成的数据结构，用于表示实体之间的连接关系。从数学上讲，图G = (V, E)，其中V是顶点集合，E是边集合。

**图的分类**：
1. **无向图**：边没有方向
2. **有向图**：边有方向
3. **带权图**：每条边有一个权值
4. **连通图**：任意两个顶点之间都有路径
5. **完全图**：任意两个顶点之间都有边
6. **二分图**：顶点可分为两个集合，同一集合内的顶点不相邻

**图的表示方法**：

**1. 邻接矩阵**：
使用一个二维数组表示顶点之间的连接关系。
- 适合于稠密图（边数接近于顶点数的平方）
- 查询两个顶点是否相连的时间复杂度为O(1)
- 空间复杂度为O(V²)

```cpp
// 邻接矩阵表示
int n = 5; // 顶点数量
vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

// 添加无向边
void addEdge(int u, int v, int weight = 1) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // 对于无向图
}

// 检查边是否存在
bool hasEdge(int u, int v) {
    return adjMatrix[u][v] != 0;
}

// 获取边的权值
int getWeight(int u, int v) {
    return adjMatrix[u][v];
}

// 遍历顶点u的所有邻接点
void printNeighbors(int u) {
    cout << "顶点" << u << "的邻接点: ";
    for (int v = 0; v < n; v++) {
        if (adjMatrix[u][v] != 0) {
            cout << v << " ";
        }
    }
    cout << endl;
}
```

**2. 邻接表**：
对每个顶点维护一个列表，存储与其相连的顶点。
- 适合于稀疏图（边数远小于顶点数的平方）
- 更节省空间，空间复杂度为O(V + E)
- 遍历一个顶点的所有邻接点很高效

```cpp
// 邻接表表示
int n = 5; // 顶点数量
vector<vector<pair<int, int>>> adjList(n); // pair<顶点, 权值>

// 添加无向边
void addEdge(int u, int v, int weight = 1) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // 对于无向图
}

// 检查边是否存在
bool hasEdge(int u, int v) {
    for (auto &edge : adjList[u]) {
        if (edge.first == v) return true;
    }
    return false;
}

// 获取边的权值
int getWeight(int u, int v) {
    for (auto &edge : adjList[u]) {
        if (edge.first == v) return edge.second;
    }
    return -1; // 表示边不存在
}

// 遍历顶点u的所有邻接点
void printNeighbors(int u) {
    cout << "顶点" << u << "的邻接点: ";
    for (auto &edge : adjList[u]) {
        cout << edge.first << "(" << edge.second << ") ";
    }
    cout << endl;
}
```

### 最短路径算法

**基本概念**：
最短路径问题是寻找图中从源点到目标点的总权重最小的路径。根据问题不同，可能需要处理单源最短路径、所有点对最短路径等变体。

#### Dijkstra算法
Dijkstra算法用于解决单源最短路径问题，即从一个点到其他所有点的最短路径。它适用于边权为非负的情况。

**算法思想**：
1. 初始时，标记源点的距离为0，其他点的距离为无穷大
2. 每次从未访问的点中选择距离源点最近的点，标记为已访问
3. 更新该点的所有邻接点的距离
4. 重复2-3步，直到所有点都被访问

**实现（使用优先队列优化）**：
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra算法：单源最短路径
// 时间复杂度：O(E log V)，其中E是边数，V是顶点数
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // 存储从源点到各点的最短距离
    vector<bool> visited(n, false); // 标记某点是否已访问
    
    // 初始化源点距离为0
    dist[start] = 0;
    
    // 优先队列，存储{距离, 顶点}对，按距离从小到大排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // 遍历u的所有邻接点
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // 尝试更新距离
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// 重建最短路径
vector<int> reconstructPath(vector<vector<pair<int, int>>> &graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1); // 存储路径中每个点的前驱
    vector<bool> visited(n, false);
    
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // 如果已经到达终点，可以提前结束
        if (u == end) break;
        
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u; // 记录前驱
                pq.push({dist[v], v});
            }
        }
    }
    
    // 如果终点不可达
    if (dist[end] == INT_MAX) {
        return {};
    }
    
    // 重建路径
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    
    // 反转路径（从起点到终点）
    reverse(path.begin(), path.end());
    return path;
}
```

#### Bellman-Ford算法
Bellman-Ford算法也解决单源最短路径问题，但它可以处理负权边，且可以检测负权环。

**算法思想**：
1. 初始时，标记源点的距离为0，其他点的距离为无穷大
2. 对所有边进行V-1次松弛操作（V是顶点数）
3. 再执行一轮松弛操作，如果还有距离可以被更新，则说明图中存在负权环

**实现**：
```cpp
// Bellman-Ford算法：单源最短路径（可处理负权边）
// 时间复杂度：O(VE)，其中V是顶点数，E是边数
// 返回值：true表示无负权环，false表示有负权环
bool bellmanFord(vector<vector<pair<int, int>>> &graph, int start, vector<int> &dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    
    // 边的表示：{from, {to, weight}}
    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < n; u++) {
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            edges.push_back({u, v, weight});
        }
    }
    
    // 执行V-1轮松弛操作
    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // 检查负权环
    for (auto &[u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return false; // 存在负权环
        }
    }
    
    return true; // 无负权环
}
```

#### Floyd-Warshall算法
Floyd-Warshall算法解决所有点对最短路径问题，即计算图中任意两点间的最短路径。

**算法思想**：
使用动态规划，dp[k][i][j]表示从i到j的路径中，只允许经过前k个顶点作为中间节点的最短距离。

**实现**：
```cpp
// Floyd-Warshall算法：所有点对最短路径
// 时间复杂度：O(V^3)，其中V是顶点数
vector<vector<int>> floydWarshall(vector<vector<int>> &adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> dist = adjMatrix; // 复制邻接矩阵
    
    // 初始化：将不连通的点之间的距离设为无穷大
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INT_MAX;
            }
        }
    }
    
    // 动态规划：考虑所有点作为中间点
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}
```

### 最小生成树

**基本概念**：
最小生成树(Minimum Spanning Tree, MST)是连通加权无向图中权值最小的生成树，即包含图中所有顶点的无环连通子图，且权值总和最小。

#### Kruskal算法
Kruskal算法基于贪心策略，按照边的权值从小到大排序，逐一加入图中，如果加入后不会形成环，则保留该边。

**算法思想**：
1. 将图中所有边按权值升序排序
2. 从权值最小的边开始，如果加入该边不会形成环，则将其加入生成树
3. 重复步骤2，直到生成树中包含V-1条边（V是顶点数）

**实现**：
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 边结构体
struct Edge {
    int u, v, weight;
    
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

// 并查集用于环检测
class DisjointSet {
private:
    vector<int> parent, rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // 已经在同一集合中
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

// Kruskal算法：最小生成树
// 时间复杂度：O(E log E)，其中E是边数
vector<Edge> kruskalMST(vector<Edge> &edges, int n) {
    // 按权值升序排序
    sort(edges.begin(), edges.end());
    
    vector<Edge> result; // 存储MST的边
    DisjointSet ds(n);
    
    for (const Edge &edge : edges) {
        // 如果加入该边不会形成环
        if (ds.unionSets(edge.u, edge.v)) {
            result.push_back(edge);
            
            // 如果已经有n-1条边，MST构建完成
            if (result.size() == n - 1) break;
        }
    }
    
    return result;
}

// 在比赛中使用
void solveKruskal() {
    int n = 5; // 顶点数
    int m = 7; // 边数
    
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    
    vector<Edge> mst = kruskalMST(edges, n);
    
    cout << "最小生成树的边：" << endl;
    int totalWeight = 0;
    for (const Edge &edge : mst) {
        cout << edge.u << " -- " << edge.v << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    
    cout << "最小生成树的总权值：" << totalWeight << endl;
}
```

#### Prim算法
Prim算法也是构建最小生成树的贪心算法，它从一个顶点开始，逐步扩展生成树。

**算法思想**：
1. 从任意顶点开始，将其加入生成树
2. 在生成树与非生成树顶点之间的边中选择权值最小的边
3. 将该边和对应的非生成树顶点加入生成树
4. 重复步骤2-3，直到所有顶点都加入生成树

**实现（使用优先队列优化）**：
```cpp
// Prim算法：最小生成树
// 时间复杂度：O(E log V)，其中E是边数，V是顶点数
vector<vector<pair<int, int>>> primMST(vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<bool> inMST(n, false); // 标记顶点是否在MST中
    vector<int> key(n, INT_MAX); // 存储连接顶点的边的最小权值
    vector<int> parent(n, -1); // 存储MST中顶点的父节点
    
    // 使用优先队列存储{权值, 顶点}对
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // 从顶点0开始
    key[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        
        // 遍历u的所有邻接点
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // 如果v不在MST中且权值更小
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }
    
    // 构建MST的邻接表表示
    vector<vector<pair<int, int>>> mst(n);
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            mst[parent[i]].push_back({i, key[i]});
            mst[i].push_back({parent[i], key[i]});
        }
    }
    
    return mst;
}

// 在比赛中使用
void solvePrim() {
    int n = 5; // 顶点数
    vector<vector<pair<int, int>>> graph(n);
    
    // 添加边
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[3].push_back({4, 9});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});
    graph[4].push_back({3, 9});
    
    vector<vector<pair<int, int>>> mst = primMST(graph);
    
    cout << "最小生成树的边：" << endl;
    int totalWeight = 0;
    
    for (int u = 0; u < n; u++) {
        for (auto &edge : mst[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (u < v) { // 避免重复输出
                cout << u << " -- " << v << " : " << weight << endl;
                totalWeight += weight;
            }
        }
    }
    
    cout << "最小生成树的总权值：" << totalWeight / 2 << endl; // 除以2因为每条边计算了两次
}
```

### 拓扑排序

**基本概念**：
拓扑排序是将有向无环图(DAG)中的顶点排成一个线性序列，使得图中任意一条边(u, v)对应的顶点u在序列中都排在顶点v之前。拓扑排序通常用于表示任务之间的依赖关系。

**应用场景**：
1. 任务调度
2. 编译顺序确定
3. 课程安排

**Kahn算法实现（使用入度）**：
```cpp
// Kahn算法：拓扑排序
// 时间复杂度：O(V+E)，其中V是顶点数，E是边数
vector<int> topologicalSort(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0); // 存储每个顶点的入度
    
    // 计算每个顶点的入度
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    
    // 将所有入度为0的顶点加入队列
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result; // 存储拓扑排序结果
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        // 将所有u指向的顶点的入度减1
        for (int v : graph[u]) {
            inDegree[v]--;
            // 如果入度变为0，加入队列
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // 如果结果中的顶点数小于n，说明图中有环
    if (result.size() != n) {
        return {}; // 返回空数组表示无法进行拓扑排序
    }
    
    return result;
}

// 在比赛中使用
void solveTopologicalSort() {
    int n = 6; // 顶点数
    vector<vector<int>> graph(n);
    
    // 添加边
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
    
    vector<int> topoOrder = topologicalSort(graph);
    
    if (topoOrder.empty()) {
        cout << "图中存在环，无法进行拓扑排序" << endl;
    } else {
        cout << "拓扑排序结果：";
        for (int vertex : topoOrder) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}
```

**DFS实现**：
```cpp
// 使用DFS进行拓扑排序
// 时间复杂度：O(V+E)
vector<int> topologicalSortDFS(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false); // 用于环检测
    vector<int> result;
    
    function<bool(int)> dfs = [&](int u) -> bool {
        visited[u] = true;
        inStack[u] = true;
        
        for (int v : graph[u]) {
            if (!visited[v]) {
                if (dfs(v)) return true; // 存在环
            } else if (inStack[v]) {
                return true; // 存在环
            }
        }
        
        inStack[u] = false;
        result.push_back(u);
        return false;
    };
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) return {}; // 存在环，无法进行拓扑排序
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// 在比赛中使用
void solveTopologicalSortDFS() {
    int n = 6; // 顶点数
    vector<vector<int>> graph(n);
    
    // 添加边
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
    
    vector<int> topoOrder = topologicalSortDFS(graph);
    
    if (topoOrder.empty()) {
        cout << "图中存在环，无法进行拓扑排序" << endl;
    } else {
        cout << "DFS拓扑排序结果：";
        for (int vertex : topoOrder) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}
```

## 动态规划

### 动态规划基础

**基本概念**：
动态规划（Dynamic Programming, DP）是一种通过将复杂问题分解为更简单的子问题，并存储子问题的解来避免重复计算的算法设计方法。

**适用条件**：
1. **最优子结构**：问题的最优解包含其子问题的最优解
2. **重叠子问题**：同一个子问题会被多次求解
3. **无后效性**：已经求解的子问题不受后续决策的影响

**设计动态规划算法的步骤**：
1. **定义状态**：明确定义子问题，确定状态表示
2. **确定状态转移方程**：如何从子问题的解得到原问题的解
3. **确定初始状态与边界条件**
4. **确定计算顺序**：一般是自底向上（迭代）或自顶向下（递归+记忆化）
5. **优化空间复杂度**（可选）：考虑是否可以优化空间使用

**递推与记忆化搜索**：
动态规划有两种常见的实现方式：
- **递推（自底向上）**：从最小的子问题开始，逐步解决更大的问题
- **记忆化搜索（自顶向下）**：从原问题开始，递归解决子问题，并记录已解决的子问题的解

**示例问题：斐波那契数列**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 递推实现（自底向上）
// 时间复杂度：O(n)，空间复杂度：O(n)
int fibDP(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// 空间优化版本
// 时间复杂度：O(n)，空间复杂度：O(1)
int fibDPOptimized(int n) {
    if (n <= 1) return n;
    
    int prev = 0;
    int curr = 1;
    
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr;
}

// 记忆化搜索实现（自顶向下）
// 时间复杂度：O(n)，空间复杂度：O(n)
vector<int> memo;

int fibMemo(int n) {
    if (n <= 1) return n;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibMemo(n-1) + fibMemo(n-2);
    return memo[n];
}

// 在比赛中使用
void solveFib() {
    int n = 10;
    
    // 递推
    cout << "斐波那契数 F(" << n << ") = " << fibDP(n) << endl;
    
    // 空间优化
    cout << "空间优化版本 F(" << n << ") = " << fibDPOptimized(n) << endl;
    
    // 记忆化搜索
    memo.assign(n + 1, -1);
    cout << "记忆化搜索版本 F(" << n << ") = " << fibMemo(n) << endl;
}
```

**什么时候使用动态规划**：
- 需要求解最优解问题（最大值、最小值等）
- 问题可以分解为重叠的子问题
- 问题具有最优子结构性质

**动态规划问题分类**：
1. **线性动态规划**：一维数组，如最长递增子序列
2. **区间动态规划**：区间问题，如戳气球
3. **背包动态规划**：资源分配问题，如0-1背包
4. **树形动态规划**：树上问题，如树的最大独立集
5. **状态压缩动态规划**：状态用位表示，如旅行商问题
6. **数位动态规划**：按数位处理，如计算特定范围内的数字计数

### 背包问题

**背包问题基本概念**：
背包问题是一类经典的组合优化问题，涉及在限制条件下选择物品以达到最大价值。

**1. 0-1背包问题**：
每种物品只有一个，可以选择放或不放入背包。

```cpp
// 0-1背包问题
// 时间复杂度：O(n*W)，其中n是物品数量，W是背包容量
int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // dp[i][j]表示考虑前i个物品，背包容量为j时的最大价值
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            // 不选第i个物品
            dp[i][j] = dp[i-1][j];
            
            // 选第i个物品（如果能装下）
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[n][capacity];
}

// 0-1背包空间优化版本
// 时间复杂度：O(n*W)，空间复杂度：O(W)
int knapsack01Optimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = capacity; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}
```

**2. 完全背包问题**：
每种物品有无限个，可以重复选择。

```cpp
// 完全背包问题
// 时间复杂度：O(n*W)
int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    // dp[j]表示背包容量为j时的最大价值
    for (int i = 0; i < n; i++) {
        for (int j = weights[i]; j <= capacity; j++) {
            // 注意循环顺序与0-1背包不同
            dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}
```

**3. 多重背包问题**：
每种物品有特定数量，不能超过这个数量。

```cpp
// 多重背包问题
// 时间复杂度：O(n*W*sum(counts))
int boundedKnapsack(vector<int>& weights, vector<int>& values, vector<int>& counts, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // 二进制优化：将counts[i]个物品i拆分成若干个物品
        for (int k = 1; k <= counts[i]; k *= 2) {
            int w = k * weights[i];
            int v = k * values[i];
            
            // 剩余的物品数量
            counts[i] -= k;
            
            // 按0-1背包处理
            for (int j = capacity; j >= w; j--) {
                dp[j] = max(dp[j], dp[j-w] + v);
            }
        }
        
        // 处理剩余的物品
        if (counts[i] > 0) {
            int w = counts[i] * weights[i];
            int v = counts[i] * values[i];
            
            for (int j = capacity; j >= w; j--) {
                dp[j] = max(dp[j], dp[j-w] + v);
            }
        }
    }
    
    return dp[capacity];
}
```

**4. 分组背包问题**：
物品被划分为多个组，每组最多选一个物品。

```cpp
// 分组背包问题
// 时间复杂度：O(n*W*k)，其中k是每组物品的平均数量
int groupKnapsack(vector<vector<int>>& weights, vector<vector<int>>& values, int capacity) {
    int n = weights.size(); // 组的数量
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = capacity; j >= 0; j--) {
            for (int k = 0; k < weights[i].size(); k++) {
                if (j >= weights[i][k]) {
                    dp[j] = max(dp[j], dp[j-weights[i][k]] + values[i][k]);
                }
            }
        }
    }
    
    return dp[capacity];
}
```

**背包问题的变种**：
1. **恰好装满**：需要初始化dp[0]=0，其他dp[j]=-INF
2. **求方案数**：状态转移为dp[j] += dp[j-weights[i]]
3. **求具体方案**：额外记录选择的物品

**在比赛中使用**：
```cpp
void solveKnapsack() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 8;
    
    cout << "0-1背包最大价值: " << knapsack01(weights, values, capacity) << endl;
    cout << "0-1背包最大价值(优化): " << knapsack01Optimized(weights, values, capacity) << endl;
    cout << "完全背包最大价值: " << unboundedKnapsack(weights, values, capacity) << endl;
    
    // 多重背包
    vector<int> counts = {2, 3, 1, 2};
    cout << "多重背包最大价值: " << boundedKnapsack(weights, values, counts, capacity) << endl;
    
    // 分组背包
    vector<vector<int>> groupWeights = {{2, 3}, {4, 5}};
    vector<vector<int>> groupValues = {{3, 4}, {5, 6}};
    cout << "分组背包最大价值: " << groupKnapsack(groupWeights, groupValues, capacity) << endl;
}
```

### 最长公共子序列

**问题描述**：
给定两个序列，找出它们的最长公共子序列（可以不连续）。

**动态规划解法**：
使用二维DP数组，dp[i][j]表示text1的前i个字符和text2的前j个字符的最长公共子序列长度。

```cpp
// 最长公共子序列
// 时间复杂度：O(m*n)，其中m和n是两个字符串的长度
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

// 空间优化版本
// 时间复杂度：O(m*n)，空间复杂度：O(min(m,n))
int lcsOptimized(string text1, string text2) {
    // 确保text1是较短的字符串
    if (text1.length() > text2.length()) {
        swap(text1, text2);
    }
    
    int m = text1.length();
    int n = text2.length();
    vector<int> dp(m + 1, 0);
    
    for (int j = 1; j <= n; j++) {
        int prev = 0; // dp[i-1][j-1]
        for (int i = 1; i <= m; i++) {
            int temp = dp[i]; // 保存dp[i]的旧值，用于下一轮的prev
            if (text1[i-1] == text2[j-1]) {
                dp[i] = prev + 1;
            } else {
                dp[i] = max(dp[i], dp[i-1]);
            }
            prev = temp;
        }
    }
    
    return dp[m];
}

// 重建最长公共子序列
string reconstructLCS(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 填充DP表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // 重建LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            lcs = text1[i-1] + lcs;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}

void solveLCS() {
    string text1 = "abcde";
    string text2 = "ace";
    
    cout << "最长公共子序列长度: " << longestCommonSubsequence(text1, text2) << endl;
    cout << "最长公共子序列: " << reconstructLCS(text1, text2) << endl;
}
```

### 最长递增子序列

**问题描述**：
给定一个整数序列，找出最长的严格递增子序列的长度。

**动态规划解法**：
使用一维DP数组，dp[i]表示以第i个元素结尾的最长递增子序列的长度。

```cpp
// 最长递增子序列 (LIS)
// 时间复杂度：O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 1); // 初始化为1，因为每个元素自身就是长度为1的LIS
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// 优化版本 - 使用二分查找
// 时间复杂度：O(n log n)
int lengthOfLISOptimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    // tails[i]表示长度为i+1的LIS的最后一个元素的最小值
    vector<int> tails(n, 0);
    int len = 0; // 当前LIS的长度
    
    for (int num : nums) {
        // 二分查找第一个大于等于num的位置
        int left = 0, right = len;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // 更新tails数组
        tails[left] = num;
        
        // 如果我们扩展了tails数组，意味着找到了更长的LIS
        if (left == len) {
            len++;
        }
    }
    
    return len;
}

// 使用patience sort重建LIS
vector<int> reconstructLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    
    vector<int> dp(n, 1); // dp[i]表示以nums[i]结尾的LIS长度
    vector<int> prev(n, -1); // prev[i]记录nums[i]前面的元素在LIS中的索引
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    
    // 找到最长LIS的结尾元素的索引
    int maxLen = 0, maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }
    
    // 重建LIS
    vector<int> lis;
    while (maxIdx != -1) {
        lis.push_back(nums[maxIdx]);
        maxIdx = prev[maxIdx];
    }
    
    reverse(lis.begin(), lis.end());
    return lis;
}

void solveLIS() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "最长递增子序列长度: " << lengthOfLIS(nums) << endl;
    cout << "最长递增子序列长度(优化): " << lengthOfLISOptimized(nums) << endl;
    
    vector<int> lis = reconstructLIS(nums);
    cout << "最长递增子序列: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;
}
```

### 经典动态规划问题示例

**最大子数组和问题（Kadane算法）**：
```cpp
// 最大子数组和 (Kadane算法)
// 时间复杂度：O(n)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    int currSum = nums[0]; // 当前子数组的和
    int maxSum = nums[0];  // 全局最大子数组和
    
    for (int i = 1; i < n; i++) {
        // 决策：续上前面的子数组还是重新开始
        currSum = max(nums[i], currSum + nums[i]);
        // 更新全局最大和
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}
```

**编辑距离问题**：
```cpp
// 编辑距离
// 时间复杂度：O(m*n)
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    
    // dp[i][j] 表示 word1[0:i-1] 转换到 word2[0:j-1] 的最小操作数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 初始化边界情况
    for (int i = 0; i <= m; i++) dp[i][0] = i; // 删除操作
    for (int j = 0; j <= n; j++) dp[0][j] = j; // 插入操作
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // 三种操作：插入、删除、替换
                dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
            }
        }
    }
    
    return dp[m][n];
}
```

**正则表达式匹配**：
```cpp
// 正则表达式匹配 ('.' 匹配任意单个字符，'*' 匹配零个或多个前面的元素)
// 时间复杂度：O(m*n)
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    
    // dp[i][j] 表示 s[0:i-1] 是否匹配 p[0:j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // 空字符串匹配空正则表达式
    dp[0][0] = true;
    
    // 处理空字符串与模式的匹配，如 s="" 是否匹配 p="a*b*c*"
    for (int j = 1; j <= n; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2]; // 不使用 '*' 前的字符
                
                if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j]; // 使用 '*'
                }
            } 
            else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    
    return dp[m][n];
}
```

### 动态规划优化技巧

1. **状态压缩**：
   - 使用位运算表示状态，特别适用于子集和旅行商问题
   - 空间复杂度可从O(2^n * n)降至O(2^n)

2. **空间优化**：
   - 滚动数组：将二维DP数组优化为一维或两行
   - 原地修改：在不需要回溯时，可以直接在原数组上修改

3. **决策单调性优化**：
   - 斜率优化：利用决策单调性，在计算dp[i]时不枚举所有j
   - 四边形不等式优化：适用于区间DP问题

4. **分治优化**：
   - 对于某些形如dp[i][j] = min{dp[i][k] + dp[k][j]} + C的问题
   - 当决策具有单调性时，可以使用分治方法优化

## 高级数据结构

### 树状数组

**基本概念**：
树状数组(Binary Indexed Tree, BIT)，也称为Fenwick树，是一种用于高效处理**前缀和查询**和**单点更新**的数据结构。

**特点**：
- 查询和更新的时间复杂度均为O(log n)
- 比线段树实现更为简单，内存占用更少
- 特别适合处理前缀和相关问题

**核心操作**：
- **更新(update)**：修改数组中某一位置的值
- **查询(query)**：计算数组中前缀和

**树状数组原理**：
核心是利用数的二进制表示。对于任意整数x，定义lowbit(x)为x的二进制表示中最低位的1所对应的值。
例如：lowbit(6) = 2，因为6的二进制是110，最低位的1对应值为2。

**lowbit函数实现**：
```cpp
// 计算x的二进制表示中最低位1所对应的值
int lowbit(int x) {
    return x & (-x);
}
```

**树状数组的基本实现**：

```cpp
#include <iostream>
#include <vector>
using namespace std;

class BIT {
private:
    vector<int> tree;
    int size;
    
    // 计算最低位1
    int lowbit(int x) {
        return x & (-x);
    }
    
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0); // 树状数组下标从1开始
    }
    
    // 单点更新：给位置idx的元素加上val
    void update(int idx, int val) {
        while (idx <= size) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    // 查询前缀和：计算区间[1, idx]的和
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
    
    // 查询区间[left, right]的和
    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

// 在比赛中使用
void solveBIT() {
    int n = 8;
    vector<int> arr = {3, 2, 1, 4, 5, 6, 7, 8}; // 原始数组（下标从0开始）
    
    // 初始化树状数组
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        bit.update(i + 1, arr[i]); // 注意树状数组下标从1开始
    }
    
    // 查询前缀和
    cout << "前缀和[1,4]: " << bit.query(4) << endl; // 输出: 10 (3+2+1+4)
    
    // 查询区间和
    cout << "区间和[3,6]: " << bit.queryRange(3, 6) << endl; // 输出: 16 (1+4+5+6)
    
    // 更新元素
    bit.update(3, 2); // 将位置3的元素增加2（此时arr[2] = 3）
    cout << "更新后区间和[3,6]: " << bit.queryRange(3, 6) << endl; // 输出: 18
}
```

**二维树状数组**：
二维树状数组可以处理二维前缀和查询和单点更新。

```cpp
// 二维树状数组
class BIT2D {
private:
    vector<vector<int>> tree;
    int n, m;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
public:
    BIT2D(int rows, int cols) {
        n = rows;
        m = cols;
        tree.resize(n + 1, vector<int>(m + 1, 0));
    }
    
    // 单点更新：给位置(row, col)的元素加上val
    void update(int row, int col, int val) {
        for (int i = row; i <= n; i += lowbit(i)) {
            for (int j = col; j <= m; j += lowbit(j)) {
                tree[i][j] += val;
            }
        }
    }
    
    // 查询前缀和：计算区域[1,1]到[row,col]的和
    int query(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= lowbit(i)) {
            for (int j = col; j > 0; j -= lowbit(j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    
    // 查询区域和
    int queryRegion(int row1, int col1, int row2, int col2) {
        return query(row2, col2) - query(row1 - 1, col2) - query(row2, col1 - 1) + query(row1 - 1, col1 - 1);
    }
};
```

**树状数组的应用场景**：
1. **区间求和**：快速计算数组任意区间的和
2. **逆序对计数**：通过离散化和树状数组高效计算逆序对
3. **区间更新**：结合差分数组实现区间更新、单点查询
4. **动态维护前缀信息**：如前缀最大值、前缀最小值等

**逆序对计数示例**：
```cpp
// 计算数组中的逆序对数量
int countInversions(vector<int>& arr) {
    int n = arr.size();
    
    // 离散化: 将原始值映射为排名
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        ranks[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
    }
    
    // 使用树状数组计算逆序对
    BIT bit(n);
    int inversions = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        // 对于每个元素，计算已经遍历过的小于它的元素个数
        inversions += bit.query(ranks[i] - 1);
        // 标记当前元素已被遍历
        bit.update(ranks[i], 1);
    }
    
    return inversions;
}
```

### ST表

**基本概念**：
ST表(Sparse Table)是一种用于解决**静态区间查询**问题的数据结构，特别是区间最大值、最小值等可重复贡献问题（满足结合律且幂等性）。

**特点**：
- 预处理时间复杂度：O(n log n)
- 查询时间复杂度：O(1)
- 不支持修改操作（静态数组）
- 非常适合处理RMQ（区间最值查询）问题

**ST表原理**：
预处理所有长度为2^k的区间的信息，查询时将任意区间分解为两个重叠的2^k区间。

**RMQ问题的ST表实现**：

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> log2_; // 预计算log2值，优化查询速度
    
public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        
        // 预计算log2(i)，优化查询
        log2_.resize(n + 1);
        log2_[1] = 0;
        for (int i = 2; i <= n; i++) {
            log2_[i] = log2_[i / 2] + 1;
        }
        
        // st[i][j] 存储从arr[i]开始，长度为2^j的区间的最大值
        int logn = log2_[n] + 1;
        st.resize(n, vector<int>(logn));
        
        // 初始化长度为1的区间
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        // 动态规划预处理
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                // 将区间分为两部分，取两者最大值
                st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    // 查询区间[L, R]的最大值，L和R从0开始
    int queryMax(int L, int R) {
        int len = R - L + 1;
        int k = log2_[len];
        
        // 将区间分为两个长度为2^k的区间，取两者最大值
        return max(st[L][k], st[R - (1 << k) + 1][k]);
    }
};

// 在比赛中使用
void solveSparseTable() {
    vector<int> arr = {3, 2, 4, 5, 6, 8, 1, 9, 7};
    SparseTable st(arr);
    
    // 查询区间最大值
    cout << "区间[2,7]的最大值: " << st.queryMax(2, 7) << endl; // 输出: 9
    cout << "区间[0,3]的最大值: " << st.queryMax(0, 3) << endl; // 输出: 5
    cout << "区间[4,8]的最大值: " << st.queryMax(4, 8) << endl; // 输出: 9
}
```

**ST表的应用场景**：
1. **区间最值查询(RMQ)**：快速查询区间的最大值或最小值
2. **区间GCD查询**：查询区间的最大公约数
3. **区间按位操作**：如区间按位或(OR)、按位与(AND)等
4. **区间幂等运算**：任何满足结合律和幂等性的操作（a op a = a）

**区间GCD查询的ST表**：
```cpp
// 区间GCD查询的ST表
class GCDSparseTable {
private:
    vector<vector<int>> st;
    vector<int> log2_;
    
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
public:
    GCDSparseTable(const vector<int>& arr) {
        int n = arr.size();
        
        // 预计算log2(i)
        log2_.resize(n + 1);
        log2_[1] = 0;
        for (int i = 2; i <= n; i++) {
            log2_[i] = log2_[i / 2] + 1;
        }
        
        int logn = log2_[n] + 1;
        st.resize(n, vector<int>(logn));
        
        // 初始化
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        // 预处理
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = gcd(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    int queryGCD(int L, int R) {
        int result = 0;
        for (int j = log2_[R - L + 1]; L <= R; j = log2_[R - L + 1]) {
            result = gcd(result, st[L][j]);
            L += (1 << j);
        }
        return result;
    }
};
```

**与其他数据结构的对比**：
1. **ST表vs线段树**：ST表查询更快(O(1)vs O(log n))但不支持修改；线段树支持修改
2. **ST表vs树状数组**：ST表适用范围更广（任何满足结合律的操作）但不支持修改
3. **ST表vs RMQ预处理**：ST表实现更简单，但某些RMQ算法可以达到更好的复杂度

### 平衡树

**基本概念**：
平衡树是一种特殊的二叉搜索树，通过自平衡操作保证树的高度是O(log n)的，从而确保基本操作（插入、删除、查找）的时间复杂度为O(log n)。

在竞赛中，常用的平衡树有：
1. **AVL树**：以高度平衡为条件
2. **红黑树**：通过着色规则维持平衡
3. **Treap**：将二叉搜索树与堆结合
4. **Splay树**：通过旋转操作将频繁访问的节点移至根部

在C++中，可以直接使用STL中的`set`、`map`、`multiset`和`multimap`，它们通常基于红黑树实现。

**Treap的实现**：
Treap是将二叉搜索树与堆结合的数据结构，每个节点有一个键值和一个优先级，键值按照二叉搜索树的性质排列，而优先级按照堆的性质排列。

```cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Treap节点定义
struct Node {
    int key;       // 键值，用于二叉搜索树性质
    int priority;  // 优先级，用于堆性质
    Node *left, *right;
    
    Node(int k) : key(k), left(nullptr), right(nullptr) {
        priority = rand(); // 随机生成优先级
    }
};

class Treap {
private:
    Node* root;
    
    // 右旋操作
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        return x;
    }
    
    // 左旋操作
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        return y;
    }
    
    // 插入操作的递归实现
    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        
        if (key < root->key) {
            root->left = insert(root->left, key);
            
            // 维持堆性质（最大堆）
            if (root->left->priority > root->priority) {
                root = rightRotate(root);
            }
        } else {
            root->right = insert(root->right, key);
            
            // 维持堆性质（最大堆）
            if (root->right->priority > root->priority) {
                root = leftRotate(root);
            }
        }
        
        return root;
    }
    
    // 删除操作的递归实现
    Node* remove(Node* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->key) {
            root->left = remove(root->left, key);
        } else if (key > root->key) {
            root->right = remove(root->right, key);
        } else { // 找到待删除的节点
            // 如果是叶节点，直接删除
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // 如果只有一个子节点，替换为子节点
            else if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            // 有两个子节点，根据优先级决定旋转方向
            else {
                if (root->left->priority > root->right->priority) {
                    root = rightRotate(root);
                    root->right = remove(root->right, key);
                } else {
                    root = leftRotate(root);
                    root->left = remove(root->left, key);
                }
            }
        }
        
        return root;
    }
    
    // 查找操作的递归实现
    bool search(Node* root, int key) {
        if (!root) return false;
        
        if (key == root->key) return true;
        
        if (key < root->key) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }
    
    // 中序遍历
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    
    // 释放内存
    void clear(Node* root) {
        if (root) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
    
public:
    Treap() : root(nullptr) {
        srand(time(nullptr)); // 初始化随机数生成器
    }
    
    ~Treap() {
        clear(root);
    }
    
    void insert(int key) {
        root = insert(root, key);
    }
    
    void remove(int key) {
        root = remove(root, key);
    }
    
    bool search(int key) {
        return search(root, key);
    }
    
    void print() {
        inorder(root);
        cout << endl;
    }
};

// 在比赛中使用
void solveTreap() {
    Treap treap;
    
    // 插入元素
    treap.insert(10);
    treap.insert(20);
    treap.insert(5);
    treap.insert(15);
    treap.insert(30);
    
    cout << "Treap内容: ";
    treap.print(); // 应该按排序顺序输出: 5 10 15 20 30
    
    // 查找元素
    cout << "查找15: " << (treap.search(15) ? "存在" : "不存在") << endl;
    cout << "查找25: " << (treap.search(25) ? "存在" : "不存在") << endl;
    
    // 删除元素
    treap.remove(15);
    cout << "删除15后: ";
    treap.print();
}
```

**平衡树的应用场景**：
1. **有序集合**：维护有序的元素集合
2. **有序映射**：键值对的有序存储
3. **范围查询**：查询某个范围内的元素
4. **前驱/后继查询**：查找某个值的前驱或后继
5. **排名统计**：查询某个值的排名或查询某个排名的值

**使用STL中的平衡树**：
```cpp
#include <iostream>
#include <set>
#include <map>
using namespace std;

void solveSTLBalancedTree() {
    // set示例 - 有序集合
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(5);
    s.insert(15);
    
    cout << "set内容: ";
    for (int x : s) cout << x << " "; // 输出: 5 10 15 20
    cout << endl;
    
    // 查找
    cout << "查找15: " << (s.find(15) != s.end() ? "存在" : "不存在") << endl;
    
    // lower_bound和upper_bound
    cout << "第一个>=12的元素: " << *s.lower_bound(12) << endl; // 输出: 15
    cout << "第一个>15的元素: " << *s.upper_bound(15) << endl; // 输出: 20
    
    // map示例 - 有序映射
    map<string, int> m;
    m["apple"] = 5;
    m["banana"] = 3;
    m["orange"] = 7;
    
    cout << "map内容: " << endl;
    for (auto& p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    
    // multiset示例 - 允许重复元素的有序集合
    multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // 允许重复
    ms.insert(30);
    
    cout << "multiset内容: ";
    for (int x : ms) cout << x << " "; // 输出: 10 10 20 30
    cout << endl;
    
    // 计数
    cout << "10的出现次数: " << ms.count(10) << endl; // 输出: 2
    
    // 删除所有特定值
    ms.erase(10);
    cout << "删除所有10后: ";
    for (int x : ms) cout << x << " "; // 输出: 20 30
    cout << endl;
}
```

## 技巧与优化

### 位运算技巧

位运算是对二进制位进行的操作，由于其高效性和特殊性质，在竞争性编程中经常使用。

**基本位运算操作**：

| 运算符 | 名称 | 表达式 | 说明 |
|------|------|-------|------|
| `&`  | 按位与 | `a & b` | 相同位都为1时结果为1 |
| `\|` | 按位或 | `a \| b` | 相同位任一为1时结果为1 |
| `^`  | 按位异或 | `a ^ b` | 相同位不同时结果为1 |
| `~`  | 按位取反 | `~a` | 0变1，1变0 |
| `<<` | 左移 | `a << b` | 左移b位，低位补0 |
| `>>` | 右移 | `a >> b` | 右移b位，高位补符号位或0 |

**常用位运算技巧**：

1. **判断奇偶性**
   ```cpp
   bool isEven = (n & 1) == 0; // 等价于 n % 2 == 0
   ```

2. **乘以/除以2的幂**
   ```cpp
   int multiply = n << k; // n * (2^k)
   int divide = n >> k;   // n / (2^k)，向下取整
   ```

3. **取模2的幂**
   ```cpp
   int mod = n & (power - 1); // n % power，其中power = 2^k
   ```

4. **交换两个数**
   ```cpp
   a ^= b;
   b ^= a; // now b = a
   a ^= b; // now a = original b
   ```

5. **获取最低位的1**
   ```cpp
   int lowestBit = n & -n; // 或者 n & (~n + 1)
   ```

6. **移除最低位的1**
   ```cpp
   int removeLowestBit = n & (n - 1);
   ```

7. **检查是否为2的幂**
   ```cpp
   bool isPowerOfTwo = n && !(n & (n - 1));
   ```

8. **统计二进制中1的个数**
   ```cpp
   int countOnes(int n) {
       int count = 0;
       while (n) {
           n &= (n - 1); // 每次消除最低位的1
           count++;
       }
       return count;
   }
   ```

9. **快速幂运算**
   ```cpp
   long long fastPow(long long base, long long exp, long long mod) {
       long long result = 1;
       base %= mod;
       while (exp) {
           if (exp & 1) result = (result * base) % mod;
           base = (base * base) % mod;
           exp >>= 1;
       }
       return result;
   }
   ```

**位掩码技术**：

位掩码是使用位运算表示集合的技术，特别适合表示小规模集合（通常≤64个元素）。

```cpp
// 使用位掩码表示集合
int set = 0;

// 添加元素 i
set |= (1 << i);

// 删除元素 i
set &= ~(1 << i);

// 检查元素 i 是否在集合中
bool contains = (set & (1 << i)) != 0;

// 切换元素 i 的存在状态
set ^= (1 << i);

// 获取集合大小
int size = __builtin_popcount(set); // GCC内置函数

// 集合操作
int unionSet = setA | setB;     // 并集
int intersectionSet = setA & setB; // 交集
int differenceSet = setA & ~setB;  // 差集
int complementSet = ~setA;      // 补集

// 遍历集合中的所有元素
for (int i = 0; i < 32; i++) {
    if (set & (1 << i)) {
        // i 在集合中
        cout << i << " in set" << endl;
    }
}

// 遍历所有子集
int subset = set;
do {
    // 处理子集 subset
    subset = (subset - 1) & set;
} while (subset != set);

// 遍历所有大小为 k 的子集（组合）
void generateCombinations(int n, int k) {
    // n选k
    int combination = (1 << k) - 1; // 初始组合：k个连续的1
    
    while (combination < (1 << n)) {
        // 处理当前组合...
        
        // 生成下一个组合（Gosper's Hack）
        int x = combination & -combination;
        int y = combination + x;
        combination = ((combination & ~y) / x >> 1) | y;
    }
}
```

**位运算在动态规划中的应用**：

位运算在状态压缩动态规划中尤为有用，可以用来表示和操作状态。

```cpp
// 旅行商问题(TSP)的状态压缩DP实现
// 状态dp[i][mask]表示从起点0出发，当前在城市i，已经访问的城市集合为mask的最短路径长度
int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
    
    // 初始状态：从起点0到各个城市的距离
    for (int i = 0; i < n; i++) {
        dp[i][1 | (1 << i)] = dist[0][i];
    }
    
    // 枚举所有可能的状态
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            // 如果城市i不在当前集合mask中，跳过
            if (!(mask & (1 << i))) continue;
            
            // 枚举上一个访问的城市j
            for (int j = 0; j < n; j++) {
                // j必须在mask中但不能是i
                if (i == j || !(mask & (1 << j))) continue;
                
                int prevMask = mask & ~(1 << i);
                if (dp[j][prevMask] != INT_MAX) {
                    dp[i][mask] = min(dp[i][mask], dp[j][prevMask] + dist[j][i]);
                }
            }
        }
    }
    
    // 找到从任意城市回到起点的最短路径
    int finalMask = (1 << n) - 1;
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (dp[i][finalMask] != INT_MAX) {
            ans = min(ans, dp[i][finalMask] + dist[i][0]);
        }
    }
    
    return ans;
}
```

### STL使用技巧

C++ STL（标准模板库）提供了大量高效的数据结构和算法，合理使用它们可以显著提高编程效率和代码可读性。

**容器使用技巧**：

1. **vector**
   ```cpp
   // 高效初始化
   vector<int> v(10, 0); // 大小为10，全部初始化为0
   
   // 二维vector初始化
   vector<vector<int>> matrix(m, vector<int>(n, 0));
   
   // 快速排序
   sort(v.begin(), v.end()); // 升序
   sort(v.rbegin(), v.rend()); // 降序
   
   // 按自定义比较函数排序
   sort(v.begin(), v.end(), [](int a, int b) {
       return abs(a) < abs(b); // 按绝对值排序
   });
   
   // 二分查找
   bool found = binary_search(v.begin(), v.end(), value);
   auto lower = lower_bound(v.begin(), v.end(), value); // >=value的第一个元素
   auto upper = upper_bound(v.begin(), v.end(), value); // >value的第一个元素
   
   // 快速去重（要求已排序）
   v.erase(unique(v.begin(), v.end()), v.end());
   
   // 反转
   reverse(v.begin(), v.end());
   
   // 求和
   int sum = accumulate(v.begin(), v.end(), 0);
   
   // 查找最值
   int maxVal = *max_element(v.begin(), v.end());
   int minVal = *min_element(v.begin(), v.end());
   ```

2. **set和map**
   ```cpp
   // set相关操作
   set<int> s;
   s.insert(1); // 插入元素
   s.erase(1);  // 删除元素
   auto it = s.lower_bound(5); // 返回>=5的第一个元素的迭代器
   auto it2 = s.upper_bound(5); // 返回>5的第一个元素的迭代器
   
   // 自定义比较函数的set
   set<pair<int,int>, greater<pair<int,int>>> customSet;
   
   // map相关操作
   map<string, int> m;
   m["key"] = 100;  // 插入或更新
   if (m.count("key")) { /* key存在 */ }
   for (auto& [key, value] : m) { /* 遍历 */ }
   
   // 有序map/multimap按键范围访问
   auto range = m.equal_range("key");
   for (auto it = range.first; it != range.second; ++it) {
       cout << it->second << endl;
   }
   ```

3. **unordered_set和unordered_map**
   ```cpp
   // 哈希集合和映射，平均O(1)查找
   unordered_set<int> us;
   unordered_map<string, int> um;
   
   // 自定义哈希函数
   struct PairHash {
       size_t operator()(const pair<int, int>& p) const {
           return p.first * 31 + p.second;
       }
   };
   unordered_set<pair<int, int>, PairHash> customHash;
   ```

4. **priority_queue（优先队列）**
   ```cpp
   // 最大堆（默认）
   priority_queue<int> maxHeap;
   
   // 最小堆
   priority_queue<int, vector<int>, greater<int>> minHeap;
   
   // 自定义比较函数
   auto cmp = [](pair<int, int> a, pair<int, int> b) {
       return a.first > b.first; // 按第一个元素构建最小堆
   };
   priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> customHeap(cmp);
   ```

5. **deque（双端队列）**
   ```cpp
   deque<int> dq;
   dq.push_front(1); // 添加到队首
   dq.pop_front();   // 移除队首元素
   dq.push_back(2);  // 添加到队尾
   dq.pop_back();    // 移除队尾元素
   ```

**算法使用技巧**：

1. **排列组合相关**
   ```cpp
   // 下一个排列
   bool hasNext = next_permutation(v.begin(), v.end());
   
   // 上一个排列
   bool hasPrev = prev_permutation(v.begin(), v.end());
   
   // 生成所有排列
   sort(v.begin(), v.end()); // 先排序以获得第一个排列
   do {
       // 处理当前排列
   } while(next_permutation(v.begin(), v.end()));
   ```

2. **数值算法**
   ```cpp
   // 最大公约数
   int gcd = __gcd(a, b); // C++17前
   int gcd = gcd(a, b);   // C++17及之后
   
   // 最小公倍数
   int lcm = (a / gcd(a, b)) * b;
   
   // 范围内最小最大值
   auto [minIt, maxIt] = minmax_element(v.begin(), v.end());
   ```

3. **其他有用算法**
   ```cpp
   // 填充
   fill(v.begin(), v.end(), value);
   
   // 计数
   int count = count(v.begin(), v.end(), value);
   int countIf = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
   
   // 查找
   auto it = find(v.begin(), v.end(), value);
   
   // 分区
   auto pivot = partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
   
   // 比较两个区间
   bool lexLessThan = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
   ```

**实用STL代码片段**：

```cpp
// 统计字符串中每个字符的频率
map<char, int> freqCount(string& s) {
    map<char, int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// 字符串分割
vector<string> split(string s, string delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}

// 检查一个string是否是另一个的子序列
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}

// 合并有序区间
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    
    return merged;
}
```

### 常见算法优化思路

在算法竞赛中，优化算法性能是一项重要技能。以下是一些常见的算法优化策略：

**1. 算法层面优化**

**时间复杂度优化**：
- **选择合适的算法**：不同算法解决同一问题的时间复杂度可能相差很大，如排序可选冒泡排序O(n²)或快速排序O(n log n)
- **减少不必要的计算**：避免重复计算，利用已有结果
- **空间换时间**：使用额外的数据结构来加速查询
- **分治与二分**：将问题规模减半处理
- **预处理与离线算法**：提前计算可重用的结果

**示例：优化斐波那契数列计算**

未优化版本(O(2ⁿ)):
```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

记忆化搜索优化(O(n)):
```cpp
int fib(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}
```

动态规划优化(O(n)):
```cpp
int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

空间复杂度进一步优化(O(1)):
```cpp
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```

**2. 数据结构优化**

- **哈希表**：将O(n)的查找优化至平均O(1)
- **平衡树**：将有序数组上的二分查找和插入操作整合到一个数据结构中
- **并查集**：优化连通性查询
- **堆/优先队列**：优化获取最值的操作
- **Trie树**：优化字符串前缀查询

**示例：区间最小值查询（RMQ）优化**

暴力方法(O(n)查询):
```cpp
int rangeMinQuery(vector<int>& arr, int L, int R) {
    int minVal = INT_MAX;
    for (int i = L; i <= R; i++) {
        minVal = min(minVal, arr[i]);
    }
    return minVal;
}
```

使用线段树优化(O(log n)查询):
```cpp
int query(vector<int>& tree, int node, int start, int end, int L, int R) {
    if (L <= start && end <= R) return tree[node];
    if (end < L || R < start) return INT_MAX;
    int mid = start + (end - start) / 2;
    return min(
        query(tree, 2*node+1, start, mid, L, R),
        query(tree, 2*node+2, mid+1, end, L, R)
    );
}
```

使用ST表进一步优化(O(1)查询，静态数组):
```cpp
int queryRMQ(vector<vector<int>>& st, vector<int>& log2, int L, int R) {
    int len = R - L + 1;
    int k = log2[len];
    return min(st[L][k], st[R-(1<<k)+1][k]);
}
```

**3. 代码层面优化**

- **局部变量替代全局变量**：减少访问全局变量的开销
- **循环优化**：减少循环内计算、循环展开、提取循环不变量
- **移除不必要的内存分配**：避免频繁创建临时对象
- **预先计算和缓存结果**：如预计算log、阶乘等
- **位运算替代昂贵操作**：如`x & 1`替代`x % 2`

**示例：预计算优化**
```cpp
// 预计算阶乘以优化组合数计算
vector<long long> factorial(N+1);
void precomputeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i <= N; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

long long combination(int n, int k) {
    if (k > n) return 0;
    return (factorial[n] * modInverse((factorial[k] * factorial[n-k]) % MOD)) % MOD;
}
```

**4. 常数优化**

- **使用合适的数据类型**：避免不必要的大数据类型
- **减少函数调用**：内联简单函数
- **避免不必要的拷贝**：使用引用传参
- **减少分支预测失误**：简化条件判断
- **利用CPU缓存**：合理组织数据访问模式
- **内存对齐和局部性**：优化内存访问模式

**实现丢弃策略**：
在某些情况下，可通过牺牲部分精确性来换取更高的性能，特别是当问题规模极大或要求近似解时。

**示例：模拟退火**
```cpp
// 使用随机化算法解决旅行商问题
double simulatedAnnealing(vector<pair<double, double>>& points) {
    vector<int> route(points.size());
    for (int i = 0; i < route.size(); i++) route[i] = i;
    random_shuffle(route.begin(), route.end());
    
    double T = 100.0;  // 初始温度
    double minDist = calculateDistance(points, route);
    
    while (T > 1e-8) {
        // 随机选择两个点交换
        int i = rand() % route.size();
        int j = rand() % route.size();
        swap(route[i], route[j]);
        
        double newDist = calculateDistance(points, route);
        double delta = newDist - minDist;
        
        // 根据Metropolis准则接受或拒绝新解
        if (delta < 0 || exp(-delta / T) > (double)rand() / RAND_MAX) {
            minDist = newDist;
        } else {
            swap(route[i], route[j]); // 恢复交换
        }
        
        T *= 0.9999; // 降温
    }
    return minDist;
}
```

## 实战练习指导

### 如何分析问题

**问题分析步骤**：

1. **理解问题**：
   - 仔细阅读题目，特别注意输入输出规格、数据范围和特殊条件
   - 分析样例，确保理解问题要求
   - 确定问题类型（图论、动态规划、贪心等）

2. **寻找关键观察**：
   - 寻找问题中的特殊性质或模式
   - 考虑边界情况和特殊输入
   - 尝试将问题简化或转化为已知问题

3. **设计算法**：
   - 从暴力解开始，逐步优化
   - 选择合适的数据结构
   - 估算时间和空间复杂度
   - 考虑可能的优化方向

**示例分析**：
假设问题是"找出一个整数数组中和为给定值的两个数"

分析过程：
```
1. 理解问题：
   - 输入：整数数组和目标和
   - 输出：满足条件的两个数的索引
   - 数组规模为n

2. 寻找关键观察：
   - 如果数组已排序，可以使用双指针法
   - 对于每个数x，我们需要查找是否存在目标和-x
   - 查找操作如果使用数组需要O(n)，如果使用哈希表可以O(1)

3. 设计算法：
   - 初始暴力解法：两重循环，O(n²)
   - 优化方案：使用哈希表存储已遍历的数，O(n)
```

**解决方案**：
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;  // 值 -> 索引
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (m.count(complement)) {
            return {m[complement], i};
        }
        m[nums[i]] = i;
    }
    return {};  // 未找到解
}
```

### 常见解题模板

**滑动窗口问题模板**：
```cpp
// 滑动窗口模板
vector<int> slidingWindowTemplate(string s, string t) {
    vector<int> result;
    unordered_map<char, int> need, window;
    
    // 初始化need哈希表
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0;  // 已匹配的字符数
    
    while (right < s.size()) {
        char c = s[right++];  // 扩大窗口
        // 更新窗口内数据
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }
        
        // 判断左窗口是否需要收缩
        while (valid == need.size()) {
            // ... 在这里更新结果
            
            char d = s[left++];  // 缩小窗口
            // 更新窗口内数据
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return result;
}
```

**二分查找模板**：
```cpp
// 寻找左侧边界的二分查找
int binarySearchLeft(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left < nums.size() && nums[left] == target ? left : -1;
}

// 寻找右侧边界的二分查找
int binarySearchRight(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left > 0 && nums[left - 1] == target ? left - 1 : -1;
}
```

**BFS网格搜索模板**：
```cpp
// 在网格中使用BFS寻找从起点到终点的最短路径
int shortestPath(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    queue<pair<pair<int, int>, int>> q;  // ((x, y), distance)
    q.push({start, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        auto [curr, distance] = q.front();
        q.pop();
        
        if (curr == end) return distance;
        
        for (auto& dir : directions) {
            int nx = curr.first + dir.first;
            int ny = curr.second + dir.second;
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, distance + 1});
            }
        }
    }
    
    return -1;  // 未找到路径
}
```

**排列组合回溯模板**：
```cpp
// 生成所有可能的组合（n选k）
void backtrackCombinations(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        backtrackCombinations(n, k, i + 1, current, result);
        current.pop_back();
    }
}

// 生成所有可能的排列
void backtrackPermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrackPermutations(nums, start + 1, result);
        swap(nums[start], nums[i]);  // 回溯
    }
}
```

### 算法比赛技巧

**时间管理**：
- **快速读题和分类**：先浏览所有题目，按难度从易到难排序
- **适当放弃**：遇到难题卡住时，先切换到其他题
- **分阶段解题**：先实现简单版本，保证得分，再优化完善
- **测试与调试**：留出足够时间进行测试和调试

**常见错误避免**：
1. **边界条件处理**：
   - 空输入、单元素输入
   - 最大/最小值输入
   - 数组越界检查
   - 整数溢出处理

2. **常见错误类型**：
   - 忘记初始化变量
   - 条件判断错误（如`<`写成`<=`）
   - 循环边界错误（如off-by-one错误）
   - 数据类型不匹配
   - 整数溢出

**示例：整数溢出检测与处理**
```cpp
// 检测加法溢出
bool addOverflow(int a, int b) {
    if (a > 0 && b > 0 && a > INT_MAX - b) return true;
    if (a < 0 && b < 0 && a < INT_MIN - b) return true;
    return false;
}

// 使用更大的数据类型避免溢出
long long safeAdd(int a, int b) {
    return (long long)a + b;
}
```

**调试技巧**：
1. **二分查找错误**：如果程序在大数据上出错，可以对输入规模进行二分，找出最小的出错输入
2. **打印中间结果**：在关键步骤添加输出语句
3. **生成随机测试数据**：创建随机测试用例验证程序正确性
4. **代码重构**：将复杂逻辑分解为更小的函数
5. **检查边界条件**：小心检查循环边界、条件判断等

**优化提交策略**：
1. **增量式开发**：先实现简单版本，确保正确后再优化
2. **保存中间版本**：定期保存可运行的版本
3. **预先准备模板**：准备常用算法和数据结构的模板代码
4. **快速验证想法**：不确定时，编写简单测试验证想法

**比赛心态调整**：
1. **保持冷静**：遇到困难时不要慌张
2. **专注当下**：不要过分纠结已经提交的题目
3. **灵活思考**：从多个角度思考问题
4. **合理休息**：保持思维清晰

**练习资源推荐**：
- LeetCode：系统练习各类算法
- CodeForces：参加比赛提升实战能力
- AtCoder：质量高的算法比赛平台
- USACO训练营：系统性强的训练项目
- OI-Wiki：开源、全面的算法百科全书

**进阶学习建议**：
1. **系统学习**：按主题系统掌握各种算法和数据结构
2. **刻意练习**：针对弱项进行重点练习
3. **比赛模拟**：定期进行模拟比赛，训练实战能力
4. **代码复盘**：比赛后分析自己的解题思路和代码
5. **团队学习**：与他人交流思路和解法