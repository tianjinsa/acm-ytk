#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

// 这个文件包含STL容器的示例代码，配合教程使用

// vector示例
void vectorExample() {
    cout << "\n===== Vector示例 =====\n";
    
    vector<int> nums = {10, 20, 30, 40, 50};
    
    cout << "原始vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // 添加和删除元素
    nums.push_back(60);
    nums.pop_back();
    
    // 在中间插入元素
    nums.insert(nums.begin() + 2, 25);
    
    cout << "修改后的vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // 使用迭代器
    cout << "使用迭代器遍历: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 使用algorithm
    sort(nums.begin(), nums.end(), greater<int>());
    cout << "降序排序后: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// list示例
void listExample() {
    cout << "\n===== List示例 =====\n";
    
    list<int> myList = {10, 20, 30};
    
    cout << "原始list: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;
    
    myList.push_front(5);
    myList.push_back(40);
    
    cout << "添加元素后: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;
    
    // 在中间插入
    auto it = myList.begin();
    advance(it, 2);  // 移动迭代器到第三个位置
    myList.insert(it, 15);
    
    cout << "插入15后: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;
    
    // 删除元素
    myList.remove(20); // 删除所有值为20的元素
    
    cout << "删除20后: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;
}

// set和map示例
void setMapExample() {
    cout << "\n===== Set和Map示例 =====\n";
    
    // set示例
    set<int> mySet = {50, 30, 10, 20, 40};
    
    cout << "set内容(自动排序): ";
    for (int num : mySet) {
        cout << num << " ";
    }
    cout << endl;
    
    // 检查元素是否存在
    if (mySet.find(30) != mySet.end()) {
        cout << "30在set中" << endl;
    }
    
    // map示例
    map<string, int> scores = {
        {"Alice", 95},
        {"Bob", 87},
        {"Charlie", 92}
    };
    
    cout << "学生成绩:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 添加新元素
    scores["David"] = 78;
    // 修改已有元素
    scores["Bob"] = 89;
    
    cout << "修改后的成绩:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// 无序容器示例
void unorderedContainersExample() {
    cout << "\n===== 无序容器示例 =====\n";
    
    unordered_set<int> hashSet = {5, 3, 1, 4, 2};
    
    cout << "unordered_set内容(无序): ";
    for (int num : hashSet) {
        cout << num << " ";
    }
    cout << endl;
    
    unordered_map<string, string> capitalCities = {
        {"中国", "北京"},
        {"美国", "华盛顿"},
        {"法国", "巴黎"}
    };
    
    cout << "国家及其首都:" << endl;
    for (const auto& pair : capitalCities) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 查找操作
    auto it = capitalCities.find("中国");
    if (it != capitalCities.end()) {
        cout << "中国的首都是: " << it->second << endl;
    }
}

// 适配器示例
void adaptersExample() {
    cout << "\n===== 容器适配器示例 =====\n";
    
    // 栈示例
    stack<string> bookStack;
    bookStack.push("书1");
    bookStack.push("书2");
    bookStack.push("书3");
    
    cout << "栈顶的书: " << bookStack.top() << endl;
    bookStack.pop();
    cout << "移除一本后栈顶的书: " << bookStack.top() << endl;
    
    // 队列示例
    queue<string> peopleQueue;
    peopleQueue.push("张三");
    peopleQueue.push("李四");
    peopleQueue.push("王五");
    
    cout << "队首的人: " << peopleQueue.front() << endl;
    cout << "队尾的人: " << peopleQueue.back() << endl;
    
    // 优先队列示例(默认最大堆)
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    cout << "优先队列顶部(最大值): " << pq.top() << endl;
    pq.pop();
    cout << "移除最大值后的顶部: " << pq.top() << endl;
    
    // 最小堆示例
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    
    cout << "最小堆顶部(最小值): " << minHeap.top() << endl;
}

// 实用示例: 用STL解决简单问题
void practicalExample() {
    cout << "\n===== 实用示例 =====\n";
    
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // 1. 排序并去重
    sort(numbers.begin(), numbers.end());
    auto last = unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    
    cout << "排序并去重后: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 2. 计算元素出现次数
    vector<string> fruits = {"apple", "banana", "apple", "orange", "banana", "apple"};
    map<string, int> fruitCount;
    
    for (const auto& fruit : fruits) {
        fruitCount[fruit]++;
    }
    
    cout << "水果统计:" << endl;
    for (const auto& pair : fruitCount) {
        cout << pair.first << ": " << pair.second << " 次" << endl;
    }
    
    // 3. 查找最大和最小值
    vector<int> data = {15, 8, 23, 4, 42, 16};
    auto minmax = minmax_element(data.begin(), data.end());
    
    cout << "最小值: " << *minmax.first << endl;
    cout << "最大值: " << *minmax.second << endl;
}

int main() {
    cout << "===== STL容器示例程序 =====\n";
    
    int choice;
    do {
        cout << "\n选择要运行的示例:\n";
        cout << "1. Vector示例\n";
        cout << "2. List示例\n";
        cout << "3. Set和Map示例\n";
        cout << "4. 无序容器示例\n";
        cout << "5. 适配器(Stack/Queue)示例\n";
        cout << "6. 实用示例\n";
        cout << "7. 运行所有示例\n";
        cout << "0. 退出\n";
        cout << "请输入选择: ";
        cin >> choice;
        
        switch(choice) {
            case 1: vectorExample(); break;
            case 2: listExample(); break;
            case 3: setMapExample(); break;
            case 4: unorderedContainersExample(); break;
            case 5: adaptersExample(); break;
            case 6: practicalExample(); break;
            case 7: 
                vectorExample();
                listExample();
                setMapExample();
                unorderedContainersExample();
                adaptersExample();
                practicalExample();
                break;
            case 0: cout << "退出程序\n"; break;
            default: cout << "无效选择，请重试\n";
        }
    } while (choice != 0);
    
    return 0;
}
