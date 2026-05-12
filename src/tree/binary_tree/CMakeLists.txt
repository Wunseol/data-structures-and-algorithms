add_executable(binary_tree_test binary_tree_test.cpp)
target_compile_features(binary_tree_test PRIVATE cxx_std_17)

add_executable(binary_tree_test_v2 binary_tree_test_v2.cpp)
target_compile_features(binary_tree_test_v2 PRIVATE cxx_std_17)

add_executable(binary_tree_v1 binary_tree_v1.cpp)
target_compile_features(binary_tree_v1 PRIVATE cxx_std_17)

add_executable(binary_tree_v2 binary_tree_v2.c)
target_compile_features(binary_tree_v2 PRIVATE c_std_17)

add_executable(binary_tree_v3 binary_tree_v3.cpp bint.h)
target_compile_features(binary_tree_v3 PRIVATE cxx_std_17)

add_executable(binary_tree_v4 binary_tree_v4.cpp bint.h)
target_compile_features(binary_tree_v4 PRIVATE cxx_std_17)

add_executable(binary_tree_v5 binary_tree_v5.cpp)
target_compile_features(binary_tree_v5 PRIVATE cxx_std_17)

add_executable(binary_tree_v6 binary_tree_v6.cpp)
target_compile_features(binary_tree_v6 PRIVATE cxx_std_17)

add_executable(count_leaves count_leaves.cpp)
target_compile_features(count_leaves PRIVATE cxx_std_17)

add_executable(swap_subtree swap_subtree.cpp)
target_compile_features(swap_subtree PRIVATE cxx_std_17)
