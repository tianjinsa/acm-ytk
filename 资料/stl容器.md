# C++ STL容器使用指南

> 本文档详细介绍了 C++ STL 容器的分类、使用方法、底层实现原理、性能对比及最佳实践。特别说明各容器在内存管理、迭代器失效和异常安全方面的细节，帮助读者更深入地理解和应用 STL 提供的各个容器。

## 目录

- [容器分类]
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

动态数组（`vector`）是最常用的容器。它的内存是连续分配的，因此支持快速随机访问；但当容量不足时，会按照一定的扩展策略（通常是倍增扩容）进行内存重新分配，这可能导致所有迭代器失效。  
详细说明：  

- 内存扩容通常遵循几何级增长，确保插入元素的均摊时间复杂度为 O(1)。  
- 迭代器和指针在重新分配时全部失效，需要注意使用返回的迭代器或重新获取索引。  

> 小贴士：适用于需要快速随机访问和尾部操作的场景。例如，存储一组数据，并需要频繁访问其中的元素。

### 使用场景

- 需要频繁随机访问元素：`vector` 提供了高效的随机访问能力，可以通过索引直接访问元素。
- 主要在尾部进行插入和删除操作：在尾部插入和删除元素的时间复杂度为 O(1)，效率很高。
- 需要动态改变容器大小：`vector` 可以根据需要动态调整大小，方便存储不确定数量的元素。
- `push_back(const T& value)`: 在末尾添加一个元素。

  ```cpp
  std::vector<int> vec;
  vec.push_back(10); // 在 vec 的末尾添加元素 10
  ```

- `pop_back()`: 删除末尾的元素。

  ```cpp
  vec.pop_back(); // 删除 vec 的末尾元素
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = vec.size(); // 获取 vec 中元素的个数
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (vec.empty()) { // 检查 vec 是否为空
      // 容器为空
  }
  ```

- `at(size_t pos)`: 访问指定位置的元素。

  ```cpp
  int value = vec.at(0); // 访问 vec 中索引为 0 的元素
  ```

- `clear()`: 清空所有元素。

  ```cpp
  vec.clear(); // 清空 vec 中的所有元素
  ```

- `insert(iterator pos, const T& value)`: 在指定位置插入元素。

  ```cpp
  vec.insert(vec.begin(), 5); // 在 vec 的起始位置插入元素 5
  ```

- `erase(iterator pos)`: 删除指定位置的元素。

  ```cpp
  vec.erase(vec.begin()); // 删除 vec 的起始位置的元素
  ```

- `emplace_back(Args&&... args)`: 在末尾原位构造一个元素。

  ```cpp
  vec.emplace_back(20); // 在 vec 的末尾原位构造元素 20，避免了临时对象的创建
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::vector<int> vec1; // 默认构造
std::vector<int> vec2(5, 10); // 5 个值为 10 的元素
std::vector<int> vec3 = {1, 2, 3, 4, 5}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
vec1.push_back(15);
vec1.emplace_back(20);
```

### 删除元素

```cpp
// 删除元素
vec1.pop_back();
vec1.erase(vec1.begin());
```

### 访问元素

```cpp
// 访问元素
int first = vec1.front();
int last = vec1.back();
int second = vec1.at(1);
```

### 容量操作

```cpp
// 容量操作
vec1.reserve(100); // 预留空间
size_t current_capacity = vec1.capacity();
```

### 排序和反转

```cpp
// 排序和反转
std::sort(vec1.begin(), vec1.end());
std::reverse(vec1.begin(), vec1.end());
```

### 拼接操作

```cpp
// 拼接操作
std::vector<int> vec4 = {6, 7, 8};
vec1.insert(vec1.end(), vec4.begin(), vec4.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    std::cout << *it << " ";
}
```

### 其他常用函数

```cpp
resize(size_t count): 调整容器大小。当 count 大于当前大小时，新元素按默认构造；若小于，则移除多余元素。
vec1.resize(10);

shrink_to_fit(): 请求收缩内存至当前大小，多用于减少内存占用，但具体结果依赖编译器实现。
vec1.shrink_to_fit();

data(): 返回指向容器内部连续存储区首元素的指针，便于与 C 风格数组互操作。
int* ptr = vec1.data();

begin(), end(), rbegin(), rend() 等：提供正向或反向迭代器，用于遍历所有元素。
```

### 反向迭代器变体

- `rbegin()`, `rend()`: 用于反向迭代
- `crbegin()`, `crend()`: const 反向迭代器

### emplace系列变体

- `emplace()`: 原位构造，C++17后支持
- `emplace_back()`: 在尾部原位构造
- `emplace_hint()`: 提供插入位置提示的原位构造

### 主要特点

- 动态大小，自动管理内存。
- 支持快速随机访问。
- 高效的尾部插入和删除操作。

## deque-双端队列

双端队列采用分段连续内存存储，每段固定大小，这使得两端的插入及删除操作非常高效。  
详细说明：  

- deque 采用分段连续内存存储，支持在两端 O(1) 时间复杂度的插入和删除操作。
- 分段存储使得 deque 可以在两端进行常数时间的操作，缺点是在中间插入时需要移动块指针，可能丢失部分迭代器。  
- 与 vector 不同，deque 不支持 reserve 操作，原因在于其非连续内存结构。

> 注意：deque 不支持 reserve 操作，请参照示例使用。

### 使用场景

- 需要在两端频繁插入和删除元素
- 需要随机访问元素
- 对中间元素的插入删除操作相对较少
- `push_front(const T& value)`: 在前端添加一个元素。

  ```cpp
  std::deque<int> deq;
  deq.push_front(5);
  ```

- `push_back(const T& value)`: 在末尾添加一个元素。

  ```cpp
  deq.push_back(10);
  ```

- `pop_front()`: 删除前端的元素。

  ```cpp
  deq.pop_front();
  ```

- `pop_back()`: 删除末尾的元素。

  ```cpp
  deq.pop_back();
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = deq.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (deq.empty()) {
      // 容器为空
  }
  ```

- `at(size_t pos)`: 访问指定位置的元素。

  ```cpp
  int value = deq.at(0);
  ```

- `clear()`: 清空所有元素。

  ```cpp
  deq.clear();
  ```

- `insert(iterator pos, const T& value)`: 在指定位置插入元素。

  ```cpp
  deq.insert(deq.begin(), 15);
  ```

- `erase(iterator pos)`: 删除指定位置的元素。

  ```cpp
  deq.erase(deq.begin());
  ```

- `emplace_front(Args&&... args)`: 在前端原位构造一个元素。

  ```cpp
  deq.emplace_front(20);
  ```

- `emplace_back(Args&&... args)`: 在末尾原位构造一个元素。

  ```cpp
  deq.emplace_back(25);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::deque<int> deq1; // 默认构造
std::deque<int> deq2(5, 10); // 5 个值为 10 的元素
std::deque<int> deq3 = {1, 2, 3, 4, 5}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
deq1.push_back(15);
deq1.emplace_back(20);
deq1.push_front(5);
deq1.emplace_front(10);
```

### 删除元素

```cpp
// 删除元素
deq1.pop_back();
deq1.pop_front();
deq1.erase(deq1.begin());
```

### 访问元素

```cpp
// 访问元素
int first = deq1.front();
int last = deq1.back();
int second = deq1.at(1);
```

### 容量操作

```cpp
// 容量操作
// 注意：deque内部为分段连续存储，不支持reserve与capacity操作
```

### 排序和反转

```cpp
// 排序和反转
std::sort(deq1.begin(), deq1.end());
std::reverse(deq1.begin(), deq1.end());
```

### 拼接操作

```cpp
// 拼接操作
std::deque<int> deq4 = {6, 7, 8};
deq1.insert(deq1.end(), deq4.begin(), deq4.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = deq1.begin(); it != deq1.end(); ++it) {
    std::cout << *it << " ";
}
```

### 其他常用函数

```cpp
resize(size_t count): 同 vector，调整 deque 大小。
deq1.resize(10);

shrink_to_fit(): 请求收缩未使用的内存（C++23起支持，部分编译器实现）。
deq1.shrink_to_fit();

data(): 返回指针指向内部数据（C++23起支持）。
int* ptr = deq1.data();
```

### 注意：deque 特有的限制

- `reserve()`: 不支持，因为deque内部结构是分段连续的
- `capacity()`: 不支持，原因同上
- `shrink_to_fit()`: 部分编译器支持，效果可能不明显

### 主要特点

- 支持在两端高效的插入和删除操作。
- 自动管理内存，适合频繁在两端操作的场景。
- 支持随机访问，但速度略低于 `vector`。

## list-双向链表

双向链表采用节点连续的内存链接，每个节点储存前后指针，允许在任意位置 O(1) 插入或删除，但不支持索引访问。  
详细说明：  

- 由于节点分散存储，list 在迭代时的局部性不如 vector，但在频繁中间修改时非常高效。  
- 即使插入或删除操作不会使其他迭代器失效，操作前仍需定位目标位置，时间复杂度为 O(n)。

> 优点：高效的中间插入删除；缺点：不支持随机访问。

### 使用场景

- 需要频繁在任意位置插入和删除元素
- 不需要随机访问元素
- 需要频繁的元素重排
- `push_front(const T& value)`: 在前端添加一个元素。

  ```cpp
  std::list<int> lst;
  lst.push_front(5);
  ```

- `push_back(const T& value)`: 在末尾添加一个元素。

  ```cpp
  lst.push_back(10);
  ```
  
- `pop_front()`: 删除前端的元素。

  ```cpp
  lst.pop_front();
  ```

- `pop_back()`: 删除末尾的元素。

  ```cpp
  lst.pop_back();
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = lst.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (lst.empty()) {
      // 容器为空
  }
  ```

- `clear()`: 清空所有元素。

  ```cpp
  lst.clear();
  ```

- `insert(iterator pos, const T& value)`: 在指定位置插入元素。

  ```cpp
  lst.insert(lst.begin(), 15);
  ```

- `erase(iterator pos)`: 删除指定位置的元素。

  ```cpp
  lst.erase(lst.begin());
  ```

- `splice(iterator pos, list& other)`: 将其他列表的元素移动到此列表。

  ```cpp
  std::list<int> other = {20, 25};
  lst.splice(lst.end(), other);
  ```

- `emplace_front(Args&&... args)`: 在前端原位构造一个元素。

  ```cpp
  lst.emplace_front(30);
  ```

- `emplace_back(Args&&... args)`: 在末尾原位构造一个元素。

  ```cpp
  lst.emplace_back(35);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::list<int> lst1; // 默认构造
std::list<int> lst2(5, 10); // 5 个值为 10 的元素
std::list<int> lst3 = {1, 2, 3, 4, 5}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
lst1.push_back(15);
lst1.emplace_back(20);
lst1.push_front(5);
lst1.emplace_front(10);
```

### 删除元素

```cpp
// 删除元素
lst1.pop_back();
lst1.pop_front();
lst1.erase(lst1.begin());
```

### 访问元素

```cpp
// 访问元素
int first = lst1.front();
int last = lst1.back();
int second = *(++lst1.begin());
```

### 容量操作

```cpp
// 容量操作
// list 不支持 reserve
size_t current_size = lst1.size();
```

### 排序和反转

```cpp
// 排序和反转
lst1.sort();
lst1.reverse();
```

### 拼接操作

```cpp
// 拼接操作
std::list<int> lst4 = {6, 7, 8};
lst1.splice(lst1.end(), lst4);
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = lst1.begin(); it != lst1.end(); ++it) {
    std::cout << *it << " ";
}
```

### 其他常用函数

```cpp
//merge(list& other): 合并另一个有序链表
lst1.merge(lst2);

//unique(): 移除相邻重复元素
lst1.unique();

//emplace(iterator pos, Args&&... args): 在指定位置原位构造元素
auto it = lst1.begin();
lst1.emplace(it, 50);
```

### list 特有的操作

- `splice_after()`: 移动元素到指定位置之后
- `merge()`: 合并两个已排序的链表
- `reverse()`: 反转整个链表
- `unique()`: 移除连续的重复元素

### list 的限制

- 不支持随机访问操作符 ([])
- 不支持算术运算的迭代器操作

### 主要特点

- 双向链表，支持高效的插入和删除操作。
- 不支持随机访问，适合需要频繁修改中间元素的场景。
- 自动管理内存，但占用更多内存空间。

### 关联式容器

## set-有序集合

有序集合基于平衡二叉树（通常为红黑树）实现，所有操作均具有 O(log n) 的时间复杂度。  
详细说明：  

- 元素在插入时自动排好序，内存占用相对较大。  
- 迭代器稳定性较好，删除一个元素仅使该元素的迭代器失效。

> 自动排序，适合存储唯一且有序的元素。

### 使用场景

- 需要维护有序的唯一元素集合
- 需要快速查找元素
- 需要范围查询功能
- `insert(const T& value)`: 插入一个元素。

  ```cpp
  std::set<int> s;
  s.insert(10);
  ```

- `erase(const T& value)`: 删除指定元素。

  ```cpp
  s.erase(10);
  ```

- `find(const T& value)`: 查找元素。

  ```cpp
  auto it = s.find(10);
  ```

- `count(const T& value) const`: 计算元素出现次数。

  ```cpp
  size_t cnt = s.count(10);
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = s.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (s.empty()) {
      // 容器为空
  }
  ```

- `clear()`: 清空所有元素。

  ```cpp
  s.clear();
  ```

- `emplace(Args&&... args)`: 原位插入一个元素。

  ```cpp
  s.emplace(15);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::set<int> s1; // 默认构造
std::set<int> s2 = {1, 2, 3, 4, 5}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
s1.insert(10);
s1.emplace(15);
```

### 删除元素

```cpp
// 删除元素
s1.erase(10);
```

### 访问元素

```cpp
// 访问元素
auto it = s1.find(15);
if (it != s1.end()) {
    std::cout << *it;
}
```

### 容量操作

```cpp
// 容量操作
size_t current_size = s1.size();
bool is_empty = s1.empty();
```

### 排序和反转

set 自动排序，不能反转

### 拼接操作

```cpp
// 拼接操作
std::set<int> s3 = {6, 7, 8};
s1.insert(s3.begin(), s3.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = s1.begin(); it != s1.end(); ++it) {
    std::cout << *it << " ";
}
```

### 其他常用函数

```cpp
lower_bound(const Key& key): 返回指向第一个不小于 key 的元素迭代器，适合用于范围查找。
auto lb = s1.lower_bound(2);

upper_bound(const Key& key): 返回指向第一个大于 key 的元素迭代器，对区间结束判断有帮助。
auto ub = s1.upper_bound(2);

equal_range(const Key& key): 同时返回 lower_bound 与 upper_bound 的迭代器对，表示所有等于 key 的元素范围。
auto range = s1.equal_range(2);
```

### 主要特点

- 元素唯一且自动有序。
- 基于红黑树实现，插入、删除、查找操作高效。
- 不支持随机访问。

### multiset-有序多重集合

允许存储重复的元素，并按照升序自动排序。
使用场景：需要记录重复值且希望元素自动排序时。

```cpp
std::multiset<int> ms;
ms.insert(10);
ms.insert(10); // 重复元素允许
```

## map-有序键值对

有序映射和 set 类似，底层也使用红黑树。  
详细说明：  

- 当使用 operator[] 进行元素访问时，如果键不存在，则会自动插入默认值，可能引起额外的内存分配和树重平衡。  
- 提供 lower_bound、upper_bound 等接口，便于高效的范围查询。

> 用于建立键值对应关系，并保持键的排序。

### 使用场景

- 需要建立键到值的映射关系
- 需要按键的顺序访问元素
- 需要高效的键值查找
- `insert(pair<const Key, T>& value)`: 插入一个键值对。

  ```cpp
  std::map<int, std::string> m;
  m.insert({1, "one"});
  ```

- `erase(const Key& key)`: 删除指定键的元素。

  ```cpp
  m.erase(1);
  ```

- `find(const Key& key)`: 查找键对应的元素。

  ```cpp
  auto it = m.find(1);
  ```

- `count(const Key& key) const`: 计算键出现次数。

  ```cpp
  size_t cnt = m.count(1);
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = m.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (m.empty()) {
      // 容器为空
  }
  ```

- `clear()`: 清空所有元素。

  ```cpp
  m.clear();
  ```

- `operator[](const Key& key)`: 访问或插入键对应的值。

  ```cpp
  m[2] = "two";
  ```

- `emplace(Args&&... args)`: 原位插入一个键值对。

  ```cpp
  m.emplace(3, "three");
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::map<int, std::string> m1; // 默认构造
std::map<int, std::string> m2 = {{1, "one"}, {2, "two"}}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
m1.insert({3, "three"});
m1.emplace(4, "four");
m1[5] = "five";
```

### 删除元素

```cpp
// 删除元素
m1.erase(3);
```

### 访问元素

```cpp
// 访问元素
auto it = m1.find(4);
if (it != m1.end()) {
    std::cout << it->second;
}
std::string value = m1[5];
```

### 容量操作

```cpp
// 容量操作
size_t current_size = m1.size();
bool is_empty = m1.empty();
```

### 排序和反转

map 自动按键排序，不能反转

### 拼接操作

```cpp
// 拼接操作
std::map<int, std::string> m3 = {{6, "six"}, {7, "seven"}};
m1.insert(m3.begin(), m3.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = m1.begin(); it != m1.end(); ++it) {
    std::cout << it->first << ": " << it->second << " ";
}
```

### 其他常用函数

```cpp
lower_bound(const Key& key): 返回第一个键不小于 key 的迭代器，用于范围查询。
auto lb = m1.lower_bound("two");

upper_bound(const Key& key): 返回第一个大于 key 的迭代器。
auto ub = m1.upper_bound("two");

equal_range(const Key& key): 返回包含 key 的元素范围，由 lower_bound 与 upper_bound 组成。
auto range = m1.equal_range("two");
```

### map 默认初始值设置

对于 std::map，当使用 operator[] 访问不存在的键时，会调用对应值的默认构造函数。例如：

```cpp
std::map<std::string, int> mp;
int value = mp["not_exist"]; // 自动插入键 "not_exist" 且 value 默认为 0
```

如果想设置其他默认值，可在判断后赋值：

```cpp
if (mp.find("key") == mp.end()) {
    mp["key"] = 42;
}
```

### 主要特点

- 键值对，键唯一且自动有序。
- 基于红黑树实现，插入、删除、查找操作高效。
- 支持通过键直接访问或修改值。

### multimap-有序多重映射

允许相同键对应多个值，自动按键的升序排序。
使用场景：需要建立一个键映射多个值时。

```cpp
std::multimap<int, std::string> mm;
mm.insert({1, "one"});
mm.insert({1, "uno"}); // 同一键的重复插入
```

# 无序关联式容器

## unordered_set-哈希集合

基于哈希表实现，所有查找、插入操作在平均情况下为 O(1)。  
详细说明：  

- 元素无序存储，内存占用相对较小。
- 内部采用开放地址或链地址法解决冲突，不同实现对内存和性能的要求不同。  
- 当负载因子过高时，rehash 操作会导致所有元素重新分布，迭代器也可能失效。

> 优点：查找速度快，无须保持顺序。

### 使用场景

- 只需要判断元素是否存在
- 不需要元素保持有序
- 追求最快的元素查找速度
- `insert(const T& value)`: 插入一个元素。

  ```cpp
  std::unordered_set<int> us;
  us.insert(10);
  ```

- `erase(const T& value)`: 删除指定元素。

  ```cpp
  us.erase(10);
  ```

- `find(const T& value)`: 查找元素。

  ```cpp
  auto it = us.find(10);
  ```

- `count(const T& value) const`: 计算元素出现次数。

  ```cpp
  size_t cnt = us.count(10);
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = us.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (us.empty()) {
      // 容器为空
  }
  ```

- `clear()`: 清空所有元素。

  ```cpp
  us.clear();
  ```

- `emplace(Args&&... args)`: 原位插入一个元素。

  ```cpp
  us.emplace(15);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::unordered_set<int> us1; // 默认构造
std::unordered_set<int> us2 = {1, 2, 3, 4, 5}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
us1.insert(10);
us1.emplace(15);
```

### 删除元素

```cpp
// 删除元素
us1.erase(10);
```

### 访问元素

```cpp
// 访问元素
auto it = us1.find(15);
if (it != us1.end()) {
    std::cout << *it;
}
```

### 容量操作

```cpp
// 容量操作
size_t current_size = us1.size();
bool is_empty = us1.empty();
```

### 排序和反转

unordered_set 不支持排序和反转。

### 拼接操作

```cpp
// 拼接操作
std::unordered_set<int> us3 = {6, 7, 8};
us1.insert(us3.begin(), us3.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = us1.begin(); it != us1.end(); ++it) {
    std::cout << *it << " ";
}
```

### 其他常用函数

```cpp
bucket_count(): 返回当前底层哈希桶的数量，有助于了解哈希表内部结构。
size_t n = us1.bucket_count();

load_factor(): 返回当前的负载因子，即元素数量与桶数的比值，可用于调优容器性能。
float lf = us1.load_factor();

rehash(size_t n): 重新配置哈希桶数量，能改变负载因子，可能导致元素重排。
us1.rehash(20);
```

### 主要特点

- 元素唯一，基于哈希表实现，无序存储。
- 插入、删除、查找操作平均常数时间复杂度。
- 不支持有序遍历。

## unordered_map-哈希表

详细说明与 unordered_set 类似，另外键值对的存储允许快速的键值映射。  

- 注意在使用 operator[] 时，如果键不存在会创建新项，可能带来意外的内存分配。

基于哈希表实现的键值对容器，提供常数时间的元素访问。

> 常用于快速键值查找和数据插入。

### 使用场景

- 需要快速的键值查找
- 不需要键值对保持有序
- 存储大量数据时需要高效查找
- `insert(pair<const Key, T>& value)`: 插入一个键值对。

  ```cpp
  std::unordered_map<int, std::string> um;
  um.insert({1, "one"});
  um.insert({2, "two"});
  um.insert({3, "three"});
  um.emplace(4, "four");
  um[5] = "five";
  ```

- `erase(const Key& key)`: 删除指定键的元素。

  ```cpp
  um.erase(1);
  ```

- `find(const Key& key)`: 查找键对应的元素。

  ```cpp
  auto it = um.find(1);
  ```

- `count(const Key& key) const`: 计算键出现次数。

  ```cpp
  size_t cnt = um.count(1);
  ```

- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = um.size();
  ```

- `empty() const`: 检查容器是否为空。

  ```cpp
  if (um.empty()) {
      // 容器为空
  }
  ```

- `clear()`: 清空所有元素。

  ```cpp
  um.clear();
  ```

- `operator[](const Key& key)`: 访问或插入键对应的值。

  ```cpp
  um[2] = "two";
  ```

- `emplace(Args&&... args)`: 原位插入一个键值对。

  ```cpp
  um.emplace(3, "three");
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::unordered_map<int, std::string> um1; // 默认构造
std::unordered_map<int, std::string> um2 = {{1, "one"}, {2, "two"}}; // 使用初始化列表
```

### 添加元素

```cpp
// 添加元素
um1.insert({3, "three"});
um1.emplace(4, "four");
um1[5] = "five";
```

### 删除元素

```cpp
// 删除元素
um1.erase(3);
```

### 访问元素

```cpp
// 访问元素
auto it = um1.find(4);
if (it != um1.end()) {
    std::cout << it->second;
}
std::string value = um1[5];
```

### 容量操作

```cpp
// 容量操作
size_t current_size = um1.size();
bool is_empty = um1.empty();
```

### 排序和反转

```cpp
// 排序和反转
// unordered_map 不支持排序和反转
```

### 拼接操作

```cpp
// 拼接操作
std::unordered_map<int, std::string> um3 = {{6, "six"}, {7, "seven"}};
um1.insert(um3.begin(), um3.end());
```

### 迭代器操作

```cpp
// 迭代器操作
for (auto it = um1.begin(); it != um1.end(); ++it) {
    std::cout << it->first << ": " << it->second << " ";
}
```

### 其他常用函数

```cpp
bucket_count(): 返回哈希桶数量。
size_t bn = um1.bucket_count();

load_factor(): 当前负载因子，衡量桶的利用率。
float lf = um1.load_factor();

rehash(size_t n): 根据指定的桶数重新安排哈希表，可能会重新分布所有元素。
um1.rehash(20);
```

### unordered_map 默认初始值设置

std::unordered_map 也具有相同特性，例如：

```cpp
std::unordered_map<std::string, std::string> um;
std::string s = um["non_exist"]; // 自动插入，s 为 ""
```

自定义默认值设置：

```cpp
if (um.find("key") == um.end()) {
    um["key"] = "default_value";
}
```

### 主要特点

- 键值对，键唯一，基于哈希表实现，无序存储。
- 插入、删除、查找操作平均常数时间复杂度。
- 支持通过键直接访问或修改值。

# 容器适配器

## queue-队列

队列是一种 FIFO 数据结构，内部一般使用 deque 实现。  
详细说明：  

- 由于只允许访问队首和队尾，不支持迭代器，因此无法直接对队列内部数据做复杂操作。  
- 在多线程环境中，队列必须进行额外的同步来保证数据的一致性。

> 先进先出(FIFO)结构，常用于任务调度及广度优先搜索。

### 使用场景

- 需要按照先进先出的顺序处理元素
- 实现广度优先搜索
- 需要按照时间顺序处理任务
- `push(const T& value)`: 添加一个元素到队列末尾。

  ```cpp
  std::queue<int> q;
  q.push(10);
  ```

- `pop()`: 移除队列前端的元素。

  ```cpp
  q.pop();
  ```

- `front()`: 访问队列前端的元素。

  ```cpp
  int front = q.front();
  ```
  
- `back()`: 访问队列末尾的元素。

  ```cpp
  int back = q.back();
  ```

- `empty() const`: 检查队列是否为空。

  ```cpp
  if (q.empty()) {
      // 队列为空
  }
  ```

- `size() const`: 返回队列中元素的个数。

  ```cpp
  size_t size = q.size();
  ```

- `emplace(Args&&... args)`: 原位添加一个元素到队列末尾。

  ```cpp
  q.emplace(20);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::queue<int> q1; // 默认构造
std::queue<int> q2;
q2.push(1);
q2.push(2);
```

### 添加元素

```cpp
// 添加元素
q1.push(10);
q1.emplace(15);
```

### 删除元素

```cpp
// 删除元素
q1.pop();
```

### 访问元素

```cpp
// 访问元素
int front = q1.front();
int back = q1.back();
```

### 容量操作

```cpp
// 容量操作
size_t current_size = q1.size();
bool is_empty = q1.empty();
```

### 排序和反转

队列不支持排序和反转。

### 拼接操作

队列不支持直接拼接，可以通过循环添加元素。

```cpp
std::queue<int> q3;
q3.push(20);
q3.push(25);
while (!q3.empty()) {
    q1.push(q3.front());
    q3.pop();
}
```

### 迭代器操作

队列不支持迭代器，因此无法进行迭代器相关的操作。

### 其他常用函数

```cpp
emplace(Args&&... args): 原位构造并添加元素
q1.emplace(30);

swap(queue& other): 交换两个队列
q1.swap(q2);
```

### 主要特点

- 先进先出（FIFO）结构。
- 不允许随机访问，只能访问队头和队尾元素。
- 基于其他容器（默认是 `deque`）实现。

## priority_queue-优先队列

优先队列基于堆实现，默认是最大堆。  
详细说明：  

- 内部维护堆结构，使得每次获取 top 操作都是 O(1)，而插入和删除操作都是 O(log n)。  
- 可通过自定义比较器改变排序规则，例如实现最小堆。

> 默认实现最大堆，可根据需定制排序规则。

### 使用场景

- 需要维护一个动态的有序序列
- 实现堆排序
- 需要频繁获取最大/最小元素
- `push(const T& value)`: 添加一个元素。

  ```cpp
  std::priority_queue<int> pq;
  pq.push(30);
  ```

- `pop()`: 移除优先级最高的元素。

  ```cpp
  pq.pop();
  ```

- `top() const`: 访问优先级最高的元素。

  ```cpp
  int top = pq.top();
  ```

- `empty() const`: 检查优先队列是否为空。

  ```cpp
  if (pq.empty()) {
      // 优先队列为空
  }
  ```

- `size() const`: 返回优先队列中元素的个数。

  ```cpp
  size_t size = pq.size();
  ```

- `emplace(Args&&... args)`: 原位添加一个元素。

  ```cpp
  pq.emplace(40);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::priority_queue<int> pq1; // 默认构造
std::priority_queue<int> pq2;
pq2.push(1);
pq2.push(2);
```

### 添加元素

```cpp
// 添加元素
pq1.push(30);
pq1.emplace(35);
```

### 删除元素

```cpp
// 删除元素
pq1.pop();
```

### 访问元素

```cpp
// 访问元素
int top = pq1.top();
```

### 容量操作

```cpp
// 容量操作
size_t current_size = pq1.size();
bool is_empty = pq1.empty();
```

### 排序和反转

优先队列自动根据优先级排序，不支持反转。

### 拼接操作

优先队列不支持直接拼接，可以通过循环添加元素。

```cpp
std::priority_queue<int> pq3;
pq3.push(40);
pq3.push(45);
while (!pq3.empty()) {
    pq1.push(pq3.top());
    pq3.pop();
}
```

### 迭代器操作

优先队列不支持迭代器，因此无法进行迭代器相关的操作。

### 其他常用函数

```cpp
emplace(Args&&... args): 原位构造并添加元素
pq1.emplace(50);

swap(priority_queue& other): 交换两优先队列
pq1.swap(pq2);
```

### 优先队列深入说明及用法

优先队列基于堆实现，默认是最大堆。可以通过自定义比较器实现最小堆或其他排序规则。

例如，自定义比较器实现最小堆：

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
    // 默认 priority_queue 为最大堆
    std::priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    
    // 自定义比较器实现最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    std::cout << "最大堆顶元素: " << maxHeap.top() << std::endl;
    std::cout << "最小堆顶元素: " << minHeap.top() << std::endl;
    return 0;
}
```

优先队列常用操作：

- push/emplace: 添加元素
- pop: 移除顶端元素
- top: 访问顶端元素
- empty/size: 检查容器状态

## stack-栈

栈是一种 LIFO 数据结构，通常使用 deque 实现。  
详细说明：  

- 栈中的所有操作均为常数时间，但由于不支持迭代器，其调试和错误检查较为困难。  
- 主要适用于递归调用、表达式求值等场景。

> 后进先出(LIFO)结构，适合实现深度优先搜索或函数调用栈。

### 使用场景

- 需要按照后进先出的顺序处理元素
- 实现深度优先搜索
- 处理括号匹配等问题
- 实现函数调用栈
- `push(const T& value)`: 添加一个元素到栈顶。

  ```cpp
  std::stack<int> s;
  s.push(10);
  ```

- `pop()`: 移除栈顶元素。

  ```cpp
  s.pop();
  ```

- `top()`: 访问栈顶元素。

  ```cpp
  int top = s.top();
  ```

- `empty() const`: 检查栈是否为空。

  ```cpp
  if (s.empty()) {
      // 栈为空
  }
  ```

- `size() const`: 返回栈中元素的个数。

  ```cpp
  size_t size = s.size();
  ```

- `emplace(Args&&... args)`: 原位添加一个元素到栈顶。

  ```cpp
  s.emplace(20);
  ```

### 构造和初始化

```cpp
// 构造和初始化
std::stack<int> s1; // 默认构造
std::stack<int> s2;
s2.push(1);
s2.push(2);
```

### 添加元素

```cpp
// 添加元素
s1.push(10);
s1.emplace(15);
```

### 删除元素

```cpp
// 删除元素
s1.pop();
```

### 访问元素

```cpp
// 访问元素
int top = s1.top();
```

### 容量操作

```cpp
// 容量操作
size_t current_size = s1.size();
bool is_empty = s1.empty();
```

### 排序和反转

栈不支持排序和反转操作。

### 拼接操作

栈不支持直接拼接，可以通过临时栈实现。

```cpp
std::stack<int> s3;
s3.push(20);
s3.push(25);
std::stack<int> temp;
while (!s3.empty()) {
    temp.push(s3.top());
    s3.pop();
}
while (!temp.empty()) {
    s1.push(temp.top());
    temp.pop();
}
```

### 迭代器操作

栈不支持迭代器，因此无法进行迭代器相关的操作。

### 其他常用函数

```cpp
emplace(Args&&... args): 原位构造并添加元素
s1.emplace(30);

swap(stack& other): 交换两个栈
s1.swap(s2);
```

### 主要特点

- 后进先出（LIFO）结构
- 只允许访问栈顶元素
- 基于其他容器（默认是 deque）实现

# 位集合

## bitset-固定大小位容器

用于存储固定数量的二进制位，支持高效位运算。  
详细说明：  

- 因为固定大小，bitset 的操作在编译期间就确定，性能和内存使用非常优化。  
- 在处理大批量布尔值数据时，比 vector<bool> 更加高效且易于理解。

用于存储固定数量的二进制位，并支持高效的位操作。
使用场景：需要按位处理或存储大量布尔标志时。

```cpp
std::bitset<8> bs; 
bs.set(0);       // 将第 0 位置为 1
bool bit0 = bs.test(0);  // 检查第 0 位是否为 1
bs.reset(0);     // 将第 0 位重置为 0
bs.flip();       // 所有位取反
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

#### 示例：利用 map 建立单词计数器

```cpp
#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main() {
    string text = "hello world hello STL";
    map<string, int> wordCount;
    istringstream iss(text);
    string word;
    while(iss >> word) {
        ++wordCount[word];
    }
    // 输出计数结果
    for(const auto& p: wordCount) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}
```

#### 示例：利用 unordered_map 进行快速查找

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string, int> lookup = { {"apple", 10}, {"banana", 20} };
    string key = "apple";
    if(lookup.find(key) != lookup.end()){
        cout << key << " 对应的值是: " << lookup[key] << endl;
    } else {
        cout << key << " 不存在于字典中" << endl;
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

#### 注意事项

1. 选择容器时要考虑迭代器的功能需求
2. 不同类别的迭代器性能差异较大
3. 随机访问迭代器功能最强大但并非所有容器都支持
4. 使用迭代器时要注意避免失效情况

这些迭代器类别的区别对于容器的选择和使用策略有重要影响，建议根据实际需求选择合适的容器类型。

### 异常安全说明

- 部分操作（如vector::at()）在访问越界时会抛出 std::out_of_range 异常，应使用try-catch进行异常捕获：

  ```cpp
  try {
      int value = vec.at(10); // 可能抛出异常
  } catch (const std::out_of_range& e) {
      // 处理异常
  }
  ```

### 注意：set和map的键为const，不允许通过迭代器进行修改，如下示例

```cpp
std::set<int> s = {1, 2, 3};
auto it = s.begin();
// *it = 4; // 错误！set的键不可修改
```
