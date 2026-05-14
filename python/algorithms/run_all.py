"""一键运行所有 Python 算法模块的测试

用法:
  python -m algorithms.run_all          # 导入测试（默认）
  python -m algorithms.run_all --verify # 运行 unittest 验证
  python python/algorithms/run_all.py --verify
"""

import importlib
import sys
import time
import unittest
from pathlib import Path

MODULES = [
    "algorithms.data_structures.L01_sequential_list",
    "algorithms.sorting.L02_bubble_sort",
    "algorithms.sorting.L02_selection_sort",
    "algorithms.sorting.L02_insertion_sort",
    "algorithms.sorting.L02_shell_sort",
    "algorithms.sorting.L02_quick_sort",
    "algorithms.sorting.L02_merge_sort",
    "algorithms.sorting.L02_heap_sort",
    "algorithms.sorting.L02_counting_sort",
    "algorithms.sorting.L02_radix_sort",
    "algorithms.sorting.L02_bucket_sort",
    "algorithms.searching.L03_linear_search",
    "algorithms.searching.L03_binary_search",
    "algorithms.searching.L03_interpolation_search",
    "algorithms.searching.L03_fibonacci_search",
    "algorithms.data_structures.L04_singly_linked_list",
    "algorithms.data_structures.L05_doubly_linked_list",
    "algorithms.data_structures.L06_circular_linked_list",
    "algorithms.data_structures.L07_stack",
    "algorithms.data_structures.L08_queue",
    "algorithms.data_structures.L09_skip_list",
    "algorithms.data_structures.L10_binary_tree",
    "algorithms.data_structures.L11_binary_search_tree",
    "algorithms.data_structures.L12_avl_tree",
    "algorithms.data_structures.L14_trie",
    "algorithms.data_structures.L15_max_heap",
    "algorithms.data_structures.L15_min_heap",
    "algorithms.data_structures.L16_segment_tree",
    "algorithms.data_structures.L17_fenwick_tree",
    "algorithms.data_structures.L18_hash_table_chaining",
    "algorithms.data_structures.L18_hash_table_open_addressing",
    "algorithms.data_structures.L19_bloom_filter",
    "algorithms.data_structures.L20_lru_cache",
    "algorithms.data_structures.L21_adjacency_matrix",
    "algorithms.data_structures.L22_adjacency_list",
    "algorithms.data_structures.L23_union_find",
    "algorithms.graph.L24_topological_sort",
    "algorithms.graph.L25_dijkstra",
    "algorithms.graph.L26_bellman_ford",
    "algorithms.graph.L27_floyd_warshall",
    "algorithms.graph.L28_kruskal",
    "algorithms.graph.L29_prim",
    "algorithms.string_algorithm.L30_brute_force",
    "algorithms.string_algorithm.L30_kmp",
    "algorithms.string_algorithm.L30_rabin_karp",
    "algorithms.string_algorithm.L30_boyer_moore",
    "algorithms.string_algorithm.L30_manacher",
    "algorithms.string_algorithm.L30_lcs",
    "algorithms.string_algorithm.L30_rolling_hash",
    "algorithms.string_algorithm.L30_z_algorithm",
    "algorithms.dynamic_programming.L31_fibonacci",
    "algorithms.dynamic_programming.L31_climbing_stairs",
    "algorithms.dynamic_programming.L31_coin_change",
    "algorithms.dynamic_programming.L31_edit_distance",
    "algorithms.dynamic_programming.L31_house_robber",
    "algorithms.dynamic_programming.L31_knapsack_01",
    "algorithms.dynamic_programming.L31_knapsack_complete",
    "algorithms.dynamic_programming.L31_lis",
    "algorithms.dynamic_programming.L31_max_subarray",
    "algorithms.dynamic_programming.L31_lcs_dp",
    "algorithms.dynamic_programming.L31_matrix_chain",
    "algorithms.greedy.L32_activity_selection",
    "algorithms.greedy.L32_fractional_knapsack",
    "algorithms.greedy.L32_interval_scheduling",
    "algorithms.divide_and_conquer.L33_closest_pair",
    "algorithms.divide_and_conquer.L33_max_subarray_dc",
    "algorithms.backtracking.L34_n_queens",
    "algorithms.backtracking.L34_permutations",
    "algorithms.backtracking.L34_combinations",
    "algorithms.backtracking.L34_subset_sum",
    "algorithms.bit_manipulation.L35_bit_tricks",
    "algorithms.math_algorithm.L36_prime",
    "algorithms.math_algorithm.L36_number_theory",
    "algorithms.math_algorithm.L36_sieve",
]


def run_import_test() -> None:
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


def run_verify() -> None:
    python_dir = Path(__file__).resolve().parent.parent
    if str(python_dir) not in sys.path:
        sys.path.insert(0, str(python_dir))

    tests_dir = str(Path(__file__).resolve().parent.parent / "tests")
    loader = unittest.TestLoader()
    suite = loader.discover(tests_dir, pattern="test_*.py")

    print(f"{'='*60}")
    print(f"  Python unittest 验证测试")
    print(f"{'='*60}\n")

    runner = unittest.TextTestRunner(verbosity=2)
    result = runner.run(suite)

    print(f"\n{'='*60}")
    print(f"  结果: {result.testsRun - len(result.failures) - len(result.errors)} 通过, "
          f"{len(result.failures)} 失败, {len(result.errors)} 错误 / 共 {result.testsRun} 个测试")
    print(f"{'='*60}")

    if not result.wasSuccessful():
        sys.exit(1)


def run_all() -> None:
    if "--verify" in sys.argv:
        run_verify()
    else:
        run_import_test()


if __name__ == "__main__":
    run_all()
