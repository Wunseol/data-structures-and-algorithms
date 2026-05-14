add_executable(test_circular_queue test_circular_queue.c ${CMAKE_SOURCE_DIR}/src/queue/circular_queue/08_circular_queue.c)
target_include_directories(test_circular_queue PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_circular_queue PRIVATE c_std_17)
add_test(NAME test_circular_queue COMMAND test_circular_queue)

add_executable(test_hash_table test_hash_table.c ${CMAKE_SOURCE_DIR}/src/hash_table/18_hash_table_chaining.c ${CMAKE_SOURCE_DIR}/src/hash_table/18_hash_table_open_addressing.c)
target_include_directories(test_hash_table PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_hash_table PRIVATE c_std_17)
add_test(NAME test_hash_table COMMAND test_hash_table)

add_executable(test_sorting test_sorting.cpp)
target_include_directories(test_sorting PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_compile_features(test_sorting PRIVATE cxx_std_17)
add_test(NAME test_sorting COMMAND test_sorting)

add_executable(test_searching test_searching.cpp)
target_include_directories(test_searching PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_compile_features(test_searching PRIVATE cxx_std_17)
add_test(NAME test_searching COMMAND test_searching)

add_executable(test_lru_cache test_lru_cache.cpp ${CMAKE_SOURCE_DIR}/src/cache/lru_cache/20_lru_cache.cpp)
target_include_directories(test_lru_cache PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_lru_cache PRIVATE cxx_std_17)
add_test(NAME test_lru_cache COMMAND test_lru_cache)

add_executable(test_bloom_filter test_bloom_filter.cpp ${CMAKE_SOURCE_DIR}/src/hash_table/bloom_filter/19_bloom_filter.cpp)
target_include_directories(test_bloom_filter PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_bloom_filter PRIVATE cxx_std_17)
add_test(NAME test_bloom_filter COMMAND test_bloom_filter)

add_executable(test_segment_tree test_segment_tree.cpp ${CMAKE_SOURCE_DIR}/src/tree/segment_tree/16_segment_tree.cpp)
target_include_directories(test_segment_tree PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_segment_tree PRIVATE cxx_std_17)
add_test(NAME test_segment_tree COMMAND test_segment_tree)

add_executable(test_fenwick_tree test_fenwick_tree.cpp ${CMAKE_SOURCE_DIR}/src/tree/fenwick_tree/17_fenwick_tree.cpp)
target_include_directories(test_fenwick_tree PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_fenwick_tree PRIVATE cxx_std_17)
add_test(NAME test_fenwick_tree COMMAND test_fenwick_tree)

add_executable(test_graph test_graph.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/topological_sort/24_topological_sort.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/dijkstra/25_dijkstra.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/bellman_ford/26_bellman_ford.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/floyd_warshall/27_floyd_warshall.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/kruskal/28_kruskal.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/prim/29_prim.cpp
)
target_include_directories(test_graph PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_graph PRIVATE cxx_std_17)
add_test(NAME test_graph COMMAND test_graph)

add_executable(test_z_algorithm test_z_algorithm.cpp ${CMAKE_SOURCE_DIR}/src/string_algorithm/30_z_algorithm.cpp)
target_include_directories(test_z_algorithm PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_z_algorithm PRIVATE cxx_std_17)
add_test(NAME test_z_algorithm COMMAND test_z_algorithm)

add_executable(test_dp test_dp.cpp
    ${CMAKE_SOURCE_DIR}/src/advanced_algorithm/dynamic_programming/31_lcs_dp.cpp
    ${CMAKE_SOURCE_DIR}/src/advanced_algorithm/dynamic_programming/31_matrix_chain.cpp
)
target_include_directories(test_dp PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_dp PRIVATE cxx_std_17)
add_test(NAME test_dp COMMAND test_dp)
