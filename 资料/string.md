# C++ String 类函数及用法

C++标准库中的`string`类提供了丰富的字符串操作功能。以下是`string`类的主要函数及其用法。

## 基本操作

### 构造函数

```cpp
string s;                    // 创建空字符串
string s("Hello");           // 用C风格字符串初始化
string s(5, 'a');            // 创建字符串"aaaaa"
string s(str, pos, len);     // 从另一个string的pos位置开始，复制len个字符
string s(str.begin(), str.end()); // 使用迭代器范围初始化
```

### 赋值

```cpp
string s;
s = "Hello";                 // 赋值C风格字符串
s = another_string;          // 赋值另一个string对象
s = 'A';                     // 赋值单个字符
s.assign("Hello");           // 赋值函数
s.assign(5, 'a');            // 赋值5个'a'
s.assign(str, pos, len);     // 赋值str中从pos开始的len个字符
```

### 访问元素

```cpp
char c = s[0];               // 使用[]操作符访问（不进行边界检查）
char c = s.at(0);            // 使用at()函数访问（进行边界检查）
char& front = s.front();     // 访问第一个字符 (C++11)
char& back = s.back();       // 访问最后一个字符 (C++11)
const char* c_str = s.c_str(); // 获取C风格字符串
```

### 迭代器

```cpp
auto it = s.begin();         // 指向第一个字符的迭代器
auto it = s.end();           // 指向最后一个字符之后的迭代器
auto it = s.rbegin();        // 指向最后一个字符的反向迭代器
auto it = s.rend();          // 指向第一个字符之前的反向迭代器
```

## 字符串操作

### 添加和连接

```cpp
s += "World";                // 追加C风格字符串
s += another_string;         // 追加另一个string对象
s += 'a';                    // 追加单个字符

s.append("World");           // 追加C风格字符串
s.append(another_string);    // 追加另一个string对象
s.append(5, 'a');            // 追加5个'a'
s.append(str, pos, len);     // 追加str中从pos开始的len个字符

s.push_back('a');            // 在末尾添加单个字符

s = s1 + s2;                 // 字符串连接
```

### 插入

```cpp
s.insert(pos, "text");       // 在pos位置插入C风格字符串
s.insert(pos, str);          // 在pos位置插入string对象
s.insert(pos, str, pos1, len); // 在pos位置插入str中从pos1开始的len个字符
s.insert(pos, n, 'a');       // 在pos位置插入n个字符'a'
s.insert(iterator, 'a');     // 在迭代器位置插入字符
s.insert(iterator, n, 'a');  // 在迭代器位置插入n个字符'a'
```

### 删除

```cpp
s.erase(pos, len);           // 从pos位置开始删除len个字符
s.erase(iterator);           // 删除迭代器指向的字符
s.erase(iterator1, iterator2); // 删除[iterator1, iterator2)范围的字符
s.pop_back();                // 删除最后一个字符 (C++11)
s.clear();                   // 清空字符串
```

### 替换

```cpp
s.replace(pos, len, "new");  // 用"new"替换从pos开始的len个字符
s.replace(pos, len, str);    // 用str替换从pos开始的len个字符
s.replace(pos, len, str, pos1, len1); // 用str中从pos1开始的len1个字符替换从pos开始的len个字符
s.replace(pos, len, n, 'a'); // 用n个'a'替换从pos开始的len个字符
s.replace(it1, it2, "new");  // 用"new"替换[it1, it2)范围的字符
```

### 子串

```cpp
string sub = s.substr(pos, len); // 从pos开始，提取len个字符的子串
```

### 交换

```cpp
s1.swap(s2);                 // 交换s1和s2的内容
swap(s1, s2);                // 使用全局swap函数
```

## 字符串信息

### 大小和容量

```cpp
size_t len = s.size();       // 获取字符串长度
size_t len = s.length();     // 同size()
bool empty = s.empty();      // 检查字符串是否为空
size_t cap = s.capacity();   // 获取当前分配的内存容量
s.resize(n);                 // 调整字符串大小为n
s.resize(n, 'a');            // 调整字符串大小为n，新增部分用'a'填充
s.reserve(n);                // 预留n个字符的内存空间
s.shrink_to_fit();           // 减少容量以适应实际大小 (C++11)
size_t max = s.max_size();   // 获取string可能的最大长度
```

### 查找与搜索

```cpp
// 查找字符或子串，返回位置或string::npos（如果未找到）
size_t pos = s.find("text");       // 查找子串第一次出现的位置
size_t pos = s.find("text", pos);  // 从pos开始查找
size_t pos = s.find('a');          // 查找字符
size_t pos = s.find('a', pos);     // 从pos开始查找字符

// 逆向查找，从字符串末尾开始搜索
size_t pos = s.rfind("text");
size_t pos = s.rfind("text", pos);
size_t pos = s.rfind('a');
size_t pos = s.rfind('a', pos);

// 查找字符集合中的任一字符第一次出现位置
size_t pos = s.find_first_of("aeiou");      // 查找任一元音字母
size_t pos = s.find_first_of("aeiou", pos); // 从pos开始查找

// 查找不在字符集合中的任一字符第一次出现位置
size_t pos = s.find_first_not_of("aeiou");
size_t pos = s.find_first_not_of("aeiou", pos);

// 查找字符集合中的任一字符最后一次出现位置
size_t pos = s.find_last_of("aeiou");
size_t pos = s.find_last_of("aeiou", pos);

// 查找不在字符集合中的任一字符最后一次出现位置
size_t pos = s.find_last_not_of("aeiou");
size_t pos = s.find_last_not_of("aeiou", pos);
```

### 比较

```cpp
int result = s.compare("text");       // 与C风格字符串比较
int result = s.compare(str);          // 与另一个string对象比较
int result = s.compare(pos, len, "text"); // 比较s中从pos开始的len个字符与"text"
int result = s.compare(pos, len, str, pos1, len1); // 比较各自的子串

// 比较结果
// 0: 相等
// <0: s小于比较对象
// >0: s大于比较对象

// 操作符比较
bool equal = (s1 == s2);
bool not_equal = (s1 != s2);
bool less = (s1 < s2);
bool less_equal = (s1 <= s2);
bool greater = (s1 > s2);
bool greater_equal = (s1 >= s2);
```

## 数值转换 (C++11)

### 字符串转数值

```cpp
int i = stoi(s);
long l = stol(s);
long long ll = stoll(s);
unsigned long ul = stoul(s);
unsigned long long ull = stoull(s);
float f = stof(s);
double d = stod(s);
long double ld = stold(s);
```

### 数值转字符串

```cpp
string s = to_string(42);    // 整数转字符串
string s = to_string(3.14);  // 浮点数转字符串
```

## 实用技巧

### 遍历字符串

```cpp
// 使用索引
for (size_t i = 0; i < s.length(); i++) {
    cout << s[i];
}

// 使用迭代器
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it;
}

// 使用范围for循环 (C++11)
for (char c : s) {
    cout << c;
}
```

### 分割字符串

```cpp
// 分割字符串（自定义函数示例）
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
```

### 字符串流

```cpp
#include <sstream>

string s = "42 3.14 Hello";
istringstream iss(s);
int i;
double d;
string word;
iss >> i >> d >> word;  // i=42, d=3.14, word="Hello"

ostringstream oss;
oss << "Value: " << 42 << " " << 3.14;
string result = oss.str();  // result="Value: 42 3.14"
```

### 大小写转换

```cpp
// 需要包含 <algorithm>
string s = "Hello World";
transform(s.begin(), s.end(), s.begin(), ::toupper);  // 转为大写
transform(s.begin(), s.end(), s.begin(), ::tolower);  // 转为小写
```

## 实际应用示例

### 1. 字符串拼接

```cpp
string firstName = "John";
string lastName = "Doe";
string fullName = firstName + " " + lastName;  // "John Doe"
```

### 2. 子串提取

```cpp
string email = "user@example.com";
size_t atPos = email.find('@');
string username = email.substr(0, atPos);  // "user"
string domain = email.substr(atPos + 1);   // "example.com"
```

### 3. 字符串替换

```cpp
string text = "Hello [name], welcome to [city]!";
size_t pos = 0;
while ((pos = text.find("[name]", pos)) != string::npos) {
    text.replace(pos, 6, "John");
    pos += 4;  // 替换后字符串长度的调整
}
pos = 0;
while ((pos = text.find("[city]", pos)) != string::npos) {
    text.replace(pos, 6, "New York");
    pos += 8;
}
// 结果: "Hello John, welcome to New York!"
```

### 4. 检查前缀和后缀

```cpp
bool hasPrefix(const string& str, const string& prefix) {
    return str.substr(0, prefix.size()) == prefix;
}

bool hasSuffix(const string& str, const string& suffix) {
    if (str.length() < suffix.length()) return false;
    return str.substr(str.length() - suffix.length()) == suffix;
}

// C++20提供了starts_with和ends_with方法
// str.starts_with(prefix);
// str.ends_with(suffix);
```

### 5. 去除首尾空白

```cpp
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}
```

## 注意事项

1. `string`类提供边界检查和不提供边界检查的方法（如`at()`和`[]`）。
2. 在频繁追加操作时，应预先使用`reserve()`分配足够的内存空间以提升性能。
3. 字符串搜索函数如果没找到目标，会返回`string::npos`。
4. C++11引入了移动语义，可以显著提高string操作的性能。
5. 使用`c_str()`可以获取C风格字符串，但需注意该指针的生命周期。

这些是C++ string类的主要功能和用法，熟练掌握这些操作可以有效地处理各种字符串相关问题。
