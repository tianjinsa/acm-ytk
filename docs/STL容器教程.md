# C++ STL容器教程

## 📚 目录

- [简介](#简介)
- [STL容器分类](#stl容器分类)
- [顺序容器](#顺序容器)
  - [vector](#vector)
  - [list](#list)
  - [deque](#deque)
- [关联容器](#关联容器)
  - [set](#set)
  - [map](#map)
  - [unordered_set](#unordered_set)
  - [unordered_map](#unordered_map)
- [容器适配器](#容器适配器)
  - [stack](#stack)
  - [queue](#queue)
  - [priority_queue](#priority_queue)
- [实战练习](#实战练习)
- [常见问题解答](#常见问题解答)

## 简介

STL (Standard Template Library) 是C++标准库的一部分，提供了一系列通用的容器、算法和迭代器。本教程将帮助你理解并掌握STL中常用的容器类型。

## STL容器分类

STL容器可以分为三大类：
1. **顺序容器**: 按照线性顺序存储元素，如vector、list和deque
2. **关联容器**: 按照特定的排序规则存储元素，如set、map、unordered_set和unordered_map
3. **容器适配器**: 基于其他容器实现的接口，如stack、queue和priority_queue

## 顺序容器

### vector

`vector`是最常用的STL容器，它是一个动态数组，支持快速随机访问。

#### 特点：
- ✅ 随机访问元素 - O(1)
- ✅ 尾部添加/删除元素 - 平均O(1)
- ❌ 中间插入/删除元素 - O(n)

#### 基本用法：

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // 创建vector
    vector<int> nums;
    
    // 添加元素
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    
    // 访问元素
    cout << "第一个元素: " << nums[0] << endl;       // 使用[]
    cout << "第二个元素: " << nums.at(1) << endl;    // 使用at()，有边界检查
    
    // 遍历方式1：下标
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    // 遍历方式2：迭代器
    for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 遍历方式3：范围for循环(C++11)
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

#### 常用操作：

| 操作 | 描述 | 时间复杂度 |
|------|------|-----------|
| `push_back(item)` | 在尾部添加元素 | 平均O(1) |
| `pop_back()` | 删除尾部元素 | O(1) |
| `insert(pos, item)` | 在指定位置插入元素 | O(n) |
| `erase(pos)` | 删除指定位置的元素 | O(n) |
| `size()` | 返回元素个数 | O(1) |
| `empty()` | 判断是否为空 | O(1) |
| `clear()` | 清空容器 | O(n) |

### list

`list`是一个双向链表，支持在任何位置快速插入和删除元素。

#### 特点：
- ❌ 随机访问元素 - O(n)
- ✅ 在任何位置插入/删除元素 - O(1)

#### 基本用法：

```cpp
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> myList;
    
    // 添加元素
    myList.push_back(10);    // 尾部添加
    myList.push_front(5);    // 头部添加
    myList.push_back(15);
    
    // 遍历
    cout << "链表内容: ";
    for (const auto& num : myList) {
        cout << num << " ";  // 输出: 5 10 15
    }
    cout << endl;
    
    // 删除元素
    myList.pop_front();      // 删除头部
    myList.pop_back();       // 删除尾部
    
    cout << "删除后: ";
    for (const auto& num : myList) {
        cout << num << " ";  // 输出: 10
    }
    cout << endl;
    
    return 0;
}
```

### deque

`deque`(双端队列)支持在两端快速插入和删除元素。

#### 特点：
- ✅ 随机访问元素 - O(1)
- ✅ 在两端添加/删除元素 - O(1)
- ❌ 中间插入/删除元素 - O(n)

#### 基本用法：

```cpp
#include <deque>
#include <iostream>
using namespace std;

int main() {
    deque<int> myDeque;
    
    // 添加元素
    myDeque.push_back(10);   // 尾部添加
    myDeque.push_front(5);   // 头部添加
    myDeque.push_back(15);
    
    cout << "deque内容: ";
    for (const auto& num : myDeque) {
        cout << num << " ";  // 输出: 5 10 15
    }
    cout << endl;
    
    // 访问元素
    cout << "第一个元素: " << myDeque.front() << endl;
    cout << "最后一个元素: " << myDeque.back() << endl;
    
    return 0;
}
```

## 关联容器

### set

`set`是一个有序集合，元素按照键值排序，且不允许重复元素。

#### 特点：
- ✅ 查找、插入和删除都是O(log n)
- ✅ 自动排序
- ✅ 不允许重复元素

#### 基本用法：

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> mySet;
    
    // 插入元素
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // 重复元素不会被插入
    
    // 遍历 - 将按升序输出: 10 20 30
    cout << "set内容: ";
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 查找元素
    auto it = mySet.find(20);
    if (it != mySet.end()) {
        cout << "找到元素: " << *it << endl;
    }
    
    // 删除元素
    mySet.erase(10);
    
    cout << "删除后: ";
    for (const auto& elem : mySet) {
        cout << elem << " ";  // 输出: 20 30
    }
    cout << endl;
    
    return 0;
}
```

### map

`map`存储键值对，按照键排序，且键不能重复。

#### 特点：
- ✅ 通过键快速查找值 - O(log n)
- ✅ 键值自动排序
- ✅ 键不允许重复

#### 基本用法：

```cpp
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string, int> scores;
    
    // 插入元素
    scores["Alice"] = 95;
    scores["Bob"] = 89;
    scores.insert({"Charlie", 78});
    
    // 访问元素
    cout << "Bob的分数: " << scores["Bob"] << endl;
    
    // 遍历 - 将按键名字母顺序输出
    cout << "所有分数:\n";
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 检查键是否存在
    if (scores.count("David") == 0) {
        cout << "David不在记录中" << endl;
    }
    
    return 0;
}
```

### unordered_set

`unordered_set`是无序集合，使用哈希表实现。

#### 特点：
- ✅ 查找、插入和删除平均是O(1)
- ❌ 元素不保证有序
- ✅ 不允许重复元素

#### 基本用法：

```cpp
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    unordered_set<int> mySet;
    
    // 插入元素
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    
    // 遍历 - 顺序不确定
    cout << "unordered_set内容: ";
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}
```

### unordered_map

`unordered_map`是无序键值对映射，使用哈希表实现。

#### 特点：
- ✅ 通过键查找值平均是O(1)
- ❌ 键值不保证有序
- ✅ 键不允许重复

#### 基本用法类似map，但使用哈希表实现，通常查找更快。

## 容器适配器

### stack

`stack`是一个后进先出(LIFO)的容器适配器。

```cpp
#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> myStack;
    
    // 添加元素
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "栈顶元素: " << myStack.top() << endl;  // 30
    
    // 移除元素
    myStack.pop();
    cout << "移除一个元素后的栈顶: " << myStack.top() << endl;  // 20
    
    cout << "栈大小: " << myStack.size() << endl;
    
    return 0;
}
```

### queue

`queue`是一个先进先出(FIFO)的容器适配器。

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> myQueue;
    
    // 添加元素
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    cout << "队首: " << myQueue.front() << endl;  // 10
    cout << "队尾: " << myQueue.back() << endl;   // 30
    
    // 移除元素
    myQueue.pop();
    cout << "移除一个元素后的队首: " << myQueue.front() << endl;  // 20
    
    return 0;
}
```

### priority_queue

`priority_queue`是一个优先队列，默认最大元素在队首。

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    // 默认最大元素优先
    priority_queue<int> maxPQ;
    
    maxPQ.push(10);
    maxPQ.push(30);
    maxPQ.push(20);
    
    cout << "最大优先队列的顶部: " << maxPQ.top() << endl;  // 30
    
    // 最小元素优先
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);
    
    cout << "最小优先队列的顶部: " << minPQ.top() << endl;  // 10
    
    return 0;
}
```

## 实战练习

### 练习1: 使用vector统计词频

```cpp
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    map<string, int> frequency;
    
    // 统计词频
    for (const auto& word : words) {
        frequency[word]++;
    }
    
    // 输出结果
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    return 0;
}
```

### 练习2: 使用set去除重复元素

```cpp
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> numbers = {1, 5, 2, 1, 6, 3, 5, 4, 3};
    set<int> uniqueNumbers(numbers.begin(), numbers.end());
    
    cout << "原始数组: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "去重后: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

## 常见问题解答

### 1. 我该使用哪种容器？

- 需要频繁随机访问元素 → `vector`
- 需要频繁在中间位置插入/删除元素 → `list`
- 需要在两端快速操作 → `deque`
- 需要按键查找元素且保持有序 → `map`/`set`
- 需要最快的查找速度且不在意顺序 → `unordered_map`/`unordered_set`

### 2. vector和数组有什么区别？

- vector是动态的，可以改变大小
- vector提供更多成员函数和安全检查
- vector在堆上分配内存，普通数组可以在栈上
- vector会自动管理内存，不需要手动释放

### 3. 如何高效地使用STL容器？

- 理解每种容器的优缺点和适用场景
- 尽量使用STL提供的算法而不是自己实现
- 使用适当的迭代方式，如范围for循环
- 避免不必要的拷贝，使用引用和移动语义

### 4. 为什么有时需要自定义比较函数？

在排序或使用有序容器时，有时需要自定义元素的比较方式：

```cpp
struct Person {
    string name;
    int age;
};

// 自定义比较函数，按年龄排序
struct CompareByAge {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

// 使用自定义比较函数
set<Person, CompareByAge> personSet;
```

记住，掌握STL容器需要实践！通过解决实际问题来巩固你的理解。

---
如有疑问或需要更多示例，请随时提问！
