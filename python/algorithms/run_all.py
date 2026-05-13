"""一键运行所有 Python 算法模块的测试

用法: python -m algorithms.run_all
  或: python python/algorithms/run_all.py
"""

import importlib
import sys
import time
from pathlib import Path

MODULES = [
    "algorithms.sorting.bubble_sort",
    "algorithms.sorting.insertion_sort",
    "algorithms.sorting.selection_sort",
    "algorithms.sorting.shell_sort",
    "algorithms.sorting.quick_sort",
    "algorithms.sorting.merge_sort",
    "algorithms.sorting.heap_sort",
    "algorithms.sorting.counting_sort",
    "algorithms.sorting.radix_sort",
    "algorithms.sorting.bucket_sort",
    "algorithms.searching.linear_search",
    "algorithms.searching.binary_search",
    "algorithms.searching.interpolation_search",
    "algorithms.searching.fibonacci_search",
    "algorithms.string_algorithm.brute_force",
    "algorithms.string_algorithm.kmp",
    "algorithms.string_algorithm.rabin_karp",
    "algorithms.string_algorithm.boyer_moore",
    "algorithms.string_algorithm.manacher",
    "algorithms.string_algorithm.lcs",
    "algorithms.dynamic_programming.fibonacci",
    "algorithms.dynamic_programming.climbing_stairs",
    "algorithms.dynamic_programming.coin_change",
    "algorithms.dynamic_programming.edit_distance",
    "algorithms.dynamic_programming.house_robber",
    "algorithms.dynamic_programming.knapsack_01",
    "algorithms.dynamic_programming.knapsack_complete",
    "algorithms.dynamic_programming.lis",
    "algorithms.dynamic_programming.max_subarray",
    "algorithms.greedy.activity_selection",
    "algorithms.greedy.fractional_knapsack",
    "algorithms.greedy.interval_scheduling",
    "algorithms.backtracking.n_queens",
    "algorithms.backtracking.permutations",
    "algorithms.backtracking.combinations",
    "algorithms.backtracking.subset_sum",
    "algorithms.divide_and_conquer.closest_pair",
    "algorithms.divide_and_conquer.max_subarray_dc",
    "algorithms.data_structures.sequential_list",
    "algorithms.data_structures.singly_linked_list",
    "algorithms.data_structures.doubly_linked_list",
    "algorithms.data_structures.circular_linked_list",
    "algorithms.data_structures.skip_list",
    "algorithms.data_structures.stack",
    "algorithms.data_structures.queue",
    "algorithms.data_structures.binary_tree",
    "algorithms.data_structures.binary_search_tree",
    "algorithms.data_structures.avl_tree",
    "algorithms.data_structures.trie",
    "algorithms.data_structures.adjacency_matrix",
    "algorithms.data_structures.adjacency_list",
    "algorithms.data_structures.union_find",
    "algorithms.data_structures.hash_table_chaining",
    "algorithms.data_structures.hash_table_open_addressing",
    "algorithms.data_structures.max_heap",
    "algorithms.data_structures.min_heap",
    "algorithms.bit_manipulation.bit_tricks",
]


def run_all() -> None:
    python_dir = Path(__file__).resolve().parent.parent
    if str(python_dir) not in sys.path:
        sys.path.insert(0, str(python_dir))

    passed = 0
    failed = 0
    errors: list[str] = []

    print(f"{'='*60}")
    print(f"  Python 算法模块测试  |  共 {len(MODULES)} 个模块")
    print(f"{'='*60}\n")

    for module_name in MODULES:
        short_name = module_name.replace("algorithms.", "")
        try:
            start = time.perf_counter()
            importlib.import_module(module_name)
            elapsed = time.perf_counter() - start
            print(f"  ✓ {short_name:<45} ({elapsed*1000:.1f}ms)")
            passed += 1
        except Exception as e:
            print(f"  ✗ {short_name:<45} ERROR: {e}")
            failed += 1
            errors.append(f"{short_name}: {e}")

    print(f"\n{'='*60}")
    print(f"  结果: {passed} 通过, {failed} 失败 / 共 {len(MODULES)} 个模块")
    print(f"{'='*60}")

    if errors:
        print("\n失败详情:")
        for err in errors:
            print(f"  - {err}")
        sys.exit(1)


if __name__ == "__main__":
    run_all()
