# C++ STL容器使用指南

> 本文档详细介绍了C++ STL容器的分类、使用方法、性能对比及最佳实践。

## 目录
- [容器分类](#容器分类)
  - [序列式容器](#序列式容器)
    - [vector](#vector-动态数组)
    - [deque](#deque-双端队列)
    - [list](#list-双向链表)
  - [关联式容器](#关联式容器)
    - [set](#set-有序集合)
    - [map](#map-有序键值对)
  - [无序关联式容器](#无序关联式容器)
    - [unordered_set](#unordered_set-哈希集合)
    - [unordered_map](#unordered_map-哈希表)
  - [容器适配器](#容器适配器)
    - [queue](#queue-队列)
    - [priority_queue](#priority_queue-优先队列)
    - [stack](#stack-栈)
- [性能对比](#性能对比)
- [最佳实践](#最佳实践)
- [查找操作详解](#查找操作详解)

## 容器分类

### 序列式容器

#### vector: 动态数组

动态数组是最常用的容器，它提供了快速的随机访问能力和高效的尾部操作。

> 小贴士：适用于需要快速随机访问和尾部操作的场景。

### 使用场景

- 需要频繁随机访问元素
- 主要在尾部进行插入和删除操作
- 需要动态改变容器大小
- `push_back(const T& value)`: 在末尾添加一个元素。

  ```cpp
  std::vector<int> vec;
  vec.push_back(10);
  ```
- `pop_back()`: 删除末尾的元素。

  ```cpp
  vec.pop_back();
  ```
- `size() const`: 返回容器中元素的个数。

  ```cpp
  size_t size = vec.size();
  ```
- `empty() const`: 检查容器是否为空。

  ```cpp
  if (vec.empty()) {
      // 容器为空
  }
  ```
- `at(size_t pos)`: 访问指定位置的元素。

  ```cpp
  int value = vec.at(0);
  ```
- `clear()`: 清空所有元素。

  ```cpp
  vec.clear();
  ```
- `insert(iterator pos, const T& value)`: 在指定位置插入元素。

  ```cpp
  vec.insert(vec.begin(), 5);
  ```
- `erase(iterator pos)`: 删除指定位置的元素。

  ```cpp
  vec.erase(vec.begin());
  ```
- `emplace_back(Args&&... args)`: 在末尾原位构造一个元素。

  ```cpp
  vec.emplace_back(20);
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
resize(size_t count): 调整容器大小
vec1.resize(10);

shrink_to_fit(): 请求容器收缩至当前大小
vec1.shrink_to_fit();

data(): 返回指向内部数组首元素的指针
int* ptr = vec1.data();

begin(), end(), rbegin(), rend() 等迭代器接口
const 版本对应 cbegin(), cend(), crbegin(), crend()
```

### 反向迭代器变体
- `rbegin()`, `rend()`: 用于反向迭代
- `crbegin()`, `crend()`: const 反向迭代器

### emplace系列变体
- `emplace()`: 原位构造，C++17后支持
- `emplace_back()`: 在尾部原位构造
- `emplace_hint()`: 提供插入位置提示的原位构造

### 主要特点：

- 动态大小，自动管理内存。
- 支持快速随机访问。
- 高效的尾部插入和删除操作。

#### deque: 双端队列

双端队列支持在两端进行快速插入和删除操作，同时也允许随机访问。

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
deq1.reserve(100); // 预留空间（注意：deque 没有 reserve，示例仅供参考）
size_t current_capacity = deq1.capacity(); // 此操作在 deque 中不可用
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
resize(size_t count): 调整容器大小
deq1.resize(10);

shrink_to_fit() (C++23 提供，部分编译器支持)
deq1.shrink_to_fit();

data() (C++23 提供，部分编译器支持)
int* ptr = deq1.data();
```

### 注意：deque 特有的限制
- `reserve()`: 不支持，因为deque内部结构是分段连续的
- `capacity()`: 不支持，原因同上
- `shrink_to_fit()`: 部分编译器支持，效果可能不明显

### 主要特点：

- 支持在两端高效的插入和删除操作。
- 自动管理内存，适合频繁在两端操作的场景。
- 支持随机访问，但速度略低于 `vector`。

#### list: 双向链表

双向链表支持在任何位置进行常数时间的插入和删除操作。

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
merge(list& other): 合并另一个有序链表
lst1.merge(lst2);

unique(): 移除相邻重复元素
lst1.unique();

emplace(iterator pos, Args&&... args): 在指定位置原位构造元素
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

### 主要特点：

- 双向链表，支持高效的插入和删除操作。
- 不支持随机访问，适合需要频繁修改中间元素的场景。
- 自动管理内存，但占用更多内存空间。

### 关联式容器

#### set: 有序集合

有序集合自动将元素按升序排列，并保证元素的唯一性。

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
lower_bound(const Key& key): 返回第一个不小于 key 的迭代器
auto lb = s1.lower_bound(2);

upper_bound(const Key& key): 返回第一个大于 key 的迭代器
auto ub = s1.upper_bound(2);

equal_range(const Key& key): 同时获取 lower_bound 和 upper_bound
auto range = s1.equal_range(2);
```

### 主要特点：

- 元素唯一且自动有序。
- 基于红黑树实现，插入、删除、查找操作高效。
- 不支持随机访问。

#### map: 有序键值对

有序映射存储键值对，并按键的升序排列。

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
lower_bound(const Key& key): 返回第一个不小于 key 的迭代器
auto lb = m1.lower_bound(2);

upper_bound(const Key& key): 返回第一个大于 key 的迭代器
auto ub = m1.upper_bound(2);

equal_range(const Key& key): 同时获取 lower_bound 和 upper_bound
auto range = m1.equal_range(2);
```

### 主要特点：

- 键值对，键唯一且自动有序。
- 基于红黑树实现，插入、删除、查找操作高效。
- 支持通过键直接访问或修改值。

### 无序关联式容器

#### unordered_set: 哈希集合

基于哈希表实现的集合，提供常数时间的元素访问。

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
bucket_count(): 返回当前哈希桶数量
size_t n = us1.bucket_count();

load_factor(): 返回当前负载因子
float lf = us1.load_factor();

rehash(size_t n): 重新配置哈希桶数量
us1.rehash(20);
```

### 主要特点：

- 元素唯一，基于哈希表实现，无序存储。
- 插入、删除、查找操作平均常数时间复杂度。
- 不支持有序遍历。

#### unordered_map: 哈希表

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
bucket_count(): 返回当前哈希桶数量
size_t bn = um1.bucket_count();

load_factor(): 返回当前负载因子
float lf = um1.load_factor();

rehash(size_t n): 重新配置哈希桶数量
um1.rehash(20);
```

### 主要特点：

- 键值对，键唯一，基于哈希表实现，无序存储。
- 插入、删除、查找操作平均常数时间复杂度。
- 支持通过键直接访问或修改值。

### 容器适配器

#### queue: 队列

实现先进先出(FIFO)的数据结构。

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

### 主要特点：

- 先进先出（FIFO）结构。
- 不允许随机访问，只能访问队头和队尾元素。
- 基于其他容器（默认是 `deque`）实现。

#### priority_queue: 优先队列

维护一个元素有序的队列，默认为最大堆。

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

### 主要特点：

- 元素按优先级自动排序，默认是最大堆。
- 只允许访问和修改最高优先级的元素。
- 基于其他容器（默认是 `vector`）实现。

#### stack: 栈

实现后进先出(LIFO)的数据结构。

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

### 主要特点：

- 后进先出（LIFO）结构
- 只允许访问栈顶元素
- 基于其他容器（默认是 deque）实现

## 性能对比

增强表格排版如下：

| 容器类型      | 随机访问 | 插入/删除(开始) | 插入/删除(中间) | 插入/删除(结尾) | 查找     |
| ------------- | :------: | :-----------: | :-----------: | :-----------: | :------: |
| vector        | O(1)     | O(n)          | O(n)          | O(1)          | O(n)     |
| deque         | O(1)     | O(1)          | O(n)          | O(1)          | O(n)     |
| list          | O(n)     | O(1)          | O(1)          | O(1)          | O(n)     |
| set           | O(log n) | O(log n)      | O(log n)      | O(log n)      | O(log n) |
| map           | O(log n) | O(log n)      | O(log n)      | O(log n)      | O(log n) |
| unordered_set | N/A      | O(1)          | O(1)          | O(1)          | O(1)     |
| unordered_map | N/A      | O(1)          | O(1)          | O(1)          | O(1)     |

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

### 常见陷阱和注意事项

1. vector
   - 频繁在中间插入可能导致性能问题
   - resize vs reserve 的区别
   - 避免频繁的 push_back 导致重新分配

2. deque
   - 内存不连续，不能获取底层数组
   - 迭代器失效条件比 vector 更严格

3. list
   - 双向链表额外内存开销大
   - 不支持随机访问

4. set/map
   - 插入重复键的行为
   - 迭代器是只读的

5. unordered_set/map
   - 哈希冲突对性能的影响
   - 自定义类型需要提供哈希函数

6. queue/priority_queue
   - 容器适配器的限制
   - 优先级定制

## 查找操作详解

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

### 查找最佳实践

1. 对于有序序列，优先使用二分查找 (`binary_search`, `lower_bound`, `upper_bound`)
2. 对于关联容器，优先使用成员函数 `find` 而不是算法 `std::find`
3. 需要频繁查找时，考虑使用哈希容器 (`unordered_set/map`)
4. 需要查找范围时，使用 `equal_range`
5. 对于 map/unordered_map，优先使用 `find` 而不是 `operator[]` 检查键是否存在
