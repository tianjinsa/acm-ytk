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
