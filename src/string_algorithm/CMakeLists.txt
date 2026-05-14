add_executable(30_string_algorithm 30_string_main.cpp)
target_compile_features(30_string_algorithm PRIVATE cxx_std_17)

add_executable(30_boyer_moore 30_boyer_moore.cpp)
target_compile_features(30_boyer_moore PRIVATE cxx_std_17)

add_executable(30_brute_force_match 30_brute_force_match.cpp)
target_compile_features(30_brute_force_match PRIVATE cxx_std_17)

add_executable(30_kmp 30_kmp.cpp)
target_compile_features(30_kmp PRIVATE cxx_std_17)

add_executable(30_lcs 30_lcs.cpp)
target_compile_features(30_lcs PRIVATE cxx_std_17)

add_executable(30_manacher 30_manacher.cpp)
target_compile_features(30_manacher PRIVATE cxx_std_17)

add_executable(30_rabin_karp 30_rabin_karp.cpp)
target_compile_features(30_rabin_karp PRIVATE cxx_std_17)

add_executable(30_rolling_hash 30_rolling_hash.cpp)
target_compile_features(30_rolling_hash PRIVATE cxx_std_17)

add_executable(30_z_algorithm 30_z_algorithm_main.cpp 30_z_algorithm.cpp)
target_compile_features(30_z_algorithm PRIVATE cxx_std_17)
