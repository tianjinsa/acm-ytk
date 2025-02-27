# C++ STL容器使用指南

> 本文档详细介绍了 C++ STL 容器的分类、使用方法、底层实现原理、性能对比及最佳实践。特别说明各容器在内存管理、迭代器失效和异常安全方面的细节，帮助读者更深入地理解和应用 STL 提供的各个容器。

## 目录

- [容器分类](#容器分类)
  - [序列式容器](#序列式容器)
    - [vector](#vector-动态数组)
    - [deque](#deque-双端队列)
    - [list](#list-双向链表)
  - [关联式容器](#关联式容器)
    - [set](#set-有序集合)
    - [multiset](#multiset-有序多重集合)
    - [map](#map-有序键值对)
    - [multimap](#multimap-有序多重映射)
  - [无序关联式容器](#无序关联式容器)
    - [unordered_set](#unordered_set-哈希集合)
    - [unordered_map](#unordered_map-哈希表)
  - [容器适配器](#容器适配器)
    - [queue](#queue-队列)
    - [priority_queue](#priority_queue-优先队列)
    - [stack](#stack-栈)
  - [位集合](#位集合)
    - [bitset](#bitset-固定大小位容器)
- [性能对比](#性能对比)
- [最佳实践](#最佳实践)
- [查找操作详解](#查找操作详解)

# 序列式容器

## vector-动态数组

> **核心特点**：连续内存、动态扩容、高效随机访问、尾部操作高效

动态数组（`vector`）是最常用的容器。它的内存是连续分配的，因此支持快速随机访问；但当容量不足时，会按照一定的扩展策略（通常是倍增扩容）进行内存重新分配，这可能导致所有迭代器失效。  

### 详细说明  

- **内存管理**：内存扩容通常遵循几何级增长（如1.5倍或2倍），确保插入元素的均摊时间复杂度为 O(1)
- **迭代器稳定性**：迭代器和指针在重新分配时全部失效，需要注意使用返回的迭代器或重新获取索引
- **异常安全**：提供如`at()`的边界检查函数，在访问越界时抛出`std::out_of_range`异常
- **性能特点**：随机访问O(1)，尾部插入均摊O(1)，中间或头部插入O(n)

> 💡 **小贴士**：适用于需要快速随机访问和尾部操作的场景。例如，存储一组数据，并需要频繁访问其中的元素。

### 使用场景

- **需要频繁随机访问元素**：`vector` 提供了高效的随机访问能力，可以通过索引直接访问元素
- **主要在尾部进行插入和删除操作**：在尾部插入和删除元素的时间复杂度为 O(1)，效率很高
- **需要动态改变容器大小**：`vector` 可以根据需要动态调整大小，方便存储不确定数量的元素
- **需要与C风格数组互操作**：通过`data()`方法可获取底层连续内存指针

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push_back(const T& value)` | 将元素添加到容器末尾 | `vec.push_back(5);` <br>// 在末尾添加数值5 | 均摊O(1) |
| `pop_back()` | 移除末尾元素（不返回值） | `vec.pop_back();` <br>// 删除最后一个元素 | O(1) |
| `size()` | 返回容器中的元素数量 | `size_t len = vec.size();` <br>// 获取元素个数 | O(1) |
| `empty()` | 检查容器是否为空 | `if(vec.empty()) {...}` <br>// 判断是否为空 | O(1) |
| `at(size_t pos)` | 访问指定位置元素（带边界检查） | `int val = vec.at(3);` <br>// 访问索引3的元素，越界会抛出异常 | O(1) |
| `operator[]` | 访问指定位置元素（无边界检查） | `int val = vec[0];` <br>// 访问首个元素，越界行为未定义 | O(1) |
| `clear()` | 清空所有元素 | `vec.clear();` <br>// 移除所有元素，容量不变 | O(n) |
| `insert(iterator pos, const T& value)` | 在指定位置插入元素 | `auto it = vec.insert(vec.begin()+2, 10);` <br>// 在索引2的位置插入值10 | O(n) |
| `erase(iterator pos)` | 删除指定位置的元素 | `auto it = vec.erase(vec.begin()+1);` <br>// 删除索引1位置的元素 | O(n) |
| `emplace_back(Args&&... args)` | 在末尾原位构造元素 | `vec.emplace_back(42);` <br>// 直接构造值为42的元素 | 均摊O(1) |
| `reserve(size_t capacity)` | 预留容量空间但不创建元素 | `vec.reserve(100);` <br>// 预留100个元素的空间，减少重新分配次数 | 最坏O(n) |
| `resize(size_t count)` | 调整容器大小 | `vec.resize(5);` <br>// 调整大小为5个元素，多余的会被移除，不足的用默认值填充 | 最坏O(n) |
| `capacity()` | 返回当前分配的容量 | `size_t cap = vec.capacity();` <br>// 获取容器当前容量 | O(1) |
| `front()` | 返回首元素的引用 | `int first = vec.front();` <br>// 获取第一个元素值 | O(1) |
| `back()` | 返回末元素的引用 | `int last = vec.back();` <br>// 获取最后一个元素值 | O(1) |
| `data()` | 返回指向数据的指针 | `int* ptr = vec.data();` <br>// 获取底层数组指针，方便与C函数交互 | O(1) |
| `shrink_to_fit()` | 减少内存到适合大小 | `vec.shrink_to_fit();` <br>// 释放未使用的内存空间 | O(n) |
| `assign(size_t count, const T& value)` | 替换容器内容 | `vec.assign(3, 0);` <br>// 用3个0替换当前内容 | O(n) |
| `swap(vector& other)` | 与另一容器交换内容 | `vec1.swap(vec2);` <br>// 交换两个vector的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::vector<int> vec1;                    // 默认构造，空容器
std::vector<int> vec2(5, 10);             // 构造包含5个值为10的元素
std::vector<int> vec3 = {1, 2, 3, 4, 5};  // 使用初始化列表
std::vector<int> vec4(vec3.begin(), vec3.end());  // 使用迭代器范围构造
```

### 添加删除元素示例

```cpp
// 添加元素
vec1.push_back(15);          // 在末尾添加元素15
vec1.emplace_back(20);       // 在末尾直接构造元素20（通常比push_back高效）

// 在指定位置添加元素
auto it = vec1.begin() + 1;  // 指向第二个元素的迭代器
vec1.insert(it, 25);         // 在第二个位置插入25
vec1.emplace(it, 30);        // 在第二个位置原位构造30

// 删除元素
vec1.pop_back();             // 移除最后一个元素
vec1.erase(vec1.begin());    // 删除第一个元素
vec1.erase(vec1.begin(), vec1.begin() + 2);  // 删除前两个元素

// 清空容器
vec1.clear();                // 移除所有元素
```

### 访问元素示例

```cpp
// 多种元素访问方式
int first = vec1.front();    // 获取第一个元素
int last = vec1.back();      // 获取最后一个元素
int third = vec1[2];         // 直接访问索引2的元素（不检查边界）
int fourth = vec1.at(3);     // 访问索引3的元素（带边界检查）

// 使用迭代器遍历
for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    std::cout << *it << " ";
}
// 使用范围for循环（C++11起）
for (const auto& item : vec1) {
    std::cout << item << " ";
}
```

### 容量操作示例

```cpp
// 容量管理
vec1.reserve(100);            // 预分配存储空间，减少重新分配
size_t current_capacity = vec1.capacity();  // 获取当前容量
vec1.resize(50);             // 调整大小为50个元素
vec1.resize(75, -1);         // 增大到75个元素，新元素用-1填充
vec1.shrink_to_fit();        // 释放多余的内存
```

### 其他常用操作

```cpp
// 排序和反转
std::sort(vec1.begin(), vec1.end());              // 升序排序整个vector
std::sort(vec1.begin(), vec1.end(), std::greater<int>()); // 降序排序
std::reverse(vec1.begin(), vec1.end());           // 反转元素顺序

// 查找元素
auto it = std::find(vec1.begin(), vec1.end(), 42);
if (it != vec1.end()) {
    std::cout << "找到元素42，位置：" << std::distance(vec1.begin(), it) << std::endl;
}

// 拼接操作
std::vector<int> vec4 = {6, 7, 8};
vec1.insert(vec1.end(), vec4.begin(), vec4.end());  // 将vec4的所有元素追加到vec1末尾

// 使用data()与C风格函数交互
void legacy_function(int* array, size_t size) { /*...*/ }
legacy_function(vec1.data(), vec1.size());
```

### vector迭代器失效情况总结

1. **添加元素时**：
   - 如果导致内存重新分配，则所有迭代器和引用都会失效
   - 如果没有导致重新分配，则插入点之前的迭代器有效，之后的失效

2. **删除元素时**：
   - 被删除位置之前的迭代器有效
   - 被删除位置及之后的迭代器全部失效

```cpp
// 处理迭代器失效的正确方法
auto it = vec.begin() + 3;
it = vec.insert(it, 42);  // insert返回指向新插入元素的迭代器
it = vec.erase(it);       // erase返回指向被删除元素之后的迭代器
```

## deque-双端队列

> **核心特点**：分段连续内存、两端高效插入删除、随机访问

双端队列采用分段连续内存存储，每段固定大小，这使得两端的插入及删除操作非常高效。  

### 详细说明  

- **内存管理**：deque 采用分段连续内存存储，支持在两端 O(1) 时间复杂度的插入和删除操作
- **迭代器稳定性**：分段存储使得 deque 可以在两端进行常数时间的操作，缺点是在中间插入时需要移动块指针，可能丢失部分迭代器
- **异常安全**：与 vector 不同，deque 不支持 reserve 操作，原因在于其非连续内存结构
- **性能特点**：两端插入删除O(1)，中间插入删除O(n)，随机访问O(1)

> 💡 **注意**：deque 不支持 reserve 操作，请参照示例使用。

### 使用场景

- **需要在两端频繁插入和删除元素**：deque 的两端操作都是 O(1) 复杂度
- **需要随机访问元素**：支持下标访问，与 vector 类似
- **对中间元素的插入删除操作相对较少**：中间操作效率低于两端操作
- **不希望因容量改变导致迭代器全部失效**：相较于 vector，deque 在容量变化时只有部分迭代器失效

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push_front(const T& value)` | 在容器前端添加元素 | `deq.push_front(10);` <br>// 在开始位置插入值10 | O(1) |
| `push_back(const T& value)` | 在容器末尾添加元素 | `deq.push_back(20);` <br>// 在末尾添加值20 | O(1) |
| `pop_front()` | 移除前端元素 | `deq.pop_front();` <br>// 删除第一个元素 | O(1) |
| `pop_back()` | 移除末尾元素 | `deq.pop_back();` <br>// 删除最后一个元素 | O(1) |
| `size()` | 获取元素个数 | `size_t len = deq.size();` <br>// 获取元素数量 | O(1) |
| `empty()` | 检查是否为空 | `if(deq.empty()) {...}` <br>// 判断容器是否为空 | O(1) |
| `at(size_t pos)` | 访问指定位置元素(带边界检查) | `int val = deq.at(2);` <br>// 安全访问索引2的元素 | O(1) |
| `operator[size_t pos]` | 访问指定位置元素(不检查边界) | `int val = deq[0];` <br>// 直接访问首个元素 | O(1) |
| `clear()` | 清空所有元素 | `deq.clear();` <br>// 移除所有元素 | O(n) |
| `insert(iterator pos, const T& value)` | 在指定位置插入元素 | `auto it = deq.insert(deq.begin()+1, 15);` <br>// 在第二个位置插入15 | O(n) |
| `erase(iterator pos)` | 删除指定位置的元素 | `auto it = deq.erase(deq.begin());` <br>// 删除首个元素 | O(n) |
| `emplace_front(Args&&... args)` | 在前端原位构造元素 | `deq.emplace_front(5);` <br>// 在开头直接构造元素5 | O(1) |
| `emplace_back(Args&&... args)` | 在末尾原位构造元素 | `deq.emplace_back(25);` <br>// 在末尾直接构造元素25 | O(1) |
| `resize(size_t count)` | 调整容器大小 | `deq.resize(10);` <br>// 调整大小为10个元素 | 最坏O(n) |
| `front()` | 返回首元素的引用 | `int first = deq.front();` <br>// 获取第一个元素 | O(1) |
| `back()` | 返回末元素的引用 | `int last = deq.back();` <br>// 获取最后一个元素 | O(1) |
| `shrink_to_fit()` | 减少内存到适合大小 | `deq.shrink_to_fit();` <br>// 释放未使用的内存（C++11起） | O(n) |
| `assign(size_t count, const T& value)` | 替换容器内容 | `deq.assign(5, 1);` <br>// 用5个值为1的元素替换内容 | O(n) |
| `swap(deque& other)` | 与另一容器交换内容 | `deq1.swap(deq2);` <br>// 交换两个deque的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::deque<int> deq1;                     // 默认构造，空队列
std::deque<int> deq2(5, 10);              // 5个值为10的元素
std::deque<int> deq3 = {1, 2, 3, 4, 5};   // 使用初始化列表
std::deque<int> deq4(deq3.begin(), deq3.begin() + 3);  // 使用迭代器范围构造
```

### 两端添加删除示例

```cpp
// 前端操作
deq1.push_front(50);          // 在前端添加元素50
deq1.emplace_front(40);       // 在前端原位构造元素40
deq1.pop_front();             // 移除前端元素

// 后端操作
deq1.push_back(60);           // 在末尾添加元素60
deq1.emplace_back(70);        // 在末尾原位构造元素70
deq1.pop_back();              // 移除末尾元素
```

### 中间插入删除示例

```cpp
// 中间位置操作
auto mid_it = deq1.begin() + deq1.size() / 2;  // 中间位置迭代器
deq1.insert(mid_it, 30);      // 在中间插入元素30
deq1.erase(mid_it);           // 删除中间位置的元素
```

### 访问元素示例

```cpp
// 访问元素
int first = deq1.front();     // 获取第一个元素
int last = deq1.back();       // 获取最后一个元素
int third = deq1[2];          // 通过索引访问（不检查边界）
int fourth = deq1.at(3);      // 通过at访问（会检查边界）

// 遍历元素
for (auto it = deq1.begin(); it != deq1.end(); ++it) {
    std::cout << *it << " ";
}
// 使用范围for循环
for (const auto& elem : deq1) {
    std::cout << elem << " ";
}
```

### 容量管理示例

```cpp
// 容量相关操作
size_t sz = deq1.size();      // 获取元素数量
bool is_empty = deq1.empty(); // 检查是否为空
deq1.resize(10);              // 调整大小为10个元素
deq1.resize(15, -1);          // 调整为15个元素，新元素用-1填充
deq1.shrink_to_fit();         // 减少内存占用（C++11起）
```

### 其他常用操作

```cpp
// 排序和反转
std::sort(deq1.begin(), deq1.end());  // 升序排序
std::reverse(deq1.begin(), deq1.end()); // 反转元素顺序

// 查找操作
auto find_it = std::find(deq1.begin(), deq1.end(), 30);
if (find_it != deq1.end()) {
    std::cout << "找到元素30" << std::endl;
}

// 拼接操作
std::deque<int> deq5 = {100, 200, 300};
deq1.insert(deq1.end(), deq5.begin(), deq5.end());  // 将deq5拼接到deq1末尾
```

### deque与vector的区别

- **内存分配**：deque 使用分段连续内存，vector 使用单一连续内存
- **扩容策略**：deque 不需要像 vector 那样整体重新分配
- **两端操作**：deque 支持高效的两端操作，vector 只支持高效的尾部操作
- **迭代器失效**：deque 的迭代器在插入删除时部分失效，vector 可能全部失效

```cpp
// 何时选择deque而非vector？
// 1. 需要频繁在两端添加删除元素
// 2. 不希望因容量变化导致全部迭代器失效
// 3. 元素数量较大且内存分配问题影响性能
```

## list-双向链表

> **核心特点**：节点分散存储、双向链接、高效中间插入删除

双向链表采用节点连续的内存链接，每个节点储存前后指针，允许在任意位置 O(1) 插入或删除，但不支持索引访问。  

### 详细说明  

- **内存管理**：由于节点分散存储，list 在迭代时的局部性不如 vector，但在频繁中间修改时非常高效
- **迭代器稳定性**：即使插入或删除操作不会使其他迭代器失效，操作前仍需定位目标位置，时间复杂度为 O(n)
- **异常安全**：list 的插入和删除操作不会抛出异常，除非内存分配失败
- **性能特点**：中间插入删除O(1)，随机访问O(n)

> 💡 **优点**：高效的中间插入删除；**缺点**：不支持随机访问。

### 使用场景

- **需要频繁在任意位置插入和删除元素**：list 的插入删除不会导致其他迭代器失效
- **不需要随机访问元素**：list 不支持下标访问，只能顺序遍历
- **需要频繁的元素重排**：list 的splice操作可以高效地合并、分割链表
- **元素需要在容器中保持稳定位置**：元素的位置不会因为插入删除而改变

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push_front(const T& value)` | 在链表开头添加元素 | `lst.push_front(10);` <br>// 在开头插入值10 | O(1) |
| `push_back(const T& value)` | 在链表末尾添加元素 | `lst.push_back(20);` <br>// 在末尾插入值20 | O(1) |
| `pop_front()` | 移除链表开头元素 | `lst.pop_front();` <br>// 删除第一个元素 | O(1) |
| `pop_back()` | 移除链表末尾元素 | `lst.pop_back();` <br>// 删除最后一个元素 | O(1) |
| `size()` | 获取元素个数 | `size_t len = lst.size();` <br>// 获取链表长度 | O(1) |
| `empty()` | 检查是否为空 | `if(lst.empty()) {...}` <br>// 判断链表是否为空 | O(1) |
| `clear()` | 清空所有元素 | `lst.clear();` <br>// 移除所有元素 | O(n) |
| `insert(iterator pos, const T& value)` | 在指定位置插入元素 | `auto it = lst.insert(pos, 30);` <br>// 在pos位置插入值30 | O(1) |
| `erase(iterator pos)` | 删除指定位置的元素 | `auto next_it = lst.erase(it);` <br>// 删除it指向的元素 | O(1) |
| `emplace_front(Args&&... args)` | 在开头原位构造元素 | `lst.emplace_front(5);` <br>// 在开头直接构造元素5 | O(1) |
| `emplace_back(Args&&... args)` | 在末尾原位构造元素 | `lst.emplace_back(25);` <br>// 在末尾直接构造元素25 | O(1) |
| `resize(size_t count)` | 调整链表大小 | `lst.resize(10);` <br>// 调整大小为10个元素 | O(n) |
| `front()` | 返回首元素的引用 | `int first = lst.front();` <br>// 获取第一个元素 | O(1) |
| `back()` | 返回末元素的引用 | `int last = lst.back();` <br>// 获取最后一个元素 | O(1) |
| `assign(size_t count, const T& value)` | 替换链表内容 | `lst.assign(5, 1);` <br>// 用5个值为1的元素替换内容 | O(n) |
| `swap(list& other)` | 与另一链表交换内容 | `lst1.swap(lst2);` <br>// 交换两个链表的内容 | O(1) |
| `splice(iterator pos, list& other)` | 将另一链表的所有元素移动到此链表 | `lst1.splice(lst1.begin(), lst2);` <br>// 将lst2的所有元素移到lst1开头 | O(1) |
| `merge(list& other)` | 合并两个有序链表 | `lst1.merge(lst2);` <br>// 将有序链表lst2合并入lst1 | O(n) |
| `unique()` | 移除相邻重复元素 | `lst.unique();` <br>// 删除连续重复的元素 | O(n) |
| `sort()` | 对链表进行排序 | `lst.sort();` <br>// 按升序排序链表 | O(n log n) |
| `reverse()` | 反转链表 | `lst.reverse();` <br>// 翻转链表元素顺序 | O(n) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::list<int> lst1;                      // 默认构造，空链表
std::list<int> lst2(5, 10);               // 5个值为10的元素
std::list<int> lst3 = {1, 2, 3, 4, 5};    // 使用初始化列表
std::list<int> lst4(lst3.begin(), std::next(lst3.begin(), 3)); // 使用迭代器范围构造
```

### 两端添加删除示例

```cpp
// 前端操作
lst1.push_front(50);           // 在开头添加元素50
lst1.emplace_front(40);        // 在开头原位构造元素40
lst1.pop_front();              // 移除开头元素

// 后端操作
lst1.push_back(60);            // 在末尾添加元素60
lst1.emplace_back(70);         // 在末尾原位构造元素70
lst1.pop_back();               // 移除末尾元素
```

### 中间插入删除示例

```cpp
// 中间位置操作
auto mid_it = std::next(lst1.begin(), lst1.size() / 2);  // 中间位置迭代器
lst1.insert(mid_it, 30);      // 在中间插入元素30
lst1.erase(mid_it);           // 删除中间位置的元素
```

### 访问元素示例

```cpp
// 访问元素
int first = lst1.front();     // 获取第一个元素
int last = lst1.back();       // 获取最后一个元素
int second = *(++lst1.begin()); // 访问第二个元素

// 遍历元素
for (auto it = lst1.begin(); it != lst1.end(); ++it) {
    std::cout << *it << " ";
}
// 使用范围for循环
for (const auto& elem : lst1) {
    std::cout << elem << " ";
}
```

### 容量管理示例

```cpp
// 容量相关操作
size_t sz = lst1.size();      // 获取元素数量
bool is_empty = lst1.empty(); // 检查是否为空
lst1.resize(10);              // 调整大小为10个元素
lst1.resize(15, -1);          // 调整为15个元素，新元素用-1填充
```

### 其他常用操作

```cpp
// 排序和反转
lst1.sort();                  // 升序排序
lst1.reverse();               // 反转元素顺序

// 查找操作
auto find_it = std::find(lst1.begin(), lst1.end(), 30);
if (find_it != lst1.end()) {
    std::cout << "找到元素30" << std::endl;
}

// 拼接操作
std::list<int> lst5 = {100, 200, 300};
lst1.splice(lst1.end(), lst5);  // 将lst5拼接到lst1末尾
```

### list与vector/deque的区别

- **内存分配**：list 使用节点分散存储，vector 和 deque 使用连续内存
- **访问方式**：list 只支持顺序访问，vector 和 deque 支持随机访问
- **插入删除**：list 在任意位置插入删除都是 O(1)，vector 和 deque 在中间位置插入删除是 O(n)
- **迭代器失效**：list 的迭代器在插入删除时不会失效，vector 和 deque 可能失效

```cpp
// 何时选择list而非vector/deque？
// 1. 需要频繁在中间位置插入删除元素
// 2. 不需要随机访问元素
// 3. 需要稳定的迭代器
```

## set-有序集合

> **核心特点**：自动排序、唯一元素、基于红黑树

有序集合基于平衡二叉树（通常为红黑树）实现，所有操作均具有 O(log n) 的时间复杂度。  

### 详细说明  

- **内存管理**：元素在插入时自动排好序，内存占用相对较大
- **迭代器稳定性**：迭代器稳定性较好，删除一个元素仅使该元素的迭代器失效
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：插入删除查找O(log n)

> 💡 **自动排序**，适合存储唯一且有序的元素。

### 使用场景

- **需要维护有序的唯一元素集合**：set 自动排序且不允许重复元素
- **需要快速查找元素**：set 的查找操作是 O(log n) 复杂度
- **需要范围查询功能**：set 提供 lower_bound 和 upper_bound 等接口

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `insert(const T& value)` | 插入元素 | `s.insert(10);` <br>// 插入值10 | O(log n) |
| `erase(const T& value)` | 删除指定元素 | `s.erase(10);` <br>// 删除值10 | O(log n) |
| `find(const T& value)` | 查找元素 | `auto it = s.find(10);` <br>// 查找值10 | O(log n) |
| `count(const T& value)` | 计算元素出现次数 | `size_t cnt = s.count(10);` <br>// 计算值10的出现次数 | O(log n) |
| `size()` | 获取元素个数 | `size_t len = s.size();` <br>// 获取元素数量 | O(1) |
| `empty()` | 检查是否为空 | `if(s.empty()) {...}` <br>// 判断容器是否为空 | O(1) |
| `clear()` | 清空所有元素 | `s.clear();` <br>// 移除所有元素 | O(n) |
| `emplace(Args&&... args)` | 原位插入元素 | `s.emplace(15);` <br>// 直接构造值为15的元素 | O(log n) |
| `lower_bound(const T& key)` | 返回第一个不小于key的迭代器 | `auto it = s.lower_bound(10);` <br>// 查找第一个不小于10的元素 | O(log n) |
| `upper_bound(const T& key)` | 返回第一个大于key的迭代器 | `auto it = s.upper_bound(10);` <br>// 查找第一个大于10的元素 | O(log n) |
| `equal_range(const T& key)` | 返回等于key的范围 | `auto range = s.equal_range(10);` <br>// 查找值10的范围 | O(log n) |
| `swap(set& other)` | 与另一容器交换内容 | `s1.swap(s2);` <br>// 交换两个set的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::set<int> s1;                      // 默认构造，空集合
std::set<int> s2 = {1, 2, 3, 4, 5};    // 使用初始化列表
std::set<int> s3(s2.begin(), s2.end()); // 使用迭代器范围构造
```

### 添加删除元素示例

```cpp
// 添加元素
s1.insert(10);             // 插入值10
s1.emplace(15);            // 直接构造值为15的元素

// 删除元素
s1.erase(10);              // 删除值10
s1.erase(s1.begin());      // 删除第一个元素
```

### 查找元素示例

```cpp
// 查找元素
auto it = s1.find(15);     // 查找值15
if (it != s1.end()) {
    std::cout << "找到元素15" << std::endl;
}

// 计算元素出现次数
size_t cnt = s1.count(15); // 计算值15的出现次数

// 范围查询
auto lower = s1.lower_bound(10); // 查找第一个不小于10的元素
auto upper = s1.upper_bound(10); // 查找第一个大于10的元素
auto range = s1.equal_range(10); // 查找值10的范围
```

### 访问元素示例

```cpp
// 访问元素
for (auto it = s1.begin(); it != s1.end(); ++it) {
    std::cout << *it << " ";
}
// 使用范围for循环
for (const auto& elem : s1) {
    std::cout << elem << " ";
}
```

### 其他常用操作

```cpp
// 清空集合
s1.clear();                // 移除所有元素

// 交换集合
s1.swap(s2);               // 交换s1和s2的内容
```

### set与unordered_set的区别

- **内存分配**：set 使用红黑树，unordered_set 使用哈希表
- **访问方式**：set 自动排序，unordered_set 无序
- **查找效率**：set 的查找是 O(log n)，unordered_set 是 O(1)
- **迭代器失效**：set 的迭代器在插入删除时不会失效，unordered_set 可能失效

```cpp
// 何时选择set而非unordered_set？
// 1. 需要有序存储元素
// 2. 需要范围查询功能
// 3. 需要稳定的迭代器
```

## multiset-有序多重集合

允许存储重复的元素，并按照升序自动排序。
使用场景：需要记录重复值且希望元素自动排序时。

```cpp
std::multiset<int> ms;
ms.insert(10);
ms.insert(10); // 重复元素允许
```

## map-有序键值对

> **核心特点**：键值对、自动排序、基于红黑树

有序映射和 set 类似，底层也使用红黑树。  

### 详细说明  

- **内存管理**：当使用 operator[] 进行元素访问时，如果键不存在，则会自动插入默认值，可能引起额外的内存分配和树重平衡
- **迭代器稳定性**：提供 lower_bound、upper_bound 等接口，便于高效的范围查询
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：插入删除查找O(log n)

> 💡 **用于建立键值对应关系，并保持键的排序**。

### 使用场景

- **需要建立键到值的映射关系**：map 提供键值对存储
- **需要按键的顺序访问元素**：map 自动按键排序
- **需要高效的键值查找**：map 的查找操作是 O(log n) 复杂度

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `insert(const std::pair<const Key, T>& value)` | 插入键值对 | `m.insert({3, "three"});` <br>// 插入键值对(3, "three") | O(log n) |
| `erase(const Key& key)` | 删除指定键的元素 | `m.erase(3);` <br>// 删除键为3的元素 | O(log n) |
| `find(const Key& key)` | 查找键对应的元素 | `auto it = m.find(3);` <br>// 查找键为3的元素 | O(log n) |
| `count(const Key& key)` | 计算键出现次数 | `size_t cnt = m.count(3);` <br>// 计算键为3的出现次数 | O(log n) |
| `size()` | 获取元素个数 | `size_t len = m.size();` <br>// 获取元素数量 | O(1) |
| `empty()` | 检查是否为空 | `if(m.empty()) {...}` <br>// 判断容器是否为空 | O(1) |
| `clear()` | 清空所有元素 | `m.clear();` <br>// 移除所有元素 | O(n) |
| `operator[](const Key& key)` | 访问或插入键对应的值 | `m[5] = "five";` <br>// 访问或插入键为5的值 | O(log n) |
| `emplace(Args&&... args)` | 原位插入键值对 | `m.emplace(4, "four");` <br>// 直接构造键值对(4, "four") | O(log n) |
| `lower_bound(const Key& key)` | 返回第一个不小于key的迭代器 | `auto it = m.lower_bound(3);` <br>// 查找第一个不小于3的元素 | O(log n) |
| `upper_bound(const Key& key)` | 返回第一个大于key的迭代器 | `auto it = m.upper_bound(3);` <br>// 查找第一个大于3的元素 | O(log n) |
| `equal_range(const Key& key)` | 返回等于key的范围 | `auto range = m.equal_range(3);` <br>// 查找键为3的范围 | O(log n) |
| `swap(map& other)` | 与另一容器交换内容 | `m1.swap(m2);` <br>// 交换两个map的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::map<int, std::string> m1;                      // 默认构造，空映射
std::map<int, std::string> m2 = {{1, "one"}, {2, "two"}}; // 使用初始化列表
std::map<int, std::string> m3(m2.begin(), m2.end()); // 使用迭代器范围构造
```

### 添加删除元素示例

```cpp
// 添加元素
m1.insert({3, "three"});     // 插入键值对(3, "three")
m1.emplace(4, "four");       // 直接构造键值对(4, "four")
m1[5] = "five";              // 访问或插入键为5的值

// 删除元素
m1.erase(3);                 // 删除键为3的元素
m1.erase(m1.begin());        // 删除第一个元素
```

### 查找元素示例

```cpp
// 查找元素
auto it = m1.find(4);        // 查找键为4的元素
if (it != m1.end()) {
    std::cout << "找到键4对应的值: " << it->second << std::endl;
}

// 计算键出现次数
size_t cnt = m1.count(4);    // 计算键为4的出现次数

// 范围查询
auto lower = m1.lower_bound(3); // 查找第一个不小于3的元素
auto upper = m1.upper_bound(3); // 查找第一个大于3的元素
auto range = m1.equal_range(3); // 查找键为3的范围
```

### 访问元素示例

```cpp
// 访问元素
for (auto it = m1.begin(); it != m1.end(); ++it) {
    std::cout << it->first << ": " << it->second << " ";
}
// 使用范围for循环
for (const auto& elem : m1) {
    std::cout << elem.first << ": " << elem.second << " ";
}
```

### 其他常用操作

```cpp
// 清空映射
m1.clear();                  // 移除所有元素

// 交换映射
m1.swap(m2);                 // 交换m1和m2的内容
```

### map与unordered_map的区别

- **内存分配**：map 使用红黑树，unordered_map 使用哈希表
- **访问方式**：map 自动排序，unordered_map 无序
- **查找效率**：map 的查找是 O(log n)，unordered_map 是 O(1)
- **迭代器失效**：map 的迭代器在插入删除时不会失效，unordered_map 可能失效

```cpp
// 何时选择map而非unordered_map？
// 1. 需要有序存储键值对
// 2. 需要范围查询功能
// 3. 需要稳定的迭代器
```

## multimap-有序多重映射

允许相同键对应多个值，自动按键的升序排序。
使用场景：需要建立一个键映射多个值时。

```cpp
std::multimap<int, std::string> mm;
mm.insert({1, "one"});
mm.insert({1, "uno"}); // 同一键的重复插入
```

# 无序关联式容器

## unordered_set-哈希集合

> **核心特点**：基于哈希表、无序存储、快速查找

基于哈希表实现，所有查找、插入操作在平均情况下为 O(1)。  

### 详细说明  

- **内存管理**：元素无序存储，内存占用相对较小
- **迭代器稳定性**：内部采用开放地址或链地址法解决冲突，不同实现对内存和性能的要求不同
- **异常安全**：当负载因子过高时，rehash 操作会导致所有元素重新分布，迭代器也可能失效
- **性能特点**：插入删除查找平均O(1)

> 💡 **优点**：查找速度快，无须保持顺序。

### 使用场景

- **只需要判断元素是否存在**：unordered_set 提供高效的查找操作
- **不需要元素保持有序**：unordered_set 无序存储
- **追求最快的元素查找速度**：unordered_set 的查找操作是 O(1) 复杂度

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `insert(const T& value)` | 插入元素 | `us.insert(10);` <br>// 插入值10 | 平均O(1) |
| `erase(const T& value)` | 删除指定元素 | `us.erase(10);` <br>// 删除值10 | 平均O(1) |
| `find(const T& value)` | 查找元素 | `auto it = us.find(10);` <br>// 查找值10 | 平均O(1) |
| `count(const T& value)` | 计算元素出现次数 | `size_t cnt = us.count(10);` <br>// 计算值10的出现次数 | 平均O(1) |
| `size()` | 获取元素个数 | `size_t len = us.size();` <br>// 获取元素数量 | O(1) |
| `empty()` | 检查是否为空 | `if(us.empty()) {...}` <br>// 判断容器是否为空 | O(1) |
| `clear()` | 清空所有元素 | `us.clear();` <br>// 移除所有元素 | O(n) |
| `emplace(Args&&... args)` | 原位插入元素 | `us.emplace(15);` <br>// 直接构造值为15的元素 | 平均O(1) |
| `bucket_count()` | 返回当前哈希桶的数量 | `size_t n = us.bucket_count();` <br>// 获取哈希桶数量 | O(1) |
| `load_factor()` | 返回当前负载因子 | `float lf = us.load_factor();` <br>// 获取负载因子 | O(1) |
| `rehash(size_t n)` | 重新配置哈希桶数量 | `us.rehash(20);` <br>// 重新配置哈希桶数量 | O(n) |
| `swap(unordered_set& other)` | 与另一容器交换内容 | `us1.swap(us2);` <br>// 交换两个unordered_set的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::unordered_set<int> us1;                      // 默认构造，空集合
std::unordered_set<int> us2 = {1, 2, 3, 4, 5};    // 使用初始化列表
std::unordered_set<int> us3(us2.begin(), us2.end()); // 使用迭代器范围构造
```

### 添加删除元素示例

```cpp
// 添加元素
us1.insert(10);             // 插入值10
us1.emplace(15);            // 直接构造值为15的元素

// 删除元素
us1.erase(10);              // 删除值10
us1.erase(us1.begin());     // 删除第一个元素
```

### 查找元素示例

```cpp
// 查找元素
auto it = us1.find(15);     // 查找值15
if (it != us1.end()) {
    std::cout << "找到元素15" << std::endl;
}

// 计算元素出现次数
size_t cnt = us1.count(15); // 计算值15的出现次数
```

### 访问元素示例

```cpp
// 访问元素
for (auto it = us1.begin(); it != us1.end(); ++it) {
    std::cout << *it << " ";
}
// 使用范围for循环
for (const auto& elem : us1) {
    std::cout << elem << " ";
}
```

### 其他常用操作

```cpp
// 清空集合
us1.clear();                // 移除所有元素

// 交换集合
us1.swap(us2);              // 交换us1和us2的内容

// 获取哈希桶数量
size_t n = us1.bucket_count(); // 获取哈希桶数量

// 获取负载因子
float lf = us1.load_factor();  // 获取负载因子

// 重新配置哈希桶数量
us1.rehash(20);             // 重新配置哈希桶数量
```

### unordered_set与set的区别

- **内存分配**：unordered_set 使用哈希表，set 使用红黑树
- **访问方式**：unordered_set 无序，set 自动排序
- **查找效率**：unordered_set 的查找是 O(1)，set 是 O(log n)
- **迭代器失效**：unordered_set 的迭代器在插入删除时可能失效，set 不会失效

```cpp
// 何时选择unordered_set而非set？
// 1. 只需要判断元素是否存在
// 2. 不需要元素保持有序
// 3. 追求最快的查找速度
```

## unordered_map-哈希表

> **核心特点**：基于哈希表、键值对、快速查找

详细说明与 unordered_set 类似，另外键值对的存储允许快速的键值映射。  

### 详细说明  

- **内存管理**：注意在使用 operator[] 时，如果键不存在会创建新项，可能带来意外的内存分配
- **迭代器稳定性**：内部采用开放地址或链地址法解决冲突，不同实现对内存和性能的要求不同
- **异常安全**：当负载因子过高时，rehash 操作会导致所有元素重新分布，迭代器也可能失效
- **性能特点**：插入删除查找平均O(1)

> 💡 **常用于快速键值查找和数据插入**。

### 使用场景

- **需要快速的键值查找**：unordered_map 提供高效的查找操作
- **不需要键值对保持有序**：unordered_map 无序存储
- **存储大量数据时需要高效查找**：unordered_map 的查找操作是 O(1) 复杂度

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `insert(const std::pair<const Key, T>& value)` | 插入键值对 | `um.insert({3, "three"});` <br>// 插入键值对(3, "three") | 平均O(1) |
| `erase(const Key& key)` | 删除指定键的元素 | `um.erase(3);` <br>// 删除键为3的元素 | 平均O(1) |
| `find(const Key& key)` | 查找键对应的元素 | `auto it = um.find(3);` <br>// 查找键为3的元素 | 平均O(1) |
| `count(const Key& key)` | 计算键出现次数 | `size_t cnt = um.count(3);` <br// 计算键为3的出现次数 | 平均O(1) |
| `size()` | 获取元素个数 | `size_t len = um.size();` <br// 获取元素数量 | O(1) |
| `empty()` | 检查是否为空 | `if(um.empty()) {...}` <br// 判断容器是否为空 | O(1) |
| `clear()` | 清空所有元素 | `um.clear();` <br// 移除所有元素 | O(n) |
| `operator[](const Key& key)` | 访问或插入键对应的值 | `um[5] = "five";` <br// 访问或插入键为5的值 | 平均O(1) |
| `emplace(Args&&... args)` | 原位插入键值对 | `um.emplace(4, "four");` <br// 直接构造键值对(4, "four") | 平均O(1) |
| `bucket_count()` | 返回当前哈希桶的数量 | `size_t n = um.bucket_count();` <br// 获取哈希桶数量 | O(1) |
| `load_factor()` | 返回当前负载因子 | `float lf = um.load_factor();` <br// 获取负载因子 | O(1) |
| `rehash(size_t n)` | 重新配置哈希桶数量 | `um.rehash(20);` <br// 重新配置哈希桶数量 | O(n) |
| `swap(unordered_map& other)` | 与另一容器交换内容 | `um1.swap(um2);` <br// 交换两个unordered_map的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::unordered_map<int, std::string> um1;                      // 默认构造，空映射
std::unordered_map<int, std::string> um2 = {{1, "one"}, {2, "two"}}; // 使用初始化列表
std::unordered_map<int, std::string> um3(um2.begin(), um2.end()); // 使用迭代器范围构造
```

### 添加删除元素示例

```cpp
// 添加元素
um1.insert({3, "three"});     // 插入键值对(3, "three")
um1.emplace(4, "four");       // 直接构造键值对(4, "four")
um1[5] = "five";              // 访问或插入键为5的值

// 删除元素
um1.erase(3);                 // 删除键为3的元素
um1.erase(um1.begin());       // 删除第一个元素
```

### 查找元素示例

```cpp
// 查找元素
auto it = um1.find(4);        // 查找键为4的元素
if (it != um1.end()) {
    std::cout << "找到键4对应的值: " << it->second << std::endl;
}

// 计算键出现次数
size_t cnt = um1.count(4);    // 计算键为4的出现次数
```

### 访问元素示例

```cpp
// 访问元素
for (auto it = um1.begin(); it != um1.end(); ++it) {
    std::cout << it->first << ": " << it->second << " ";
}
// 使用范围for循环
for (const auto& elem : um1) {
    std::cout << elem.first << ": " << elem.second << " ";
}
```

### 其他常用操作

```cpp
// 清空映射
um1.clear();                  // 移除所有元素

// 交换映射
um1.swap(um2);                // 交换um1和um2的内容

// 获取哈希桶数量
size_t n = um1.bucket_count(); // 获取哈希桶数量

// 获取负载因子
float lf = um1.load_factor();  // 获取负载因子

// 重新配置哈希桶数量
um1.rehash(20);               // 重新配置哈希桶数量
```

### unordered_map与map的区别

- **内存分配**：unordered_map 使用哈希表，map 使用红黑树
- **访问方式**：unordered_map 无序，map 自动排序
- **查找效率**：unordered_map 的查找是 O(1)，map 是 O(log n)
- **迭代器失效**：unordered_map 的迭代器在插入删除时可能失效，map 不会失效

```cpp
// 何时选择unordered_map而非map？
// 1. 需要快速的键值查找
// 2. 不需要键值对保持有序
// 3. 存储大量数据时需要高效查找
```

# 容器适配器

## queue-队列

> **核心特点**：FIFO结构、基于deque实现、只允许访问队首和队尾

队列是一种 FIFO 数据结构，内部一般使用 deque 实现。  

### 详细说明  

- **内存管理**：由于只允许访问队首和队尾，不支持迭代器，因此无法直接对队列内部数据做复杂操作
- **迭代器稳定性**：在多线程环境中，队列必须进行额外的同步来保证数据的一致性
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：插入删除O(1)，访问队首队尾O(1)

> 💡 **先进先出(FIFO)结构，常用于任务调度及广度优先搜索**。

### 使用场景

- **需要按照先进先出的顺序处理元素**：queue 提供 FIFO 结构
- **实现广度优先搜索**：queue 常用于 BFS 算法
- **需要按照时间顺序处理任务**：queue 适合任务调度

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push(const T& value)` | 添加元素到队列末尾 | `q.push(10);` <br// 在末尾添加值10 | O(1) |
| `pop()` | 移除队列前端元素 | `q.pop();` <br// 删除第一个元素 | O(1) |
| `front()` | 访问队列前端元素 | `int front = q.front();` <br// 获取第一个元素 | O(1) |
| `back()` | 访问队列末尾元素 | `int back = q.back();` <br// 获取最后一个元素 | O(1) |
| `empty()` | 检查是否为空 | `if(q.empty()) {...}` <br// 判断容器是否为空 | O(1) |
| `size()` | 获取元素个数 | `size_t len = q.size();` <br// 获取元素数量 | O(1) |
| `emplace(Args&&... args)` | 原位添加元素到队列末尾 | `q.emplace(15);` <br// 直接构造值为15的元素 | O(1) |
| `swap(queue& other)` | 与另一容器交换内容 | `q1.swap(q2);` <br// 交换两个queue的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::queue<int> q1;                      // 默认构造，空队列
std::queue<int> q2;                      // 使用默认构造
q2.push(1);                              // 添加元素
q2.push(2);                              // 添加元素
```

### 添加删除元素示例

```cpp
// 添加元素
q1.push(10);             // 在末尾添加值10
q1.emplace(15);          // 直接构造值为15的元素

// 删除元素
q1.pop();                // 删除第一个元素
```

### 访问元素示例

```cpp
// 访问元素
int front = q1.front();  // 获取第一个元素
int back = q1.back();    // 获取最后一个元素
```

### 容量管理示例

```cpp
// 容量相关操作
size_t sz = q1.size();   // 获取元素数量
bool is_empty = q1.empty(); // 检查是否为空
```

### 其他常用操作

```cpp
// 交换队列
q1.swap(q2);             // 交换q1和q2的内容
```

### queue与deque的区别

- **内存分配**：queue 使用 deque 作为底层容器
- **访问方式**：queue 只允许访问队首和队尾，deque 支持随机访问
- **插入删除**：queue 只允许在队首和队尾插入删除，deque 支持在任意位置插入删除
- **迭代器失效**：queue 不支持迭代器，deque 支持迭代器

```cpp
// 何时选择queue而非deque？
// 1. 需要先进先出的顺序处理元素
// 2. 不需要随机访问元素
// 3. 需要简单的接口
```

## priority_queue-优先队列

> **核心特点**：基于堆、默认最大堆、支持自定义比较器

优先队列基于堆实现，默认是最大堆。  

### 详细说明  

- **内存管理**：内部维护堆结构，使得每次获取 top 操作都是 O(1)，而插入和删除操作都是 O(log n)
- **迭代器稳定性**：可通过自定义比较器改变排序规则，例如实现最小堆
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：插入删除O(log n)，访问top O(1)

> 💡 **默认实现最大堆，可根据需定制排序规则**。

### 使用场景

- **需要维护一个动态的有序序列**：priority_queue 提供堆结构
- **实现堆排序**：priority_queue 常用于堆排序算法
- **需要频繁获取最大/最小元素**：priority_queue 提供高效的 top 操作

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push(const T& value)` | 添加元素 | `pq.push(10);` <br// 添加值10 | O(log n) |
| `pop()` | 移除优先级最高的元素 | `pq.pop();` <br// 删除优先级最高的元素 | O(log n) |
| `top()` | 访问优先级最高的元素 | `int top = pq.top();` <br// 获取优先级最高的元素 | O(1) |
| `empty()` | 检查是否为空 | `if(pq.empty()) {...}` <br// 判断容器是否为空 | O(1) |
| `size()` | 获取元素个数 | `size_t len = pq.size();` <br// 获取元素数量 | O(1) |
| `emplace(Args&&... args)` | 原位添加元素 | `pq.emplace(15);` <br// 直接构造值为15的元素 | O(log n) |
| `swap(priority_queue& other)` | 与另一容器交换内容 | `pq1.swap(pq2);` <br// 交换两个priority_queue的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::priority_queue<int> pq1;                      // 默认构造，空优先队列
std::priority_queue<int> pq2;                      // 使用默认构造
pq2.push(1);                                       // 添加元素
pq2.push(2);                                       // 添加元素
```

### 添加删除元素示例

```cpp
// 添加元素
pq1.push(10);             // 添加值10
pq1.emplace(15);          // 直接构造值为15的元素

// 删除元素
pq1.pop();                // 删除优先级最高的元素
```

### 访问元素示例

```cpp
// 访问元素
int top = pq1.top();      // 获取优先级最高的元素
```

### 容量管理示例

```cpp
// 容量相关操作
size_t sz = pq1.size();   // 获取元素数量
bool is_empty = pq1.empty(); // 检查是否为空
```

### 其他常用操作

```cpp
// 交换优先队列
pq1.swap(pq2);            // 交换pq1和pq2的内容
```

### priority_queue与queue的区别

- **内存分配**：priority_queue 使用堆结构，queue 使用 deque 作为底层容器
- **访问方式**：priority_queue 只允许访问优先级最高的元素，queue 只允许访问队首和队尾
- **插入删除**：priority_queue 的插入删除是 O(log n)，queue 的插入删除是 O(1)
- **迭代器失效**：priority_queue 不支持迭代器，queue 不支持迭代器

```cpp
// 何时选择priority_queue而非queue？
// 1. 需要维护一个动态的有序序列
// 2. 需要频繁获取最大/最小元素
// 3. 需要实现堆排序
```

## stack-栈

> **核心特点**：LIFO结构、基于deque实现、只允许访问栈顶

栈是一种 LIFO 数据结构，通常使用 deque 实现。  

### 详细说明  

- **内存管理**：栈中的所有操作均为常数时间，但由于不支持迭代器，其调试和错误检查较为困难
- **迭代器稳定性**：主要适用于递归调用、表达式求值等场景
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：插入删除O(1)，访问栈顶O(1)

> 💡 **后进先出(LIFO)结构，适合实现深度优先搜索或函数调用栈**。

### 使用场景

- **需要按照后进先出的顺序处理元素**：stack 提供 LIFO 结构
- **实现深度优先搜索**：stack 常用于 DFS 算法
- **处理括号匹配等问题**：stack 适合括号匹配等问题
- **实现函数调用栈**：stack 适合函数调用栈

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `push(const T& value)` | 添加元素到栈顶 | `s.push(10);` <br// 在栈顶添加值10 | O(1) |
| `pop()` | 移除栈顶元素 | `s.pop();` <br// 删除栈顶元素 | O(1) |
| `top()` | 访问栈顶元素 | `int top = s.top();` <br// 获取栈顶元素 | O(1) |
| `empty()` | 检查是否为空 | `if(s.empty()) {...}` <br// 判断容器是否为空 | O(1) |
| `size()` | 获取元素个数 | `size_t len = s.size();` <br// 获取元素数量 | O(1) |
| `emplace(Args&&... args)` | 原位添加元素到栈顶 | `s.emplace(15);` <br// 直接构造值为15的元素 | O(1) |
| `swap(stack& other)` | 与另一容器交换内容 | `s1.swap(s2);` <br// 交换两个stack的内容 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::stack<int> s1;                      // 默认构造，空栈
std::stack<int> s2;                      // 使用默认构造
s2.push(1);                              // 添加元素
s2.push(2);                              // 添加元素
```

### 添加删除元素示例

```cpp
// 添加元素
s1.push(10);             // 在栈顶添加值10
s1.emplace(15);          // 直接构造值为15的元素

// 删除元素
s1.pop();                // 删除栈顶元素
```

### 访问元素示例

```cpp
// 访问元素
int top = s1.top();      // 获取栈顶元素
```

### 容量管理示例

```cpp
// 容量相关操作
size_t sz = s1.size();   // 获取元素数量
bool is_empty = s1.empty(); // 检查是否为空
```

### 其他常用操作

```cpp
// 交换栈
s1.swap(s2);             // 交换s1和s2的内容
```

### stack与deque的区别

- **内存分配**：stack 使用 deque 作为底层容器
- **访问方式**：stack 只允许访问栈顶元素，deque 支持随机访问
- **插入删除**：stack 只允许在栈顶插入删除，deque 支持在任意位置插入删除
- **迭代器失效**：stack 不支持迭代器，deque 支持迭代器

```cpp
// 何时选择stack而非deque？
// 1. 需要后进先出的顺序处理元素
// 2. 不需要随机访问元素
// 3. 需要简单的接口
```

# 位集合

## bitset-固定大小位容器

> **核心特点**：固定大小、位操作高效、适合布尔标志存储

用于存储固定数量的二进制位，支持高效位运算。  

### 详细说明  

- **内存管理**：因为固定大小，bitset 的操作在编译期间就确定，性能和内存使用非常优化
- **迭代器稳定性**：在处理大批量布尔值数据时，比 vector<bool> 更加高效且易于理解
- **异常安全**：所有操作均具有强异常安全性
- **性能特点**：位操作O(1)

> 💡 **用于存储固定数量的二进制位，并支持高效的位操作**。

### 使用场景

- **需要按位处理或存储大量布尔标志**：bitset 提供高效的位操作

### 常用成员函数及使用说明

| 函数 | 描述 | 示例 | 复杂度 |
|------|------|------|--------|
| `set()` | 将所有位或指定位置的位设置为1 | `bs.set();` <br// 将所有位设置为1 | O(1) |
| `reset()` | 将所有位或指定位置的位重置为0 | `bs.reset();` <br// 将所有位重置为0 | O(1) |
| `flip()` | 将所有位或指定位置的位取反 | `bs.flip();` <br// 将所有位取反 | O(1) |
| `test(size_t pos)` | 检查指定位置的位是否为1 | `bool bit3 = bs.test(3);` <br// 检查第3位是否为1 | O(1) |
| `all()` | 检查所有位是否都为1 | `bool all = bs.all();` <br// 检查所有位是否都为1 | O(1) |
| `any()` | 检查是否存在为1的位 | `bool any = bs.any();` <br// 检查是否存在为1的位 | O(1) |
| `none()` | 检查是否所有位都为0 | `bool none = bs.none();` <br// 检查是否所有位都为0 | O(1) |
| `count()` | 返回为1的位的个数 | `size_t cnt = bs.count();` <br// 返回为1的位的个数 | O(1) |
| `size()` | 返回位的总数 | `size_t sz = bs.size();` <br// 返回位的总数 | O(1) |
| `to_string()` | 返回位的字符串表示 | `std::string str = bs.to_string();` <br// 返回位的字符串表示 | O(n) |
| `to_ulong()` | 返回位的无符号长整型表示 | `unsigned long ul = bs.to_ulong();` <br// 返回位的无符号长整型表示 | O(1) |
| `to_ullong()` | 返回位的无符号长长整型表示 | `unsigned long long ull = bs.to_ullong();` <br// 返回位的无符号长长整型表示 | O(1) |

### 构造和初始化示例

```cpp
// 多种构造方式
std::bitset<8> bs1;                      // 默认构造，空位集合
std::bitset<8> bs2(0b10101010);          // 使用二进制字面量
std::bitset<8> bs3("1100");              // 使用字符串
```

### 设置和重置位示例

```cpp
// 设置和重置位
bs1.set();                // 将所有位设置为1
bs1.reset();              // 将所有位重置为0
bs1.set(3);               // 将第3位置为1
bs1.reset(3);             // 将第3位重置为0
bs1.flip();               // 将所有位取反
bs1.flip(2);              // 将第2位取反
```

### 检查位示例

```cpp
// 检查位
bool bit3 = bs1.test(3);  // 检查第3位是否为1
bool all = bs1.all();     // 检查所有位是否都为1
bool any = bs1.any();     // 检查是否存在为1的位
bool none = bs1.none();   // 检查是否所有位都为0
size_t cnt = bs1.count(); // 返回为1的位的个数
size_t sz = bs1.size();   // 返回位的总数
```

### 转换为字符串和整数示例

```cpp
// 转换为字符串和整数
std::string str = bs1.to_string(); // 返回位的字符串表示
unsigned long ul = bs1.to_ulong(); // 返回位的无符号长整型表示
unsigned long long ull = bs1.to_ullong(); // 返回位的无符号长长整型表示
```

### 示例：bitset默认索引从右到左（低位到高位）

```cpp
std::bitset<4> bs(0b1010); // 表示：第3位为1，第2位为0，第1位为1，第0位为0
// 例如：测试最高位
bool highest = bs.test(3); // 返回true
```

# 性能对比

| 容器类型      | 随机访问 | 插入/删除(开始) | 插入/删除(中间)          | 插入/删除(结尾) | 查找     |
| ------------- | :------: | :-----------: | :----------------------: | :-----------: | :------: |
| vector        | O(1)     | O(n)          | O(n)*                   | O(1)          | O(n)     |
| deque         | O(1)     | O(1)          | O(n)*                   | O(1)          | O(n)     |
| list          | O(n)     | O(1)          | O(n) (遍历定位 + O(1))   | O(1)          | O(n)     |
| set           | O(log n) | O(log n)      | O(log n)               | O(log n)      | O(log n) |
| map           | O(log n) | O(log n)      | O(log n)               | O(log n)      | O(log n) |
| unordered_set | N/A      | O(1)          | O(1)                   | O(1)          | O(1)     |
| unordered_map | N/A      | O(1)          | O(1)                   | O(1)          | O(1)     |

*注：中间插入/删除需要先遍历定位，list操作定位为O(n)

## 空间复杂度

| 容器类型      | 额外空间 |
| ------------- | -------- |
| vector        | O(n)     |
| deque         | O(n)     |
| list          | O(n)     |
| set           | O(n)     |
| map           | O(n)     |
| unordered_set | O(n)     |
| unordered_map | O(n)     |

## 最佳实践

1. 默认优先使用 vector
2. 需要在两端操作时使用 deque
3. 频繁插入删除使用 list
4. 需要有序唯一元素使用 set
5. 需要键值对使用 map
6. 追求查找效率使用 unordered_set/map
7. 需要FIFO使用 queue
8. 需要维护有序序列使用 priority_queue

> **补充说明**  
>
> - 使用 emplace 系列函数可以避免构造临时对象，从而提高性能。  
> - 对于可能抛出异常的操作（如 vector::at()、map::at()），建议使用 try-catch 捕获异常。

## 容器适用场景对比

| 容器类型       | 内存占用  | 查找效率   | 插入/删除效率     | 是否有序 | 允许重复元素 |
| -------------- | --------- | ---------- | ----------------- | -------- | ------------ |
| vector         | 较低      | O(n)       | 尾部 O(1)，中间 O(n) | 是       | 否           |
| deque          | 较低      | O(n)       | 两端 O(1)，中间 O(n) | 是       | 否           |
| list           | 较高      | O(n)       | O(1)              | 否       | 是           |
| set            | 中等      | O(log n)   | O(log n)          | 是       | 否           |
| multiset       | 中等      | O(log n)   | O(log n)          | 是       | 是           |
| map            | 中等      | O(log n)   | O(log n)          | 是       | 键唯一       |
| multimap       | 中等      | O(log n)   | O(log n)          | 是       | 键可重复     |
| unordered_set  | 较低      | 平均 O(1)  | 平均 O(1)         | 否       | 否           |
| unordered_map  | 较低      | 平均 O(1)  | 平均 O(1)         | 否       | 键唯一       |

# 迭代器失效说明

在 **vector** 和 **deque** 中，插入或删除元素可能导致迭代器失效：  
详细说明：  

- 对 vector：插入或删除元素可能导致重新分配内存，从而使所有迭代器失效。建议使用返回值或重新获取迭代器。  
- 对 deque：插入/删除头尾元素通常安全，但中间操作可能使部分迭代器失效。

示例：

```cpp
// 避免迭代器失效的示例
auto it = vec.begin();
it = vec.insert(it, 42); // 使用返回的迭代器继续操作
```

# std::array 的说明

虽然 std::array 大小固定，但适用于需要在栈上分配小型固定数组的场景，性能较高且安全：

```cpp
#include <array>
std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

# 查找操作详解

详细查找操作部分增加对异常安全性、底层实现（例如哈希桶分布、红黑树平衡规则）的解释，帮助你更好地选择合适的查找算法和数据结构进行优化。

### 顺序容器查找

#### vector/deque 的查找

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// 1. 使用 find 算法（需要包含 <algorithm>）
auto it = std::find(vec.begin(), vec.end(), 3);
if (it != vec.end()) {
    std::cout << "找到元素: " << *it << "\n";
} else {
    std::cout << "未找到元素\n";
}

// 2. 使用 find_if 查找满足条件的元素
auto it2 = std::find_if(vec.begin(), vec.end(), [](int x) { 
    return x > 3; 
});
if (it2 != vec.end()) {
    std::cout << "找到第一个大于3的元素: " << *it2 << "\n";
}

// 3. 二分查找（要求容器已排序）
if (std::binary_search(vec.begin(), vec.end(), 3)) {
    std::cout << "元素3存在\n";
}

// 4. 获取位置
auto idx = std::distance(vec.begin(), it);
std::cout << "元素位置: " << idx << "\n";
```

#### list 的查找

```cpp
std::list<int> lst = {1, 2, 3, 4, 5};

// 由于list不支持随机访问，通常使用迭代器
auto it = std::find(lst.begin(), lst.end(), 3);
if (it != lst.end()) {
    std::cout << "找到元素: " << *it << "\n";
    // 前移/后移迭代器
    ++it; // 下一个元素
    --it; // 上一个元素
}
```

### 关联容器查找

#### set 的查找

```cpp
std::set<int> s = {1, 2, 3, 4, 5};

// 1. 使用 find 成员函数
auto it = s.find(3);
if (it != s.end()) {
    std::cout << "找到元素: " << *it << "\n";
}

// 2. 使用 count 检查元素是否存在（set中要么是0要么是1）
if (s.count(3) > 0) {
    std::cout << "元素3存在\n";
}

// 3. 使用 lower_bound 和 upper_bound
auto lower = s.lower_bound(3); // 大于等于3的第一个元素
auto upper = s.upper_bound(3); // 大于3的第一个元素

if (lower != s.end()) {
    std::cout << "第一个大于等于3的元素: " << *lower << "\n";
}

// 4. 使用 equal_range 获取范围
auto range = s.equal_range(3);
for (auto it = range.first; it != range.second; ++it) {
    std::cout << *it << " ";
}
```

#### map 的查找

```cpp
std::map<std::string, int> m = {
    {"one", 1}, {"two", 2}, {"three", 3}
};

// 1. 使用 find 成员函数
auto it = m.find("two");
if (it != m.end()) {
    std::cout << "找到键two对应的值: " << it->second << "\n";
}

// 2. 使用 count 检查键是否存在
if (m.count("two") > 0) {
    std::cout << "键two存在\n";
}

// 3. 使用 at 访问（不存在则抛出异常）
try {
    int value = m.at("two");
    std::cout << "键two的值: " << value << "\n";
} catch (const std::out_of_range& e) {
    std::cout << "键不存在\n";
}

// 4. 使用 operator[] （不存在则插入默认值）
int value = m["two"]; // 如果不存在，会插入并初始化为0

// 5. 使用 lower_bound 和 upper_bound（基于键排序）
auto lower = m.lower_bound("two");
if (lower != m.end()) {
    std::cout << "第一个大于等于two的键值对: " 
              << lower->first << ":" << lower->second << "\n";
}
```

### 无序容器查找

#### unordered_set 的查找

```cpp
std::unordered_set<int> us = {1, 2, 3, 4, 5};

// 1. 使用 find 成员函数
auto it = us.find(3);
if (it != us.end()) {
    std::cout << "找到元素: " << *it << "\n";
}

// 2. 使用 count 检查元素是否存在
if (us.count(3) > 0) {
    std::cout << "元素3存在\n";
}

// 注意：无序容器不支持 lower_bound/upper_bound
```

#### unordered_map 的查找

```cpp
std::unordered_map<std::string, int> um = {
    {"one", 1}, {"two", 2}, {"three", 3}
};

// 1. 使用 find 成员函数
auto it = um.find("two");
if (it != um.end()) {
    std::cout << "找到键two对应的值: " << it->second << "\n";
}

// 2. 使用 count 检查键是否存在
if (um.count("two") > 0) {
    std::cout << "键two存在\n";
}

// 3. 安全的值访问模式
auto it2 = um.find("two");
if (it2 != um.end()) {
    std::cout << "值: " << it2->second << "\n";
} else {
    std::cout << "键不存在\n";
}

// 4. 使用 at（不存在则抛出异常）
try {
    int value = um.at("two");
} catch (const std::out_of_range& e) {
    std::cout << "键不存在\n";
}
```

### 容器适配器的查找

注意：stack、queue 和 priority_queue 不支持直接查找，只能访问特定位置的元素（如栈顶、队首等）

```cpp
std::stack<int> s;
s.push(1);
s.push(2);
s.push(3);

// 只能访问栈顶元素
if (!s.empty()) {
    std::cout << "栈顶元素: " << s.top() << "\n";
}

std::queue<int> q;
q.push(1);
q.push(2);
q.push(3);

// 只能访问队首和队尾元素
if (!q.empty()) {
    std::cout << "队首元素: " << q.front() << "\n";
    std::cout << "队尾元素: " << q.back() << "\n";
}

std::priority_queue<int> pq;
pq.push(1);
pq.push(3);
pq.push(2);

// 只能访问最高优先级的元素（默认最大值）
if (!pq.empty()) {
    std::cout << "最高优先级元素: " << pq.top() << "\n";
}
```

## 查找最佳实践

1. 对于有序序列，优先使用二分查找 (`binary_search`, `lower_bound`, `upper_bound`)
2. 对于关联容器，优先使用成员函数 `find` 而不是算法 `std::find`
3. 需要频繁查找时，考虑使用哈希容器 (`unordered_set/map`)
4. 需要查找范围时，使用 `equal_range`
5. 对于 map/unordered_map，优先使用 `find` 而不是 `operator[]` 检查键是否存在

# 扩展说明及用法

### 1. STL各容器的选择建议

- 对于需要动态扩展且随机访问要求高的场景，尽可能使用 vector。
- 当两端插入删除频繁时，优先考虑 deque；而中间频繁插入删除建议使用 list。
- 对于需要快速查询，且数据无须顺序时，可选择 unordered_set 或 unordered_map。

### 2. 详细使用示例

#### 示例：使用 vector 与算法配合

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> vec = {5, 3, 8, 1};
    // 排序并查找第一个大于4的元素
    sort(vec.begin(), vec.end());
    auto it = find_if(vec.begin(), vec.end(), [](int n){ return n > 4; });
    if(it != vec.end()){
        cout << "第一个大于4的元素是: " << *it << endl;
    }
    return 0;
}
```

### 3. 扩展用法说明

- 为提高代码复用性，建议将常用操作封装为函数或类模板。
- 利用 Lambda 表达式进行复杂条件查找，是 C++11 后的常用技巧。
- STL 算法与容器的灵活组合，能够大幅简化代码且提高性能，应多加实践。

# 扩展阅读与总结

- 推荐书籍：  
  - 《Effective STL》  
  - 《STL源码剖析》  
  - 《C++标准库》

- 在线资源：  
  - [cppreference.com](https://en.cppreference.com)  
  - [C++ 学习笔记](https://www.cplusplus.com)

- 学习建议：  
  - 在实际项目中尝试不同容器以平衡性能与空间；  
  - 注意容器的迭代器失效规则与内存管理细节；  
  - 关注 STL 算法使用案例，提升编码规范和效率。

### 迭代器类别

- **vector / deque**：随机访问迭代器（支持 +、-、[] 运算符）
- **list / set / map**：双向迭代器（仅支持 ++ 和 --）
- **forward_list**：前向迭代器（仅支持 ++）

C++ STL 中的迭代器按照功能强大程度可以分为以下几类：

1. 随机访问迭代器
   - 适用容器：`vector`、`deque`
   - 支持的操作：

   ```cpp
   it + n;      // 向前移动n个位置
   it - n;      // 向后移动n个位置
   it[n];       // 访问第n个元素
   it1 < it2;   // 迭代器比较
   ```

2. 双向迭代器
   - 适用容器：`list`、`set`、`map`
   - 支持的操作：

   ```cpp
   ++it;    // 向前移动一个位置
   --it;    // 向后移动一个位置
   *it;     // 解引用访问元素
   ```

3. 前向迭代器
   - 适用容器：`forward_list`
   - 支持的操作：

   ```cpp
   ++it;    // 只能向前移动
   *it;     // 解引用访问元素
   ```

#### 使用示例

```cpp
// 随机访问迭代器示例
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it = vec.begin();
it += 2;      // 可以直接跳转
std::cout << it[1] << std::endl;  // 可以用[]访问

// 双向迭代器示例
std::list<int> lst = {1, 2, 3, 4, 5};
auto it2 = lst.begin();
++it2;    // 只能一步一步移动
--it2;    // 可以向后移动

// 前向迭代器示例
std::forward_list<int> fl = {1, 2, 3, 4, 5};
auto it3 = fl.begin();
++it3;    // 只能向前移动
```