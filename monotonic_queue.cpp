/**
 * 单调队列算法实现与应用
 * 
 * 单调队列是一种特殊的队列，它维护队列中元素的单调性（递增或递减）
 * 主要用于解决滑动窗口的最大值/最小值问题
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * 滑动窗口最大值问题
 * 
 * 问题描述：给定一个数组 nums 和滑动窗口的大小 k，找出所有滑动窗口里的最大值
 * 
 * @param nums  输入数组
 * @param k     窗口大小
 * @return      所有窗口的最大值数组
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;  // 存储结果
    deque<int> q;        // 双端队列，存储元素下标
    
    for (int i = 0; i < nums.size(); i++) {
        // 1. 移除队列中所有小于当前元素的值
        // 这样保证队列中元素单调递减
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        
        // 2. 将当前元素的下标加入队列尾部
        q.push_back(i);
        
        // 3. 如果队首元素已经不在当前窗口内，将其移除
        if (q.front() <= i - k) {
            q.pop_front();
        }
        
        // 4. 当窗口形成后（至少有k个元素），记录当前窗口的最大值
        if (i >= k - 1) {
            result.push_back(nums[q.front()]);
        }
    }
    
    return result;
}

/**
 * 滑动窗口最小值问题
 * 
 * @param nums  输入数组
 * @param k     窗口大小
 * @return      所有窗口的最小值数组
 */
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> q;
    
    for (int i = 0; i < nums.size(); i++) {
        // 1. 移除队列中所有大于当前元素的值（与最大值问题相反）
        // 保证队列中元素单调递增
        while (!q.empty() && nums[q.back()] > nums[i]) {
            q.pop_back();
        }
        
        // 2. 将当前元素的下标加入队列尾部
        q.push_back(i);
        
        // 3. 如果队首元素已经不在当前窗口内，将其移除
        if (q.front() <= i - k) {
            q.pop_front();
        }
        
        // 4. 当窗口形成后，记录当前窗口的最小值
        if (i >= k - 1) {
            result.push_back(nums[q.front()]);
        }
    }
    
    return result;
}

/**
 * 单调队列的扩展应用：求数组中每个元素左右两侧第一个比它大/小的元素
 * 
 * 这种问题在很多场景下都有应用，比如求直方图中最大矩形面积
 * 
 * @param nums  输入数组
 * @return      二维数组，每个元素包含两个值：左侧第一个大于当前元素的下标和右侧第一个大于当前元素的下标
 */
vector<vector<int>> findGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result(n, vector<int>(2, -1));  // 初始化为-1，表示不存在
    deque<int> q;  // 单调递减队列
    
    // 找右侧第一个大于当前元素的元素
    for (int i = 0; i < n; i++) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            result[q.back()][1] = i;  // 更新结果
            q.pop_back();
        }
        q.push_back(i);
    }
    
    q.clear();  // 清空队列
    
    // 找左侧第一个大于当前元素的元素
    for (int i = n - 1; i >= 0; i--) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            result[q.back()][0] = i;  // 更新结果
            q.pop_back();
        }
        q.push_back(i);
    }
    
    return result;
}

// 使用示例
void demonstrateMonotonicQueue() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    cout << "原数组: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "窗口大小: " << k << endl;
    
    // 滑动窗口最大值
    vector<int> maxValues = maxSlidingWindow(nums, k);
    cout << "滑动窗口最大值: ";
    for (int val : maxValues) cout << val << " ";
    cout << endl;
    
    // 滑动窗口最小值
    vector<int> minValues = minSlidingWindow(nums, k);
    cout << "滑动窗口最小值: ";
    for (int val : minValues) cout << val << " ";
    cout << endl;
    
    // 查找每个元素左右两侧第一个比它大的元素
    vector<vector<int>> greaterElements = findGreaterElements(nums);
    cout << "每个元素左右两侧第一个比它大的元素下标:" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << "元素 " << nums[i] << " 的左侧: " << greaterElements[i][0] 
             << ", 右侧: " << greaterElements[i][1] << endl;
    }
}

int main() {
    demonstrateMonotonicQueue();
    return 0;
}
