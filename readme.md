<div align="center">

# Data Structures and Algorithms

**数据结构与算法学习项目**

涵盖常用数据结构的 C/C++ 与 Python 双语实现及经典算法的多种解法

[![Language](https://img.shields.io/badge/Language-C17%20%7C%20C%2B%2B17%20%7C%20Python%203.10-blue)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey)]()

[快速开始](#快速开始) • [项目结构](#项目结构) • [文档](#项目文档) • [模块索引](#模块索引)

</div>

---

## 特性

- **双语实现** — C/C++ 与 Python 对照学习，理解底层细节与高层抽象
- **完整文档** — 13 份学习文档 + 7 份工程文档，从入门到精通
- **现代标准** — C17 / C++17 / Python 3.10+，紧跟语言演进
- **跨平台构建** — CMake 统一构建，支持 GCC / Clang / MSVC
- **自检测试** — 每个模块配备测试用例，确保代码正确性
- **学习路径** — 九阶段循序渐进，数据结构与算法交错推进

## 项目结构

```
data-structures-and-algorithms/
├── src/                               # C/C++ 源码
│   ├── linear_list/                   #   线性表（顺序表/单链表/双向链表/循环链表/跳表）
│   ├── stack/                         #   栈（顺序栈/链栈）
│   ├── queue/                         #   队列（循环队列/链队列/双端队列/优先队列）
│   ├── tree/                          #   树（二叉树/BST/AVL/哈夫曼/Trie/线段树/树状数组）
│   ├── graph/                         #   图（邻接矩阵/邻接表/并查集/拓扑排序/最短路径/MST）
│   ├── hash_table/                    #   哈希表（链地址法/开放地址法/布隆过滤器）
│   ├── cache/                         #   缓存（LRU）
│   ├── heap/                          #   堆（最大堆/最小堆）
│   ├── sorting/                       #   排序算法（9种）
│   ├── searching/                     #   搜索算法（4种）
│   ├── string_algorithm/              #   字符串算法（8种）
│   ├── bit_manipulation/              #   位运算
│   ├── math/                          #   数学算法
│   └── advanced_algorithm/             #   高级算法（DP/贪心/回溯/分治）
├── python/algorithms/                  # Python 实现
│   ├── data_structures/               #   23 种数据结构
│   ├── sorting/                       #   10 种排序算法
│   ├── searching/                     #   4 种搜索算法
│   ├── string_algorithm/              #   8 种字符串算法
│   ├── dynamic_programming/           #   11 个 DP 问题
│   ├── graph/                         #   6 种图算法
│   ├── greedy/                        #   3 种贪心算法
│   ├── backtracking/                  #   4 种回溯算法
│   ├── divide_and_conquer/            #   2 种分治算法
│   ├── math_algorithm/                #   数学算法
│   └── bit_manipulation/              #   位运算
├── tests/                             # 测试框架
├── docs/                              # 文档
│   ├── learning/                      #   学习文档（13份）
│   └── engineering/                   #   工程文档（7份）
├── CMakeLists.txt                     # CMake 配置
└── LICENSE                            # MIT 许可证
```

## 快速开始

### 环境要求

| 工具 | 最低版本 | 推荐版本 |
|------|---------|---------|
| CMake | 3.16 | 3.25+ |
| GCC | 12 | 13+ |
| Clang | 15 | 17+ |
| MSVC | 19.3 | 19.35+ |
| Python | 3.10 | 3.12+ |

### 构建 C/C++

```bash
cmake -B build
cmake --build build
```

### 运行 Python 测试

```bash
cd python
python -m algorithms.run_all
```

更多细节请参阅 [快速开始](docs/learning/00-快速开始.md) 文档。

## 项目文档

### 学习文档

| 文档 | 说明 |
|------|------|
| [快速开始](docs/learning/00-快速开始.md) | 项目快速上手指南 |
| [学习路径与参考资料](docs/learning/01-学习路径与参考资料.md) | 九阶段学习路线与权威参考 |
| [数据结构详解](docs/learning/02-数据结构详解.md) | 每个数据结构的实现与 STL 对比 |
| [算法详解](docs/learning/03-算法详解.md) | 每个算法的原理、论文引用与 STL 对比 |
| [线性表模块](docs/learning/04-线性表模块.md) | 线性表模块需求文档 |
| [栈与队列模块](docs/learning/05-栈与队列模块.md) | 栈与队列模块需求文档 |
| [树模块](docs/learning/06-树模块.md) | 树模块需求文档 |
| [图模块](docs/learning/07-图模块.md) | 图模块需求文档 |
| [哈希表模块](docs/learning/08-哈希表模块.md) | 哈希表模块需求文档 |
| [排序算法模块](docs/learning/09-排序算法模块.md) | 排序算法模块需求文档 |
| [搜索算法模块](docs/learning/10-搜索算法模块.md) | 搜索算法模块需求文档 |
| [字符串算法模块](docs/learning/11-字符串算法模块.md) | 字符串算法模块需求文档 |
| [高级算法模块](docs/learning/12-高级算法模块.md) | 高级算法模块需求文档 |

### 工程文档

| 文档 | 说明 |
|------|------|
| [项目总览](docs/engineering/01-项目总览.md) | 项目架构、技术栈、构建与运行 |
| [技术栈与工具链指南](docs/engineering/02-技术栈与工具链指南.md) | CMake/GCC/Clang/Doxygen 详解 |
| [代码导读与开发指南](docs/engineering/03-代码导读与开发指南.md) | 开发环境搭建与工具链配置 |
| [项目演进报告](docs/engineering/04-项目演进报告.md) | 版本历史与未来规划 |
| [项目结构优化](docs/engineering/05-项目结构优化.md) | 项目结构优化需求文档 |
| [代码质量优化](docs/engineering/06-代码质量优化.md) | 代码质量优化需求文档 |
| [软件工程图集](docs/engineering/07-软件工程图集.md) | Mermaid 软件工程图索引 |

## 模块索引

### 数据结构（25 种）

| 类别 | 模块 |
|------|------|
| 线性表 | 顺序表、单链表、双向链表、循环链表、跳表 |
| 栈与队列 | 顺序栈、链栈、循环队列、链队列、双端队列、优先队列 |
| 树结构 | 二叉树、二叉搜索树、AVL 树、哈夫曼树、字典树、线段树、树状数组 |
| 图结构 | 邻接矩阵、邻接表、并查集 |
| 哈希与缓存 | 哈希表（链地址法/开放地址法）、布隆过滤器、LRU 缓存 |
| 堆 | 最大堆、最小堆 |

### 算法（50+ 种）

| 类别 | 算法 |
|------|------|
| 排序 | 插入排序、冒泡排序、选择排序、快速排序、归并排序、堆排序、计数排序、基数排序、桶排序 |
| 搜索 | 线性搜索、二分搜索、插值搜索、斐波那契搜索 |
| 字符串 | KMP、Rabin-Karp、Boyer-Moore、Manacher、Z 算法、滚动哈希、LCS |
| 图算法 | 拓扑排序、Dijkstra、Bellman-Ford、Floyd-Warshall、Kruskal、Prim |
| 动态规划 | 斐波那契、爬楼梯、零钱兑换、编辑距离、打家劫舍、0-1 背包、完全背包、LIS、最大子数组、矩阵连乘、LCS |
| 贪心 | 活动选择、分数背包、区间调度 |
| 回溯 | N 皇后、全排列、组合、子集和 |
| 分治 | 最大子数组、最近点对 |
| 位运算 | 位操作技巧 |
| 数学 | 素数判定、数论、筛法 |

## 代码规范

- 目录和文件名使用 snake_case
- C 文件使用 `malloc/free`，C++ 文件使用 `new/delete`
- 每个算法标注时间/空间复杂度
- 每个模块配备自检测试

详见 [CodingGuidelines.md](CodingGuidelines.md)。

## 贡献

欢迎贡献代码、报告问题或提出建议！请阅读 [CONTRIBUTING.md](CONTRIBUTING.md) 了解详情。

## 致谢

本项目在编写过程中参考了以下权威资料和开源项目：

### 教材与标准

- **《算法导论》**（Introduction to Algorithms, CLRS）— 算法设计与分析的理论基础
- **《数据结构（C语言版）》严蔚敏** — 经典数据结构教材
- **ISO/IEC 9899:2018 (C17)** — C 语言国际标准
- **ISO/IEC 14882:2020 (C++17)** — C++ 语言国际标准
- **cppreference.com** — C/C++ 在线参考文档

### 算法论文

- Knuth, D. E., *The Art of Computer Programming* — 排序与搜索算法权威参考
- Dijkstra, E. W., "A Note on Two Problems in Connexion with Graphs", 1959 — Dijkstra 算法原始论文
- Knuth, D. E., Morris, J. H., Pratt, V. R., "Fast Pattern Matching in Strings", 1977 — KMP 算法原始论文
- Boyer, R. S., Moore, J. S., "A Fast String Searching Algorithm", 1977 — Boyer-Moore 算法原始论文

### 开源项目

- [Python](https://www.python.org/) — Python 官方实现
- [GCC](https://gcc.gnu.org/) — GNU 编译器集合
- [LLVM/Clang](https://llvm.org/) — LLVM 编译器基础设施
- [CMake](https://cmake.org/) — 跨平台构建系统

感谢所有为计算机科学教育和开源社区做出贡献的人们！

## 许可证

本项目采用 [MIT License](LICENSE) 开源许可。
