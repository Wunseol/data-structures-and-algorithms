add_executable(string_algorithm string_main.cpp)
target_compile_features(string_algorithm PRIVATE cxx_std_17)

add_executable(boyer_moore boyer_moore.cpp)
target_compile_features(boyer_moore PRIVATE cxx_std_17)

add_executable(brute_force_match brute_force_match.cpp)
target_compile_features(brute_force_match PRIVATE cxx_std_17)

add_executable(kmp kmp.cpp)
target_compile_features(kmp PRIVATE cxx_std_17)

add_executable(lcs lcs.cpp)
target_compile_features(lcs PRIVATE cxx_std_17)

add_executable(manacher manacher.cpp)
target_compile_features(manacher PRIVATE cxx_std_17)

add_executable(rabin_karp rabin_karp.cpp)
target_compile_features(rabin_karp PRIVATE cxx_std_17)

add_executable(rolling_hash rolling_hash.cpp)
target_compile_features(rolling_hash PRIVATE cxx_std_17)
