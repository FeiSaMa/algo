# algo

LeetCode 解法 + 本地调试脚手架。

- `leetcode/` —— VSCode LeetCode 扩展生成的文件，**文件名不要改**（扩展靠 `<题号>.<slug>.cpp` 定位题目）
- `tests/` —— 给每个解法套一个 `main`，用来本地跑和调试
- `tools/` —— `newtest`（生成骨架）、`build`（按文件名推题号构建）、`run`（构建 + 运行）

---

## 一分钟上手

```bash
# 写一道新题的本地测试
tools/newtest 739       # 从 leetcode/739.*.cpp 抠出签名，生成 tests/739.cpp
$EDITOR tests/739.cpp   # 填输入（只有几行 TODO）
tools/run 739           # 构建 + 运行

# 调试：在 tests/739.cpp 或 leetcode/739.xxx.cpp 里按 F5，都行
```

---

## 双屏工作流（本机配置）

正面外接屏（`HDMI-A-1`，144Hz）跑 VSCode；右侧笔记本屏（`eDP-1`）跑 kitty。

| 干什么 | 在哪 | 怎么起 |
| --- | --- | --- |
| `make` / `tools/*` / `./out/NN` / `git` | kitty（右侧笔记本屏） | `Mod+Shift+L` 聚焦笔记本屏 → `Mod+T` 开 kitty |
| 写代码、断点、F5 调试 | VSCode（正面屏） | `Mod+Shift+H` 聚焦正面 |
| 看题解 | 浏览器 | — |

niri 的规则是**新窗口开在焦点所在输出**，所以"先 `Mod+Shift+L` 再 `Mod+T`"就能让 kitty 落在笔记本屏。

| 键位（niri） | 作用 |
| --- | --- |
| `Mod+Shift+H` / `Mod+Shift+L` | 焦点切到 左（外接）/ 右（笔记本） |
| `Mod+Shift+Ctrl+H` / `Mod+Shift+Ctrl+L` | 把当前窗口搬到 左 / 右 |
| `Mod+T` | 开 kitty |

**分工的边界**：F5 调试用的是 `"console": "integratedTerminal"`，那个终端必须在 VSCode 里（正面屏）；kitty 只跑不涉及调试的活。

kitty 不知道 VSCode 当前目录，所以 `tools/*` 要在仓库根跑：

```bash
cd ~/dev/algo
```

---

## 为什么需要 tests/

扩展生成的 `<题号>.<slug>.cpp` 只有一个 `class Solution`，**没有 `main`**，所以 Code Runner / `g++ x.cpp` 一定失败（`undefined reference to main`）。`tests/<题号>.cpp` 的作用就是给它套一个 `main`：

```cpp
#include "1004.max-consecutive-ones-iii.cpp"   // 把解法直接 include 进来
int main() { Solution s; /* 调用、打印、断言 */ }
```

用 `#include` 而不是"编译两个源文件"：解法文件里没有声明 `Solution` 的头文件，include 最省事，而且**调试符号落在原文件上**——断点打在 `leetcode/` 的循环里照样命中，堆栈里能看到 `main() at tests/1004.cpp`。

---

## 自动生成测试骨架

```bash
tools/newtest 739        # 生成 tests/739.cpp
tools/newtest -f 739     # 覆盖已有
tools/newtest --stats    # 81 道解法里还有几道没写测试
```

自动的部分：方法名、参数类型、变量声明、调用、打印、链表/树节点定义
（能从解法文件注释里抠出 `struct ListNode` 就用它的，抠不出就 `#include "structs.h"`，
里面还带 `make_list({1,2,3})` / `make_tree({3,9,std::nullopt,15,7})` 构造辅助）。

**不能自动的部分：输入。** C++ 没有反射，每道题的输入形态和序列化方式都不同，
生成出来的 `{}` 空容器必须你自己填——这也是唯一需要想的地方。

不必给全部 81 道补测试，只给三类补：卡住调试过的、边界容易错的、想对比多种写法的。

---

## 命令速查

```bash
tools/newtest 56                                 # 生成测试骨架
tools/run 56                                     # 构建 + 运行（最常用）
tools/run                                        # 列出能跑的题
tools/build leetcode/56.merge-intervals.cpp      # 按文件名推题号构建
tools/build tests/56.cpp                         # 同上（都是 out/56）
make -j4                                         # 构建 tests/ 下全部
make list                                        # 看有哪些可构建
make out/56                                      # 只构建一道
make clean                                       # 删除 out/
./out/56                                         # 直接跑
```

`out/current` 是一个符号链接，指向**最后一次构建**的二进制，给 `launch.json` 当固定调试入口用（不要在别处依赖它）。

---

## VSCode 里怎么用

| 操作 | 快捷键 | 说明 |
| --- | --- | --- |
| 构建当前题 | `Ctrl+Shift+B` | 走 `./tools/build ${file}`，解法文件和测试文件都能用 |
| 调试当前题 | `F5` | 先构建（`out/NN`），再调试 `out/current` |
| 单步跳过 / 进入 | `F10` / `F11` | `launch.json` 里配了 gdb `skip`，`F11` 不会钻进 `/usr/include/c++` |
| 条件断点 / 日志点 | 右键红点 | 例：条件 `i == 4`；日志 `i={i}, sum={sum}` |
| 观察点 | 调试控制台 `-exec watch i` | 看循环变量每次自增 |

终端已设为 `terminal.integrated.defaultLocation: "editor"`，需要时可用 `Ctrl+Shift+P` →
`将编辑器移动到新窗口` 把终端搬到另一块屏（Wayland 下**拖拽标签不生效**，用命令面板）。

---

## cmake 备选

产物在 `build/`，目标名带 `t` 前缀：

```bash
cmake -S . -B build && cmake --build build
./build/t1004
```

`CMakeLists.txt` 用 `foreach` + `file(GLOB ... CONFIGURE_DEPENDS)` 遍历 `tests/[0-9]*.cpp`，
新增测试不用改 CMakeLists。注意解法文件是被 `#include` 进测试文件的，**不能再作为独立源文件列进 `add_executable`**，否则 duplicate symbol。

---

## 坑

1. **`leetcode/` 里的文件名不能改**，扩展靠文件名定位；测试文件按题号命名即可（`tests/56.cpp`）。
2. **F5 在哪个文件都行**，因为 `program` 固定是 `out/current`，题号由 `tools/build` 从文件名推。
   没有 `tests/NN.cpp` 时 `tools/build` 会报错并中止调试，不会静默跑上一个二进制。
3. `out/` 和 `build/` 都在 `.gitignore` 里，别提交产物。
4. `tests/structs.h` 与解法文件里**非注释版**的 `struct ListNode/TreeNode` 会冲突——真遇到就删掉 `structs.h` 里对应的那个。
5. **`cppdbg` 不支持 `justMyCode`**（那是 cppvsdbg/MSVC 的字段，写上去被忽略）。要让 `F11` 不钻进
   `basic_string.h`/`allocator.h`，得用 gdb 自己的 `skip`——`launch.json` 的 `setupCommands` 里那两条
   `-interpreter-exec console "skip -gfile /usr/include/c++/*/bits/*.h"` 就是干这个的。
6. 断点是**语句级**的：停在某行 = 该行还没执行，所以断在声明行看到的是未初始化值；想在循环"多跑一轮"时停，用观察点而不是行断点。
