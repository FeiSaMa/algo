# C++ 面向对象 · 对照 Python 速查

> 起点：写 LeetCode 155（最小栈）时，会 Python 的 OOP 但不知道 C++ 怎么写
> 整理时间：2026-10-01
> 适用：LeetCode 设计类题目（155 最小栈 / 208 Trie / 146 LRU / 706 哈希映射 等）

**阅读说明**

- 本文是**对照速查表**，不是 OOP 教程
- 标 ★ 处是**最关键差异**
- 假设你会 Python 的类

---

## 〇、一图总览

**Python：**

```python
class MinStack:
    def __init__(self):          # 构造函数
        self.st = []             # 成员在 __init__ 里创建
        self.min_st = []

    def push(self, val):         # 第一个参数永远是 self
        self.st.append(val)
```

**C++：**

```cpp
class MinStack {
private:                         // 访问控制（Python 没有强制私有）
    stack<int> st;               // ★ 成员在类体里【声明】
    stack<int> min_st;

public:
    MinStack() { }               // 构造函数 = __init__，通常留空

    void push(int val) {         // ★ 无 self；必须有返回类型和参数类型
        st.push(val);            // ★ 直接写成员名，不用 self.
    }
};
```

---

## 一、★ 三个最关键的差异

| Python | C++ | 说明 |
|---|---|---|
| `def __init__(self):` | **`类名() { }`** | 构造函数与类同名、无返回类型 |
| `self.xxx` | **`xxx`** | C++ 不用 self（`this->xxx` 也可以但不必要） |
| 成员在 `__init__` 里创建 | **在类体里声明** | C++ 强制提前声明成员 |
| 方法隐含 `self` 参数 | **没有 self** | 隐式传递 |
| 不写类型 | **必须写类型** | 返回类型 + 参数类型 |

---

## 二、类的结构与访问控制

```cpp
class MinStack {
private:                 // 只有类内部能访问
    stack<int> st;
    stack<int> minst;

public:                  // 外部能访问（LeetCode 只调用这些）
    MinStack() { }
    void push(int value) { ... }
    void pop() { ... }
    int top() { ... }
    int getMin() { ... }
};                       // ★ 结尾有分号！
```

★ **`class` 默认是 `private`**（`struct` 默认 `public`），所以习惯上会显式写 `private:` / `public:`。

★ **LeetCode 使用规则**：成员放 `private`、方法放 `public`。或者干脆全 `public` 也能过。

⚠️ **别忘了类结尾的分号 `};`** —— 这是 C++ 新手最常漏的。

---

## 三、构造函数

| Python | C++ |
|---|---|
| `def __init__(self):` | `MinStack() { }` |
| `def __init__(self, x):` | `MinStack(int x) { ... }` |
| 成员在这里创建 | 成员已在类体声明，这里只做额外初始化 |

★ **C++ 的 `vector`/`string`/`stack` 等会自动默认构造**，所以构造函数经常**留空**。

★ **甚至可以不写构造函数**（LeetCode 会默认构造）：

```cpp
class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    // 不写构造函数也 OK
    void push(int value) { ... }
};
```

**初始化列表写法**（C++ 特有，比在函数体里赋值更高效）：

```cpp
MinStack(int n) : st(), minst() { }        // 成员初始化列表
```

---

## 四、方法（成员函数）

| Python | C++ |
|---|---|
| `def push(self, val):` | `void push(int val) { ... }` |
| `def top(self) -> int:` | `int top() { ... }` |
| `def pop(self) -> None:` | `void pop() { ... }` |
| `def is_empty(self) -> bool:` | `bool isEmpty() { ... }` |

★ **C++ 是静态类型**：返回类型、参数类型**必须写明**。

★ **没有返回值的写 `void`**（对应 Python 的 `-> None`）。

---

## 五、成员访问

```cpp
// C++
void push(int val) {
    if (minst.empty() || val <= minst.top()) {   // 直接写 minst
        minst.push(val);
    }
    st.push(val);
}
```

★ **不用 `self.`**。虽然 `this->minst` 也合法，但没必要。

★ **命名冲突时**才需要 `this->`：

```cpp
void setValue(int value) {
    this->value = value;    // 参数和成员同名，用 this-> 区分
}
```

---

## 六、常用操作对照（Python ↔ C++）

| 操作 | Python | C++ |
|---|---|---|
| 列表末尾添加 | `lst.append(x)` | `v.push_back(x)` |
| 末尾删除 | `lst.pop()` | `v.pop_back()` |
| 取末尾 | `lst[-1]` | `v.back()` |
| 取开头 | `lst[0]` | `v.front()` |
| 是否为空 | `if not lst:` | `v.empty()` |
| 长度 | `len(lst)` | `v.size()` |
| 入栈 | `st.append(x)` | `st.push(x)` |
| 栈顶 | `st[-1]` | `st.top()` |
| 出栈 | `st.pop()` | `st.pop()` |
| 哈希取值（不存在返回默认） | `d.get(k)` | `m[k]`（会插入！） |
| 哈希是否包含 | `if k in d:` | `m.count(k)` |
| 字典遍历 | `for k, v in d.items():` | `for (auto& [k, v] : m)` |

---

## 七、LeetCode 设计类题目的一般套路

```cpp
class MyClass {
private:
    // 1. 成员变量（数据结构）
    vector<int> data;

public:
    // 2. 构造函数（通常留空）
    MyClass() { }

    // 3. 各个操作方法
    void method1(int x) { ... }
    int method2() { ... }
};
```

★ **LeetCode 会自动 `MyClass obj;` 然后调用你的方法**，所以：

- 构造函数必须能**无参调用**（或题目指定参数）
- 方法名必须和题目一致
- 返回类型必须对

---

## 八、⚠️ 常见错误

| # | 坑 | 正确 |
|---|---|---|
| 1 | 类结尾漏分号 `}` | 写 `};` |
| 2 | 写 `self.st` | 直接 `st` |
| 3 | 构造函数写返回类型 `void MinStack()` | 构造函数**无返回类型** |
| 4 | 成员在构造函数里才声明 | 成员必须在**类体里声明** |
| 5 | 忘写方法返回类型 | 必须写（`void` / `int` ...） |
| 6 | `MinStack obj();` | ⚠️ 这是**函数声明**不是对象！用 `MinStack obj;` |
| 7 | 成员默认 `private` 导致外部无法调用 | 方法放 `public:` |

★ **第 6 条最阴险**：

```cpp
MinStack obj;      // ✅ 创建对象
MinStack obj();    // ❌ 声明了一个返回 MinStack 的函数！
```

（这条在 LeetCode 里不会遇到，因为框架帮你创建对象，但本地写代码会踩。）

---

## 九、进阶：类内 `struct` / `priority_queue` 的自定义比较

后面做设计题会遇到的写法：

```cpp
class MyClass {
    struct Node {
        int val;
        Node* next;
    };

    // 自定义比较（用于 priority_queue）
    struct Cmp {
        bool operator()(const Node* a, const Node* b) const {
            return a->val > b->val;   // 小顶堆
        }
    };

    priority_queue<Node*, vector<Node*>, Cmp> pq;

public:
    ...
};
```

★ **这就是 C++ 版的"lambda / 闭包"** —— Python 里 `heapq` 要写元组或包装，C++ 用 `operator()`。

---

## 十、一句话总结

> ★ **C++ 的 OOP 和 Python 唯一本质区别是三点：**
>
> 1. **成员要在类体里声明**（不是 `__init__` 里创建）
> 2. **没有 `self`**（直接写成员名）
> 3. **必须写类型**（返回类型 + 参数类型）
>
> **其余都是语法差异：`__init__` → 构造函数（同名、无返回类型）、`}` 结尾要加 `;`。**
>
> **LeetCode 设计类题目模板：`private` 成员 + `public` 构造函数 + `public` 方法。**
