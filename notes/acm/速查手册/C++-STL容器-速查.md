# C++ STL 容器速查

> 用途：**做题时「这个容器怎么用 / 该选哪个 / 有什么坑」的速查**
> 整理时间：2026-10-20
> 配套：`C++-OOP-对照Python.md`（类语法）、`C++-内存与调度-速查.md`（底层布局 / 性能）
> 本文只讲「接口 + 用法 + 坑」，不讲底层原理（底层看内存与调度那份）

**阅读说明**

- ★ 核心结论，⚠️ 高频坑
- 每个容器按「头文件 → 接口 → 坑 → 典型场景」组织

---

## 〇、一页总表

| 容器 | 底层 | 头文件 | 查找 | 插入 | 有序 | 典型场景 |
|---|---|---|---|---|---|---|
| `vector` | 动态数组 | `<vector>` | O(1) | 尾均摊 O(1) | 否 | **默认首选** |
| `deque` | 分段数组 | `<deque>` | O(1) | 头尾 O(1) | 否 | 两头进出（单调队列）|
| `list` | 双向链表 | `<list>` | O(n) | 任意 O(1) | 否 | 频繁中间插删（很少用）|
| `stack` | 适配器（默认 deque）| `<stack>` | — | 顶 O(1) | — | LIFO |
| `queue` | 适配器（默认 deque）| `<queue>` | — | 尾 O(1) | — | FIFO / BFS |
| `priority_queue` | 二叉堆 | `<queue>` | — | O(log n) | 堆序 | 动态最值（大顶堆）|
| `set` / `map` | 红黑树 | `<set>` `<map>` | O(log n) | O(log n) | ✅ | 需要有序 / 前驱后继 |
| `unordered_set` / `unordered_map` | 哈希表 | `<unordered_set>` `<unordered_map>` | 平均 O(1) | 平均 O(1) | ❌ | 查存在 / 值→信息 |
| `pair` / `tuple` | 打包 | `<utility>` `<tuple>` | — | — | 字典序 | 成对数据 |

★ **默认思维：能用 `vector` 就用 `vector`**（连续内存、最快）。只在需要特定操作时才换。

---

## 一、`vector` —— 动态数组（默认首选）

### 1.1 接口

```cpp
#include <vector>
vector<int> v;                       // 空
vector<int> v(n);                    // n 个 0
vector<int> v(n, x);                 // n 个 x
vector<int> v = {1,2,3};
vector<int> v(begin_it, end_it);     // ★ 区间构造（一行拷贝/去重）

v.push_back(x);      // 尾部追加
v.pop_back();        // 删尾部（★ 不返回值）
v[i];                // 随机访问（❌ 不检查越界）
v.at(i);             // 随机访问（✅ 越界抛异常，但慢）
v.front(); v.back(); // 首尾（空容器访问 = UB）
v.size(); v.empty();
v.clear();           // 清空（size=0，容量保留）
v.resize(n);         // 改大小
v.reserve(n);        // ★ 预分配容量（不改变 size）
v.assign(n, x);      // 重新赋值 n 个 x
```

### 1.2 ⚠️ 坑

| # | 坑 | 正确做法 |
|---|---|---|
| 1 | `v[i]` 越界 = UB | 确保 `i < v.size()`；调试用 `at()` |
| 2 | `pop_back()` 不返回值 | `x = v.back(); v.pop_back();` |
| 3 | 空 vector 取 `v[0]` / `front()` / `back()` = UB | 先判 `!v.empty()` |
| 4 | `v.size() - 1` 在空时回绕 | 用 `(int)v.size() - 1` 或先判空 |
| 5 | 循环里频繁 `push_back` | 已知大小就 `reserve(n)` |

### 1.3 ★ 区间构造（高频）

```cpp
unordered_set<int> st(v.begin(), v.end());     // 去重
vector<int> w(v.begin() + l, v.begin() + r);   // 拷贝 [l, r)
string s(v.begin(), v.end());
```

★ **`first, last` 永远是半开区间**（`last` 不包含）。

---

## 二、`stack` —— 后进先出

```cpp
#include <stack>
stack<int> st;
st.push(x);       // 压栈
st.pop();         // ★ 弹栈，不返回值
st.top();         // 看栈顶，不弹出
st.empty(); st.size();
```

### ⚠️ 坑

| # | 坑 | 正确做法 |
|---|---|---|
| 1 | `int x = st.pop();` | `int x = st.top(); st.pop();` |
| 2 | 空栈 `top()` / `pop()` = UB | 先 `!st.empty()` |
| 3 | 想要 `clear()` | 没有 → `while (!st.empty()) st.pop();` |
| 4 | 想遍历 | 不能 → 换 `vector` 手动当栈 |

★ **典型场景**：括号匹配（20）、辅助栈记最值（155）、单调栈（739/496）、DFS 显式栈。

---

## 三、`queue` —— 先进先出

```cpp
#include <queue>
queue<int> q;
q.push(x);        // 入队（末尾）
q.pop();          // ★ 出队（弹队首），不返回值
q.front();        // 看队首，不弹出
q.back();         // 看队尾
q.empty(); q.size();
```

### ⚠️ 坑

| # | 坑 | 正确做法 |
|---|---|---|
| 1 | `int x = q.pop();` | `int x = q.front(); q.pop();` |
| 2 | 空队列 `front()` / `pop()` = UB | 先 `!q.empty()` |
| 3 | 忘记 `pop` → 死循环 | `auto [i,j] = q.front(); q.pop();` 两行连着写 |

★ **典型场景**：BFS（994 腐烂的橘子、542 01 矩阵）、层序遍历（102）。

★ **BFS 为什么必须用队列**：先发现的先处理（FIFO）→ 天然按距离分层。

---

## 四、`pair` / `tuple` —— 打包

```cpp
#include <utility>   // pair
#include <tuple>     // tuple

pair<int, int> p = {3, 5};
p.first;      // 3
p.second;     // 5

tuple<int,int,int> t = {1,2,3};
get<0>(t);    // 1
```

### 4.1 ★ 结构化绑定（C++17）

```cpp
auto [i, j] = q.front();            // 拆 pair
auto [a, b, c] = someTuple;         // 拆 tuple
for (auto& [k, v] : mp) { ... }     // 遍历 map 时拆键值
```

★ **`auto [i,j]` 是拷贝；`auto& [i,j]` 是引用**：

```cpp
auto [i, j] = q.front();     // ✅ 拷贝（安全）
q.pop();

auto& [i, j] = q.front();    // ⚠️ 引用 → q.pop() 后悬垂！
q.pop();
```

### 4.2 ★ pair 的默认排序是「字典序」

```cpp
vector<pair<int,int>> v = {{1,3}, {1,2}, {2,1}};
sort(v.begin(), v.end());
// → {{1,2}, {1,3}, {2,1}}   先比 first，再比 second
```

⚠️ **`vector<int>` 也有默认字典序比较** → 想「只按第一个元素排」必须自己写比较器。

### 4.3 典型场景

| 场景 | 写法 |
|---|---|
| 网格 BFS 存坐标 | `queue<pair<int,int>>` |
| 存 (值, 下标) 对 | `vector<pair<int,int>>` |
| BFS 带步数 | `queue<tuple<int,int,int>>` |
| map 遍历 | `for (auto& [k,v] : mp)` |

---

## 五、`priority_queue` —— 堆（动态最值）

```cpp
#include <queue>
priority_queue<int> pq;                              // ★ 默认大顶堆
pq.push(x);       // O(log n)
pq.pop();         // 弹最大，O(log n)
pq.top();         // 看最大，O(1)

// 小顶堆
priority_queue<int, vector<int>, greater<int>> minHeap;

// pair 的大顶堆：先比 first
priority_queue<pair<int,int>> pq2;
```

### ⚠️ 坑

| # | 坑 | 正确做法 |
|---|---|---|
| 1 | 以为是小顶堆 | **默认是大顶堆**；小顶堆要 `greater<int>` |
| 2 | 想改已有元素的优先级 | 堆不支持 → 常见做法是「插入新值，出堆时判重」|
| 3 | 自定义结构体排序 | 写 `operator<` 或自定义 `cmp` |

★ **典型场景**：第 K 大（215）、前 K 高频（347）、合并 K 个有序链表（23）、任务调度。

---

## 六、`unordered_set` / `unordered_map` —— 哈希表

```cpp
#include <unordered_set>
#include <unordered_map>

unordered_set<int> st;
st.insert(x);        // 插入（重复自动忽略）
st.count(x);         // ★ 存在吗（0/1），不插入
st.erase(x);
st.size();

unordered_map<int,int> mp;
mp[k] = v;           // ★ 键不存在会自动创建
mp.count(k);         // ★ 判断存在用这个
mp.find(k);          // 迭代器
mp.erase(k);
for (auto& [k,v] : mp) { ... }
```

### ⚠️ 坑

| # | 坑 | 正确做法 |
|---|---|---|
| 1 | `mp[k]` 判断存在 | 会**自动创建 0** → 用 `count` / `find` |
| 2 | `insert` 想覆盖 | **不覆盖** → 用 `mp[k] = v` |
| 3 | 指望遍历有序 | 无序 → 要有序用 `map` |
| 4 | 数组当 key | 不能 → 先**编码**成 string |
| 5 | 一 key 多值用 `int` | 用 `map<K, vector<V>>` + `mp[key].push_back` |

### 6.1 ★ `insert` 的返回值

```cpp
auto [it, ok] = st.insert(x);
// ok == false → 本来就有
// ★ 一次完成「查 + 记」，但仅当「查的键 == 插的键」时
```

★ 详见 `第0层-基础工具/哈希表-专题笔记.md` §4。

### 6.2 典型场景

| 需求 | 用 |
|---|---|
| 查存在 | `unordered_set` |
| 值 → 位置/次数/答案 | `unordered_map` |
| 分组（一对多）| `unordered_map<K, vector<V>>` |
| 需要有序 | `set` / `map` |

---

## 七、`set` / `map` —— 有序（红黑树）

```cpp
#include <set>
#include <map>

set<int> s;
s.insert(x);              // O(log n)
s.count(x); s.erase(x);
s.lower_bound(x);         // ★ 第一个 >= x（迭代器）
s.upper_bound(x);         // 第一个 > x

*prev(s.upper_bound(x));  // ★ 最后一个 <= x（前驱）

map<int,int> mp;
mp[k] = v;                // O(log n)
for (auto& [k,v] : mp)    // ★ 按键升序遍历
```

### 与 unordered 的取舍

| | `unordered_*` | `set` / `map` |
|---|---|---|
| 查找 | 平均 O(1) | 稳定 O(log n) |
| 有序 | ❌ | ✅ |
| 怕被卡 | ⚠️ 哈希碰撞攻击 | ❌ 不怕 |
| 常数 | 小 | 大 |

★ **要「有序遍历 / 前驱后继」或「怕被 hack」→ 用 `set`/`map`；否则 `unordered_*`。**

★ **典型场景**：需要有序集合（220 存在重复元素 III）、区间查询（729 我的日程安排）。

---

## 八、`deque` —— 双端队列

```cpp
#include <deque>
deque<int> dq;
dq.push_back(x);   dq.pop_back();
dq.push_front(x);  dq.pop_front();      // ★ 头部 O(1)
dq.front(); dq.back();
dq[i];                                  // 随机访问 O(1)（比 vector 稍慢）
```

★ **典型场景**：单调队列（239 滑动窗口最大值）。

★ **为什么 239 必须用 deque**：需要「尾部踢 + 头部弹过期 + 取头部」→ 两头都要动。

---

## 九、★ 选型决策表

| 需求 | 选 |
|---|---|
| 动态数组、随机访问 | **`vector`** |
| 已知元素个数 | `vector` + `reserve(n)` |
| 只在一端进出（LIFO）| `stack` |
| 两端进出（FIFO / 滑动窗口）| `queue` / `deque` |
| 查存在 / 值→信息 | `unordered_set` / `unordered_map` |
| 一 key 多值 | `unordered_map<K, vector<V>>` |
| 需要有序 / 前驱后继 | `set` / `map` |
| 动态最值 | `priority_queue` |
| 两/三个值打包 | `pair` / `tuple` + 结构化绑定 |

★ **默认思维：先想「能不能用 vector」，再考虑别的。**

---

## 十、⚠️ 跨容器通用纪律

| # | 纪律 | 说明 |
|---|---|---|
| 1 | **取值 / 弹出前判空** | `front()` / `back()` / `top()` / `pop*()` 空容器 = UB |
| 2 | **`!empty()` 放 `&&` 左边** | 短路求值防越界 |
| 3 | **`pop*()` 都不返回值** | 先取再弹 |
| 4 | **`size()` 返回 `size_t`（无符号）** | `size()-1` 空时回绕 → 用 `(int)` |
| 5 | **区间一律半开 `[first, last)`** | 构造、`sort`、`lower_bound` 都是 |
| 6 | **遍历大对象用 `auto&` / `const auto&`** | 避免拷贝 |
| 7 | **`vector` 的 `v[i]` 不检查越界** | 越界 = UB，不报错 |

---

## 十一、一句话总结

> ★ **默认用 `vector`；需要特定操作时按决策表换。**
> ★ **`stack` / `queue` / `priority_queue` 都是适配器**（`pop()` 不返回值、不能遍历）。
> ★ **`pair` + `auto [a,b]` 是「打包 / 拆包」的标准工具**（网格 BFS 必备）。
> ★ **哈希 vs 有序树：要 O(1) 用 `unordered_*`，要有序用 `set`/`map`。**
> ★ **跨容器纪律：判空、`!empty()` 放左边、`pop` 不返回值、`size()` 是无符号。**
