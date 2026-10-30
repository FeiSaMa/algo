# 算法题调试脚手架：把 LeetCode 扩展生成的 <题号>.<slug>.cpp 套上一个 main，
# 用 make 就能编译，用 F5 就能在 gdb 里单步。

CXX      := g++
CXXFLAGS := -std=c++20 -g -O0 -Wall -Wextra -Ileetcode
OUT      := out

# tests/*.cpp 里以 _ 开头的是模板，不参与构建
TESTS := $(patsubst tests/%.cpp,$(OUT)/%,$(filter-out tests/_%,$(wildcard tests/*.cpp)))

.PHONY: all list clean
all: $(TESTS)

list:
	@echo 可构建的测试: $(notdir $(TESTS))

# 二次展开：让 $* 能在依赖里用，从而自动找到 leetcode/<题号>.<slug>.cpp
.SECONDEXPANSION:
$(OUT)/%: tests/%.cpp $$(firstword $$(wildcard leetcode/$$*.*.cpp)) | $(OUT)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OUT):
	mkdir -p $(OUT)

clean:
	rm -rf $(OUT)
