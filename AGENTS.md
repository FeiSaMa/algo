# AGENTS.md — algo

LeetCode 解法 + 本地调试脚手架的仓库。给在本仓库里干活的 agent 用。

---

## 1. 仓库地图

```
leetcode/        VSCode LeetCode 扩展生成，扩展的地盘 —— 见 §2 硬约束
tests/           <题号>.cpp：给每个解法套一个 main；_template.cpp 是模板（下划线开头不进构建）
tests/structs.h  ListNode / TreeNode 定义 + make_list / make_tree 构造辅助
tools/newtest    从解法文件抠签名，生成 tests/<题号>.cpp 骨架
tools/build      按文件名推题号构建（解法文件、测试文件都行），并更新 out/current
tools/run        构建 + 运行（无参数时列出可跑的题）
Makefile         主构建（产物 out/）
CMakeLists.txt   备选构建（产物 build/，目标名 t<题号>）
.vscode/         tasks.json / launch.json / c_cpp_properties.json，已配好，别重写
```

本机环境：g++ 16.2.1（默认 `gnu++20`、`gnu23`）、make 4.4.1、cmake 4.4.5、**没有 ninja**。

---

## 2. 硬约束（改了就会坏）

1. **不要重命名或移动 `leetcode/` 里的文件。** 扩展靠 `<题号>.<slug>.cpp` 定位题目；改名 → 网页端提交失败。
   也**不要**把解法重构成 `problems/<题号>_<slug>/main.cpp` 那种结构。
2. **不要改动 `leetcode/` 文件里 `// @lc code=start` … `// @lc code=end` 之外的头部注释**，那是扩展的元数据。
   区间内的解法可以改（那是人的工作）。
3. **测试文件必须叫 `tests/<题号>.cpp`**，题号是纯数字（`tests/56.cpp`，不是 `tests/56.merge-intervals.cpp`）。
   `Makefile` 和 `tools/*` 全部靠这条约定推题号。
4. **`tests/*.cpp` 用 `#include` 引入解法文件**，因此解法**不能**再作为独立源文件列进 `CMakeLists.txt` 的
   `add_executable`（会 duplicate symbol）。
5. `tests/structs.h` 与解法文件里**非注释版**的 `struct ListNode / TreeNode` 会重定义冲突。真遇到就删掉
   `structs.h` 里对应的那个 struct，不要改解法文件。

---

## 3. 日常命令

```bash
tools/newtest 56                 # 生成 tests/56.cpp 骨架（-f 覆盖；--stats 看覆盖率）
tools/run 56                     # make out/56 && ./out/56
tools/build tests/56.cpp         # 只构建（解法文件路径也行）
make -j4                         # 构建 tests/ 下全部
make list                        # 列出可构建目标
make clean                       # 删 out/
```

`out/current` 是指向"最后构建的那个二进制"的符号链接，**仅供 `launch.json` 调试入口使用**。
不要把它当产物依赖，也不要提交（`out/` 已在 `.gitignore`）。

---

## 4. 加一道题的测试（标准流程）

```bash
tools/newtest 739
$EDITOR tests/739.cpp      # 只改 "TODO: 填输入" 那几行
tools/run 739
```

骨架里已经自动生成：方法名、参数类型、变量声明、调用、`show()` 打印、链表/树定义。

**唯一需要人想的是输入。** C++ 没有反射，每题输入形态与序列化方式都不同，不要试图"猜一个通用输入"。
树用 `make_tree({3, 9, std::nullopt, 15, 7})`（层序，`nullopt` = 空），链表用 `make_list({1, 2, 3})`。

**不要给 81 道全部补测试。** 只补三类：调试过的、边界容易错的、想对比多种写法的。`tools/newtest --stats` 可查现状。

---

## 5. 调试约定

- `F5` 在 `tests/NN.cpp` 或 `leetcode/NN.xxx.cpp` 里按都可以：`preLaunchTask` 会跑
  `tools/build ${file}`，`program` 是固定的 `out/current`。
- **不要给 `launch.json` 加 `"justMyCode": true`** —— `cppdbg` 不认识这个字段（那是 `cppvsdbg` 的），
  写了会被静默忽略。跳过 libstdc++ 的正确做法是 `setupCommands` 里已有的两条 gdb `skip -gfile`。
- 断点是**语句级**的：停在某行 = 该行还没执行。断在声明行看到的是未初始化值，别据此判断 bug。
- 想在"循环多跑一轮/条件失败那次"停下，用观察点（调试控制台 `-exec watch i`）或日志点，不要靠行断点。

---

## 6. git 约定

- 提交信息用 conventional commits，与本仓库历史一致：`feat|fix|docs|test|chore|style(scope): 中文简述`。
- 一次提交一件事。改工具 + 加测试 + 改文档分三条。
- **不要提交**：`out/`、`build/`、`compile_commands.json`、任何二进制。
- 提交前至少跑一次 `make -j4`（全绿）和 `tools/run <改动的题号>`。

---

## 7. 已知坑

| 现象 | 原因 / 处理 |
| --- | --- |
| `undefined reference to main` | 直接编译 `leetcode/NN.cpp` 必然如此（只有 class Solution，没有 main）。要走 `tests/` |
| `No rule to make target 'out/56.merge-intervals'` | 用 `tools/build`/`tools/run`，或按 `Ctrl+Shift+B`（走 `${file}` → `tools/build`） |
| `struct ListNode` 重定义 | 见 §2.5 |
| 新增测试没被 cmake 编到 | `CMakeLists.txt` 用的是 `file(GLOB ... CONFIGURE_DEPENDS)`，正常会自动重配置；若没生效，删 `build/` 重来 |
| `make` 说 up to date 但改了头文件 | 不可能：编译带 `-MMD -MP`，依赖记录在 `out/*.d` |
| F11 钻进 `basic_string.h` | `skip` 没生效 → 检查 `setupCommands` 是否被改动；改完要**重开调试会话** |

---

## 8. 不要做的事

- 不要用 Code Runner 跑 `leetcode/` 里的文件（必然链接失败）。
- 不要为了"统一结构"重构 `leetcode/`、`tests/` 的命名或目录层级。
- 不要在 `CMakeLists.txt` 里把解法文件当源文件加进去（§2.4）。
- 不要在本仓库写 Python 依赖、装包；工具脚本只用 bash / python3 标准库。
- 不要把 README 里的"双屏工作流（本机配置）"小节当成仓库通用文档——那是本机专属内容，
  仓库转 public 前应迁到 `~/feisama-base` 的文档里。
