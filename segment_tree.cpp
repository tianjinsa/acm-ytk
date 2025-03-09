/**
 * 线段树算法实现与应用
 * 
 * 线段树是一种二叉搜索树，用于解决区间查询和修改的问题
 * 它能在O(log n)的时间复杂度内完成区间查询和单点修改操作
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 基础线段树实现 - 区间求和问题
 * 
 * 功能：
 * 1. 构建线段树
 * 2. 单点修改
 * 3. 区间查询
 */
class SegmentTree {
private:
    vector<int> tree;  // 存储线段树节点的数组
    vector<int> lazy;  // 用于延迟传播的标记数组
    int n;            // 原始数组的大小
    
    /**
     * 构建线段树
     * 
     * @param arr  原始数组
     * @param node 当前节点在tree数组中的索引
     * @param start 当前节点代表的区间起始位置
     * @param end   当前节点代表的区间结束位置
     */
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // 叶节点，存储原始数组对应位置的值
            tree[node] = arr[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        // 递归构建左右子树
        build(arr, leftChild, start, mid);
        build(arr, rightChild, mid + 1, end);
        
        // 当前节点的值是其左右子节点值的和
        tree[node] = tree[leftChild] + tree[rightChild];
    }
    
    /**
     * 更新线段树中某个节点的值
     * 
     * @param node  当前节点在tree数组中的索引
     * @param start 当前节点代表的区间起始位置
     * @param end   当前节点代表的区间结束位置
     * @param idx   需要更新的原始数组索引
     * @param val   更新后的值
     */
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // 找到叶节点，直接更新
            tree[node] = val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        // 确定idx落在左子树还是右子树
        if (idx <= mid) {
            update(leftChild, start, mid, idx, val);
        } else {
            update(rightChild, mid + 1, end, idx, val);
        }
        
        // 从子节点更新当前节点的值
        tree[node] = tree[leftChild] + tree[rightChild];
    }
    
    /**
     * 查询区间[qStart, qEnd]的和
     * 
     * @param node   当前节点在tree数组中的索引
     * @param start  当前节点代表的区间起始位置
     * @param end    当前节点代表的区间结束位置
     * @param qStart 查询区间的起始位置
     * @param qEnd   查询区间的结束位置
     * @return 区间和
     */
    int query(int node, int start, int end, int qStart, int qEnd) {
        // 查询区间与当前节点区间不相交
        if (qStart > end || qEnd < start) {
            return 0;  // 返回查询操作的默认值（和为0）
        }
        
        // 查询区间完全包含当前节点区间
        if (qStart <= start && qEnd >= end) {
            return tree[node];
        }
        
        // 查询区间与当前节点区间部分相交，需要递归查询子树
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        int leftSum = query(leftChild, start, mid, qStart, qEnd);
        int rightSum = query(rightChild, mid + 1, end, qStart, qEnd);
        
        return leftSum + rightSum;
    }
    
    /**
     * 区间更新 - 将区间[qStart, qEnd]中每个元素加上val
     * 
     * @param node   当前节点在tree数组中的索引
     * @param start  当前节点代表的区间起始位置
     * @param end    当前节点代表的区间结束位置
     * @param qStart 更新区间的起始位置
     * @param qEnd   更新区间的结束位置
     * @param val    增加的值
     */
    void updateRange(int node, int start, int end, int qStart, int qEnd, int val) {
        // 先处理当前节点的lazy标记
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];  // 更新当前节点的值
            
            // 如果不是叶节点，将lazy标记下推给子节点
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            
            lazy[node] = 0;  // 清除当前节点的lazy标记
        }
        
        // 查询区间与当前节点区间不相交
        if (qStart > end || qEnd < start) {
            return;
        }
        
        // 查询区间完全包含当前节点区间
        if (qStart <= start && qEnd >= end) {
            tree[node] += (end - start + 1) * val;  // 更新当前节点的值
            
            // 如果不是叶节点，设置子节点的lazy标记
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            
            return;
        }
        
        // 查询区间与当前节点区间部分相交，需要递归更新子树
        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, qStart, qEnd, val);
        updateRange(2 * node + 2, mid + 1, end, qStart, qEnd, val);
        
        // 从子节点更新当前节点的值
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
    /**
     * 带延迟传播的区间查询
     * 
     * @param node   当前节点在tree数组中的索引
     * @param start  当前节点代表的区间起始位置
     * @param end    当前节点代表的区间结束位置
     * @param qStart 查询区间的起始位置
     * @param qEnd   查询区间的结束位置
     * @return 区间和
     */
    int queryLazy(int node, int start, int end, int qStart, int qEnd) {
        // 先处理当前节点的lazy标记
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];  // 更新当前节点的值
            
            // 如果不是叶节点，将lazy标记下推给子节点
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            
            lazy[node] = 0;  // 清除当前节点的lazy标记
        }
        
        // 查询区间与当前节点区间不相交
        if (qStart > end || qEnd < start) {
            return 0;
        }
        
        // 查询区间完全包含当前节点区间
        if (qStart <= start && qEnd >= end) {
            return tree[node];
        }
        
        // 查询区间与当前节点区间部分相交，需要递归查询子树
        int mid = start + (end - start) / 2;
        int leftSum = queryLazy(2 * node + 1, start, mid, qStart, qEnd);
        int rightSum = queryLazy(2 * node + 2, mid + 1, end, qStart, qEnd);
        
        return leftSum + rightSum;
    }

public:
    /**
     * 构造函数
     * 
     * @param arr 原始数组
     */
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        // 为线段树分配4n的空间（最坏情况下需要的空间大小）
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        
        if (n > 0) {
            build(arr, 0, 0, n - 1);
        }
    }
    
    /**
     * 更新单个元素的值
     * 
     * @param idx 原始数组中的索引
     * @param val 新值
     */
    void update(int idx, int val) {
        if (idx < 0 || idx >= n) return;
        update(0, 0, n - 1, idx, val);
    }
    
    /**
     * 查询区间[left, right]的和
     * 
     * @param left  查询区间的起始位置
     * @param right 查询区间的结束位置
     * @return 区间和
     */
    int query(int left, int right) {
        if (left < 0) left = 0;
        if (right >= n) right = n - 1;
        if (left > right) return 0;
        
        return query(0, 0, n - 1, left, right);
    }
    
    /**
     * 更新区间[left, right]中的所有元素，每个元素增加val
     * 
     * @param left  更新区间的起始位置
     * @param right 更新区间的结束位置
     * @param val   增加的值
     */
    void updateRange(int left, int right, int val) {
        if (left < 0) left = 0;
        if (right >= n) right = n - 1;
        if (left > right) return;
        
        updateRange(0, 0, n - 1, left, right, val);
    }
    
    /**
     * 带延迟传播的区间查询
     * 
     * @param left  查询区间的起始位置
     * @param right 查询区间的结束位置
     * @return 区间和
     */
    int queryLazy(int left, int right) {
        if (left < 0) left = 0;
        if (right >= n) right = n - 1;
        if (left > right) return 0;
        
        return queryLazy(0, 0, n - 1, left, right);
    }
};
