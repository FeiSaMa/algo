# algo

LeetCode 解法（`leetcode/`，由 VSCode LeetCode 扩展生成，**文件名不要改**）+ 调试脚手架（`tests/`、`Makefile`、`CMakeLists.txt`）。

## 为什么需要 tests/

扩展生成的 `<题号>.<slug>.cpp` 只有一个 `class Solution`，**没有 `main`**，所以 Code Runner / `g++ x.cpp` 一定失败（`undefined reference to main`）。`tests/<题号>.cpp` 的作用就是给它套一个 `main`：

```cpp
#include "1004.max-consecutive-ones-iii.cpp"   // 把解法直接 include 进来
int main() { Solution s; /* 调用、打印、断言 */ }
```

这样断点可以直接打在 `leetcode/` 的解法文件里，堆栈里也能看到 `main() at tests/1004.cpp`。

## 加一道题

```bash
cp tests/_template.cpp tests/1004.cpp     # 1. 复制模板，文件名 = 题号
$EDITOR tests/1004.cpp                    # 2. 改 include 的文件名 + main 里的调用
make out/1004 && ./out/1004               # 3. 构建并跑
```

调试：**在 `tests/1004.cpp` 或 `leetcode/1004.max-xxx.cpp` 里按 `F5` 都行**
（题号由 `tools/build` 从文件名推出，`${file}` → `out/1004` → `out/current`）。

## 自动生成测试骨架

```bash
tools/newtest 739        # 从 leetcode/739.*.cpp 抠出方法签名，生成 tests/739.cpp
tools/newtest -f 739     # 覆盖已有
tools/newtest --stats    # 81 道解法里还有几道没写测试
```

自动的部分：方法名、参数类型、变量声明、调用、打印、链表/树节点定义
（能从解法文件注释里抠出 `struct ListNode` 就用它的，抠不出就 include `tests/structs.h`，
里面还带 `make_list({1,2,3})` / `make_tree({3,9,std::nullopt,15,7})` 构造辅助）。

**不能自动的部分：输入。** C++ 没有反射，每道题的输入形态和序列化方式都不同，
所以生成出来的 `{}` 空容器必须你自己填。

## 命令

```bash
./tools/run 56                                  # 构建 + 运行（最常用）
./tools/run                                     # 列出能跑的题
./tools/build leetcode/56.merge-intervals.cpp   # 从任一文件构建对应题
./tools/build tests/56.cpp                      # 同上（题号都是 56）
make                # 构建 tests/ 下所有测试
make list           # 看有哪些可构建
make out/1004       # 只构建一道
make clean
./out/1004
```

cmake 备选（产物在 `build/`，目标名带 `t` 前缀）：

```bash
cmake -S . -B build && cmake --build build
./build/t1004
```
