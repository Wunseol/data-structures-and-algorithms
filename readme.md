# Data Structures and Algorithms

[![CI](https://github.com/YOUR_USERNAME/data-structures-and-algorithms/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/data-structures-and-algorithms/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

数据结构与算法学习项目，涵盖常用数据结构的 C/C++ 实现及经典算法的多种解法。

**[在线文档](https://your-username.github.io/data-structures-and-algorithms/)** | **[贡献指南](CONTRIBUTING.md)** | **[编码规范](CodingGuidelines.md)** | **[目录索引](DIRECTORY.md)**

## 项目结构

```
data-structures-and-algorithms/
├── docs/                              # 需求文档与设计文档
├── src/
│   ├── linear_list/                   # 线性表
│   │   ├── sequential_list/           #   顺序表
│   │   ├── singly_linked_list/        #   单链表
│   │   ├── doubly_linked_list/        #   双向链表
│   │   ├── circular_linked_list/      #   循环链表
│   │   └── skip_list/                 #   跳表
│   ├── stack/                         # 栈
│   │   ├── sequential_stack/          #   顺序栈
│   │   └── linked_stack/              #   链栈
│   ├── queue/                         # 队列
│   │   ├── circular_queue/            #   循环队列
│   │   ├── linked_queue/              #   链队列
│   │   ├── deque/                     #   双端队列
│   │   └── priority_queue/            #   优先队列
│   ├── tree/                          # 树
│   │   ├── binary_tree/               #   二叉树
│   │   ├── binary_search_tree/        #   二叉排序树
│   │   ├── avl_tree/                  #   AVL 树
│   │   ├── huffman_tree/              #   哈夫曼树
│   │   └── trie/                      #   字典树
│   ├── graph/                         # 图
│   │   ├── adjacency_matrix/          #   邻接矩阵
│   │   ├── adjacency_list/            #   邻接表
│   │   └── union_find/                #   并查集
│   ├── hash_table/                    # 哈希表
│   ├── heap/                          # 堆
│   │   ├── max_heap/                  #   最大堆
│   │   └── min_heap/                  #   最小堆
│   ├── sorting/                       # 排序算法
│   ├── searching/                     # 搜索算法
│   ├── string_algorithm/              # 字符串算法
│   ├── bit_manipulation/              # 位运算
│   ├── math/                          # 数学算法
│   └── advanced_algorithm/            # 高级算法
│       ├── dynamic_programming/       #   动态规划
│       ├── greedy/                    #   贪心算法
│       ├── backtracking/              #   回溯法
│       └── divide_and_conquer/        #   分治法
├── tests/                             # 自检测试框架与模块测试
├── python/                            # Python 辅助实现与验证
├── .clang-format                      # 代码格式化配置
├── .clang-tidy                        # 静态分析配置
├── CMakeLists.txt                     # CMake 构建配置
├── Doxyfile                           # Doxygen 文档配置
├── CONTRIBUTING.md                    # 贡献指南
├── CodingGuidelines.md                # 编码规范
├── DIRECTORY.md                       # 目录索引
├── .gitignore
└── README.md
```

## 快速开始

### 前置条件

| 工具 | 最低版本 | 推荐版本 | 说明 |
|------|---------|---------|------|
| CMake | 3.16 | 3.25+ | 构建系统 |
| GCC | 12 | 13+ | 支持 C17 / C++17 |
| Clang | 15 | 17+ | 支持 C17 / C++17 |
| MSVC | 19.3 | 19.35+ | Visual Studio 2022 |
| Python | 3.10 | 3.12+ | 辅助验证与可视化 |

**语言标准：**
- C 文件 (`.c`)：ISO/IEC 9899:2018 (C17)
- C++ 文件 (`.cpp`)：ISO/IEC 14882:2020 (C++17)
- Python 文件 (`.py`)：Python 3.10+

### 使用 CMake 构建（推荐）

```bash
cmake -B build
cmake --build build
```

构建产物位于 `build/` 目录下，每个模块生成独立的可执行文件。

### 编译单个文件

```bash
gcc -std=c17 -Wall -Wextra -o output src/path/to/file.c
g++ -std=c++17 -Wall -Wextra -o output src/path/to/file.cpp
```

### 运行自检测试

```bash
gcc tests/test_circular_queue.c src/queue/circular_queue/circular_queue.c -I tests -o test_cq
./test_cq
```

## 模块索引

### 数据结构

| 模块 | 路径 | 说明 |
|------|------|------|
| 顺序表 | `src/linear_list/sequential_list/` | 动态数组与静态数组实现 |
| 单链表 | `src/linear_list/singly_linked_list/` | 带头结点的单链表实现 |
| 双向链表 | `src/linear_list/doubly_linked_list/` | 双向链表实现 |
| 循环链表 | `src/linear_list/circular_linked_list/` | 循环单链表实现 |
| 跳表 | `src/linear_list/skip_list/` | 概率数据结构，平均 O(log n) |
| 顺序栈 | `src/stack/sequential_stack/` | 基于数组的栈实现 |
| 链栈 | `src/stack/linked_stack/` | 基于链表的栈实现 |
| 循环队列 | `src/queue/circular_queue/` | 循环队列实现 |
| 链队列 | `src/queue/linked_queue/` | 链式队列实现 |
| 双端队列 | `src/queue/deque/` | 双端队列实现 |
| 优先队列 | `src/queue/priority_queue/` | 基于最大堆的优先队列 |
| 二叉树 | `src/tree/binary_tree/` | 二叉树基本操作 |
| 二叉排序树 | `src/tree/binary_search_tree/` | BST 增删改查 |
| AVL 树 | `src/tree/avl_tree/` | 自平衡二叉搜索树 |
| 哈夫曼树 | `src/tree/huffman_tree/` | 哈夫曼编码 |
| 字典树 | `src/tree/trie/` | 字符串前缀匹配 |
| 邻接矩阵 | `src/graph/adjacency_matrix/` | 图的邻接矩阵表示 |
| 邻接表 | `src/graph/adjacency_list/` | 图的邻接表表示 |
| 并查集 | `src/graph/union_find/` | 路径压缩+按秩合并 |
| 哈希表 | `src/hash_table/` | 链地址法与开放地址法 |
| 堆 | `src/heap/` | 最大堆与最小堆 |

### 算法

| 模块 | 路径 | 说明 |
|------|------|------|
| 排序 | `src/sorting/` | 插入/冒泡/选择/快排/归并/堆排/计数/基数/桶排序 |
| 搜索 | `src/searching/` | 线性/二分/插值/斐波那契查找 |
| 字符串 | `src/string_algorithm/` | KMP/Rabin-Karp/Boyer-Moore/Manacher |
| 位运算 | `src/bit_manipulation/` | 位操作技巧与常用位运算 |
| 数学 | `src/math/` | 素数/GCD/筛法/快速幂/组合数 |
| 动态规划 | `src/advanced_algorithm/dynamic_programming/` | 背包/LCS/LIS/编辑距离等 |
| 贪心 | `src/advanced_algorithm/greedy/` | 活动选择/分数背包/区间调度 |
| 回溯 | `src/advanced_algorithm/backtracking/` | N 皇后/全排列/组合 |
| 分治 | `src/advanced_algorithm/divide_and_conquer/` | 最大子数组/最近点对 |

## 代码规范

- 目录和文件名使用全小写英文 snake_case
- C 文件使用 `malloc/free`，C++ 文件使用 `new/delete`，不混用
- 全局变量通过函数参数或结构体封装传递
- 跨平台兼容：`system("cls")` / `system("pause")` 使用条件编译封装
- 每个算法标注时间/空间复杂度
- 每个模块包含自检测试
- 详见 [CodingGuidelines.md](CodingGuidelines.md)

## 贡献

欢迎贡献！请阅读 [CONTRIBUTING.md](CONTRIBUTING.md) 了解详情。

## 许可证

MIT License
