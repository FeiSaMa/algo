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

调试：打开 `tests/1004.cpp`，按 `F5` → 自动 `make out/1004` 再挂 gdb。

## 命令

```bash
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
