$base = "d:\Dev\DevWorkSpace\VS Code\data-structures-and-algorithms\src"

# 01: sequential_list
$dir = "$base\linear_list\sequential_list"
Rename-Item "$dir\sequential_list_v1.cpp" "01_sequential_list_v1.cpp"
Rename-Item "$dir\sequential_list_v2.c" "01_sequential_list_v2.c"
Rename-Item "$dir\sequential_list_v3.cpp" "01_sequential_list_v3.cpp"
Rename-Item "$dir\sequential_list_demo.cpp" "01_sequential_list_demo.cpp"
Rename-Item "$dir\sequential_list_dahua_v1.c" "01_sequential_list_dahua_v1.c"
Rename-Item "$dir\sequential_list_dahua_v2.c" "01_sequential_list_dahua_v2.c"
Rename-Item "$dir\sequential_list_dahua_v3.c" "01_sequential_list_dahua_v3.c"
Rename-Item "$dir\sequential_list_dahua_v4.c" "01_sequential_list_dahua_v4.c"
Rename-Item "$dir\static_sequential_list.cpp" "01_static_sequential_list.cpp"
Rename-Item "$dir\static_sequential_list_v2.cpp" "01_static_sequential_list_v2.cpp"
Rename-Item "$dir\static_sequential_list_v3.cpp" "01_static_sequential_list_v3.cpp"
Rename-Item "$dir\static_sequential_list_v4.cpp" "01_static_sequential_list_v4.cpp"
Rename-Item "$dir\static_sequential_list_v5.cpp" "01_static_sequential_list_v5.cpp"
Rename-Item "$dir\setup_list.cpp" "01_setup_list.cpp"
Rename-Item "$dir\setup_list_v2.c" "01_setup_list_v2.c"
Rename-Item "$dir\basic_sequential_list.cpp" "01_basic_sequential_list.cpp"
Rename-Item "$dir\menu_demo.cpp" "01_menu_demo.cpp"
Write-Host "01 sequential_list done"

# 02: sorting
$dir = "$base\sorting"
Rename-Item "$dir\sequential_list_sorting.cpp" "02_sequential_list_sorting.cpp"
Rename-Item "$dir\bucket_sort.cpp" "02_bucket_sort.cpp"
Rename-Item "$dir\counting_sort.cpp" "02_counting_sort.cpp"
Rename-Item "$dir\radix_sort.cpp" "02_radix_sort.cpp"
Write-Host "02 sorting done"

# 03: searching
$dir = "$base\searching"
Rename-Item "$dir\search_main.cpp" "03_search_main.cpp"
Rename-Item "$dir\search_common.h" "03_search_common.h"
Rename-Item "$dir\linear_search.cpp" "03_linear_search.cpp"
Rename-Item "$dir\interpolation_search.cpp" "03_interpolation_search.cpp"
Rename-Item "$dir\fibonacci_search.cpp" "03_fibonacci_search.cpp"
Rename-Item "$dir\binary_search.cpp" "03_binary_search.cpp"
Write-Host "03 searching done"

# 04: singly_linked_list
$dir = "$base\linear_list\singly_linked_list"
Rename-Item "$dir\singly_linked_list_v1.c" "04_singly_linked_list_v1.c"
Rename-Item "$dir\singly_linked_list_v2.c" "04_singly_linked_list_v2.c"
Rename-Item "$dir\singly_linked_list_v3.cpp" "04_singly_linked_list_v3.cpp"
Rename-Item "$dir\singly_linked_list_v4.c" "04_singly_linked_list_v4.c"
Write-Host "04 singly_linked_list done"

# 05: doubly_linked_list
$dir = "$base\linear_list\doubly_linked_list"
Rename-Item "$dir\doubly_linked_list_main.c" "05_doubly_linked_list_main.c"
Rename-Item "$dir\doubly_linked_list.h" "05_doubly_linked_list.h"
Rename-Item "$dir\doubly_linked_list.c" "05_doubly_linked_list.c"
Write-Host "05 doubly_linked_list done"

# 06: circular_linked_list
$dir = "$base\linear_list\circular_linked_list"
Rename-Item "$dir\circular_linked_list_main.c" "06_circular_linked_list_main.c"
Rename-Item "$dir\circular_linked_list.h" "06_circular_linked_list.h"
Rename-Item "$dir\circular_linked_list.c" "06_circular_linked_list.c"
Write-Host "06 circular_linked_list done"

# 07: stack
$dir = "$base\stack\sequential_stack"
Rename-Item "$dir\sequential_stack_v1.cpp" "07_sequential_stack_v1.cpp"
Rename-Item "$dir\sequential_stack_v2.cpp" "07_sequential_stack_v2.cpp"
Rename-Item "$dir\sequential_stack_v3.cpp" "07_sequential_stack_v3.cpp"
$dir = "$base\stack\linked_stack"
Rename-Item "$dir\linked_stack_v1.cpp" "07_linked_stack_v1.cpp"
Write-Host "07 stack done"

# 08: queue
$dir = "$base\queue\priority_queue"
Rename-Item "$dir\priority_queue_main.c" "08_priority_queue_main.c"
Rename-Item "$dir\priority_queue.h" "08_priority_queue.h"
Rename-Item "$dir\priority_queue.c" "08_priority_queue.c"
$dir = "$base\queue\linked_queue"
Rename-Item "$dir\linked_queue_main.c" "08_linked_queue_main.c"
Rename-Item "$dir\linked_queue.h" "08_linked_queue.h"
Rename-Item "$dir\linked_queue.c" "08_linked_queue.c"
$dir = "$base\queue\deque"
Rename-Item "$dir\deque_main.cpp" "08_deque_main.cpp"
Rename-Item "$dir\deque.h" "08_deque.h"
Rename-Item "$dir\deque.cpp" "08_deque.cpp"
$dir = "$base\queue\circular_queue"
Rename-Item "$dir\circular_queue_main.c" "08_circular_queue_main.c"
Rename-Item "$dir\circular_queue.h" "08_circular_queue.h"
Rename-Item "$dir\circular_queue.c" "08_circular_queue.c"
Write-Host "08 queue done"

# 09: skip_list
$dir = "$base\linear_list\skip_list"
Rename-Item "$dir\skip_list_main.cpp" "09_skip_list_main.cpp"
Rename-Item "$dir\skip_list.h" "09_skip_list.h"
Rename-Item "$dir\skip_list.cpp" "09_skip_list.cpp"
Write-Host "09 skip_list done"

# 10: binary_tree
$dir = "$base\tree\binary_tree"
Rename-Item "$dir\swap_subtree.cpp" "10_swap_subtree.cpp"
Rename-Item "$dir\count_leaves.cpp" "10_count_leaves.cpp"
Rename-Item "$dir\bint_v2.h" "10_bint_v2.h"
Rename-Item "$dir\bint.h" "10_bint.h"
Rename-Item "$dir\binary_tree_v6.cpp" "10_binary_tree_v6.cpp"
Rename-Item "$dir\binary_tree_v5.cpp" "10_binary_tree_v5.cpp"
Rename-Item "$dir\binary_tree_v4.cpp" "10_binary_tree_v4.cpp"
Rename-Item "$dir\binary_tree_v3.cpp" "10_binary_tree_v3.cpp"
Rename-Item "$dir\binary_tree_v2.c" "10_binary_tree_v2.c"
Rename-Item "$dir\binary_tree_v1.cpp" "10_binary_tree_v1.cpp"
Rename-Item "$dir\binary_tree_test_v2.cpp" "10_binary_tree_test_v2.cpp"
Rename-Item "$dir\binary_tree_test.cpp" "10_binary_tree_test.cpp"
Write-Host "10 binary_tree done"

# 11: binary_search_tree
$dir = "$base\tree\binary_search_tree"
Rename-Item "$dir\bst_crud.cpp" "11_bst_crud.cpp"
Write-Host "11 binary_search_tree done"

# 12: avl_tree
$dir = "$base\tree\avl_tree"
Rename-Item "$dir\avl_tree_main.cpp" "12_avl_tree_main.cpp"
Rename-Item "$dir\avl_tree.h" "12_avl_tree.h"
Rename-Item "$dir\avl_tree.cpp" "12_avl_tree.cpp"
Write-Host "12 avl_tree done"

# 13: huffman_tree
$dir = "$base\tree\huffman_tree"
Rename-Item "$dir\huffman_tree_main.cpp" "13_huffman_tree_main.cpp"
Rename-Item "$dir\huffman_tree.h" "13_huffman_tree.h"
Rename-Item "$dir\huffman_tree.cpp" "13_huffman_tree.cpp"
Write-Host "13 huffman_tree done"

# 14: trie
$dir = "$base\tree\trie"
Rename-Item "$dir\trie_main.cpp" "14_trie_main.cpp"
Rename-Item "$dir\trie.h" "14_trie.h"
Rename-Item "$dir\trie.cpp" "14_trie.cpp"
Write-Host "14 trie done"

# 15: heap
$dir = "$base\heap\min_heap"
Rename-Item "$dir\min_heap_main.c" "15_min_heap_main.c"
Rename-Item "$dir\min_heap.h" "15_min_heap.h"
Rename-Item "$dir\min_heap.c" "15_min_heap.c"
$dir = "$base\heap\max_heap"
Rename-Item "$dir\max_heap_main.c" "15_max_heap_main.c"
Rename-Item "$dir\max_heap.h" "15_max_heap.h"
Rename-Item "$dir\max_heap.c" "15_max_heap.c"
Write-Host "15 heap done"

# 16: segment_tree
$dir = "$base\tree\segment_tree"
Rename-Item "$dir\segment_tree_main.cpp" "16_segment_tree_main.cpp"
Rename-Item "$dir\segment_tree.cpp" "16_segment_tree.cpp"
Rename-Item "$dir\segment_tree.h" "16_segment_tree.h"
Write-Host "16 segment_tree done"

# 17: fenwick_tree
$dir = "$base\tree\fenwick_tree"
Rename-Item "$dir\fenwick_tree_main.cpp" "17_fenwick_tree_main.cpp"
Rename-Item "$dir\fenwick_tree.h" "17_fenwick_tree.h"
Rename-Item "$dir\fenwick_tree.cpp" "17_fenwick_tree.cpp"
Write-Host "17 fenwick_tree done"

# 18: hash_table
$dir = "$base\hash_table"
Rename-Item "$dir\hash_table_open_addressing.h" "18_hash_table_open_addressing.h"
Rename-Item "$dir\hash_table_open_addressing.c" "18_hash_table_open_addressing.c"
Rename-Item "$dir\hash_table_main.c" "18_hash_table_main.c"
Rename-Item "$dir\hash_table_chaining.h" "18_hash_table_chaining.h"
Rename-Item "$dir\hash_table_chaining.c" "18_hash_table_chaining.c"
Write-Host "18 hash_table done"

# 19: bloom_filter
$dir = "$base\hash_table\bloom_filter"
Rename-Item "$dir\bloom_filter_main.cpp" "19_bloom_filter_main.cpp"
Rename-Item "$dir\bloom_filter.cpp" "19_bloom_filter.cpp"
Rename-Item "$dir\bloom_filter.h" "19_bloom_filter.h"
Write-Host "19 bloom_filter done"

# 20: lru_cache
$dir = "$base\cache\lru_cache"
Rename-Item "$dir\lru_cache_main.cpp" "20_lru_cache_main.cpp"
Rename-Item "$dir\lru_cache.cpp" "20_lru_cache.cpp"
Rename-Item "$dir\lru_cache.h" "20_lru_cache.h"
Write-Host "20 lru_cache done"

# 21: adjacency_matrix
$dir = "$base\graph\adjacency_matrix"
Rename-Item "$dir\adjacency_matrix_main.c" "21_adjacency_matrix_main.c"
Rename-Item "$dir\adjacency_matrix.h" "21_adjacency_matrix.h"
Rename-Item "$dir\adjacency_matrix.c" "21_adjacency_matrix.c"
Write-Host "21 adjacency_matrix done"

# 22: adjacency_list
$dir = "$base\graph\adjacency_list"
Rename-Item "$dir\adjacency_list_main.c" "22_adjacency_list_main.c"
Rename-Item "$dir\adjacency_list.h" "22_adjacency_list.h"
Rename-Item "$dir\adjacency_list.c" "22_adjacency_list.c"
Write-Host "22 adjacency_list done"

# 23: union_find
$dir = "$base\graph\union_find"
Rename-Item "$dir\union_find_main.c" "23_union_find_main.c"
Rename-Item "$dir\union_find.h" "23_union_find.h"
Rename-Item "$dir\union_find.c" "23_union_find.c"
Write-Host "23 union_find done"

# 24: topological_sort
$dir = "$base\graph\topological_sort"
Rename-Item "$dir\topological_sort_main.cpp" "24_topological_sort_main.cpp"
Rename-Item "$dir\topological_sort.cpp" "24_topological_sort.cpp"
Rename-Item "$dir\topological_sort.h" "24_topological_sort.h"
Write-Host "24 topological_sort done"

# 25: dijkstra
$dir = "$base\graph\dijkstra"
Rename-Item "$dir\dijkstra_main.cpp" "25_dijkstra_main.cpp"
Rename-Item "$dir\dijkstra.cpp" "25_dijkstra.cpp"
Rename-Item "$dir\dijkstra.h" "25_dijkstra.h"
Write-Host "25 dijkstra done"

# 26: bellman_ford
$dir = "$base\graph\bellman_ford"
Rename-Item "$dir\bellman_ford_main.cpp" "26_bellman_ford_main.cpp"
Rename-Item "$dir\bellman_ford.cpp" "26_bellman_ford.cpp"
Rename-Item "$dir\bellman_ford.h" "26_bellman_ford.h"
Write-Host "26 bellman_ford done"

# 27: floyd_warshall
$dir = "$base\graph\floyd_warshall"
Rename-Item "$dir\floyd_warshall_main.cpp" "27_floyd_warshall_main.cpp"
Rename-Item "$dir\floyd_warshall.cpp" "27_floyd_warshall.cpp"
Rename-Item "$dir\floyd_warshall.h" "27_floyd_warshall.h"
Write-Host "27 floyd_warshall done"

# 28: kruskal
$dir = "$base\graph\kruskal"
Rename-Item "$dir\kruskal_main.cpp" "28_kruskal_main.cpp"
Rename-Item "$dir\kruskal.cpp" "28_kruskal.cpp"
Rename-Item "$dir\kruskal.h" "28_kruskal.h"
Write-Host "28 kruskal done"

# 29: prim
$dir = "$base\graph\prim"
Rename-Item "$dir\prim_main.cpp" "29_prim_main.cpp"
Rename-Item "$dir\prim.cpp" "29_prim.cpp"
Rename-Item "$dir\prim.h" "29_prim.h"
Write-Host "29 prim done"

# 30: string_algorithm
$dir = "$base\string_algorithm"
Rename-Item "$dir\z_algorithm_main.cpp" "30_z_algorithm_main.cpp"
Rename-Item "$dir\z_algorithm.cpp" "30_z_algorithm.cpp"
Rename-Item "$dir\z_algorithm.h" "30_z_algorithm.h"
Rename-Item "$dir\string_main.cpp" "30_string_main.cpp"
Rename-Item "$dir\rabin_karp.cpp" "30_rabin_karp.cpp"
Rename-Item "$dir\rolling_hash.cpp" "30_rolling_hash.cpp"
Rename-Item "$dir\manacher.cpp" "30_manacher.cpp"
Rename-Item "$dir\lcs.cpp" "30_lcs.cpp"
Rename-Item "$dir\kmp.cpp" "30_kmp.cpp"
Rename-Item "$dir\brute_force_match.cpp" "30_brute_force_match.cpp"
Rename-Item "$dir\boyer_moore.cpp" "30_boyer_moore.cpp"
Write-Host "30 string_algorithm done"

# 31: dynamic_programming
$dir = "$base\advanced_algorithm\dynamic_programming"
Rename-Item "$dir\matrix_chain_main.cpp" "31_matrix_chain_main.cpp"
Rename-Item "$dir\lcs_dp_main.cpp" "31_lcs_dp_main.cpp"
Rename-Item "$dir\matrix_chain.cpp" "31_matrix_chain.cpp"
Rename-Item "$dir\lcs_dp.cpp" "31_lcs_dp.cpp"
Rename-Item "$dir\matrix_chain.h" "31_matrix_chain.h"
Rename-Item "$dir\lcs_dp.h" "31_lcs_dp.h"
Rename-Item "$dir\max_subarray.cpp" "31_max_subarray.cpp"
Rename-Item "$dir\lis.cpp" "31_lis.cpp"
Rename-Item "$dir\knapsack_complete.cpp" "31_knapsack_complete.cpp"
Rename-Item "$dir\fibonacci.cpp" "31_fibonacci.cpp"
Rename-Item "$dir\knapsack_01.cpp" "31_knapsack_01.cpp"
Rename-Item "$dir\house_robber.cpp" "31_house_robber.cpp"
Rename-Item "$dir\edit_distance.cpp" "31_edit_distance.cpp"
Rename-Item "$dir\coin_change.cpp" "31_coin_change.cpp"
Rename-Item "$dir\climbing_stairs.cpp" "31_climbing_stairs.cpp"
Write-Host "31 dynamic_programming done"

# 32: greedy
$dir = "$base\advanced_algorithm\greedy"
Rename-Item "$dir\interval_scheduling.cpp" "32_interval_scheduling.cpp"
Rename-Item "$dir\fractional_knapsack.cpp" "32_fractional_knapsack.cpp"
Rename-Item "$dir\activity_selection.cpp" "32_activity_selection.cpp"
Write-Host "32 greedy done"

# 33: divide_and_conquer
$dir = "$base\advanced_algorithm\divide_and_conquer"
Rename-Item "$dir\max_subarray_dc.cpp" "33_max_subarray_dc.cpp"
Rename-Item "$dir\closest_pair.cpp" "33_closest_pair.cpp"
Write-Host "33 divide_and_conquer done"

# 34: backtracking
$dir = "$base\advanced_algorithm\backtracking"
Rename-Item "$dir\subset_sum.cpp" "34_subset_sum.cpp"
Rename-Item "$dir\permutations.cpp" "34_permutations.cpp"
Rename-Item "$dir\n_queens.cpp" "34_n_queens.cpp"
Rename-Item "$dir\combinations.cpp" "34_combinations.cpp"
Write-Host "34 backtracking done"

# 35: bit_manipulation
$dir = "$base\bit_manipulation"
Rename-Item "$dir\bit_manipulation_main.cpp" "35_bit_manipulation_main.cpp"
Rename-Item "$dir\bit_manipulation.h" "35_bit_manipulation.h"
Rename-Item "$dir\bit_manipulation.cpp" "35_bit_manipulation.cpp"
Write-Host "35 bit_manipulation done"

# 36: math
$dir = "$base\math"
Rename-Item "$dir\math_algorithms_main.cpp" "36_math_algorithms_main.cpp"
Rename-Item "$dir\math_algorithms.h" "36_math_algorithms.h"
Rename-Item "$dir\math_algorithms.cpp" "36_math_algorithms.cpp"
Write-Host "36 math done"

Write-Host "ALL RENAMES COMPLETE"
