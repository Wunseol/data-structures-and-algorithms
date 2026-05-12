add_executable(test_circular_queue test_circular_queue.c ${CMAKE_SOURCE_DIR}/src/queue/circular_queue/circular_queue.c)
target_include_directories(test_circular_queue PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_circular_queue PRIVATE c_std_17)

add_executable(test_hash_table test_hash_table.c ${CMAKE_SOURCE_DIR}/src/hash_table/hash_table_chaining.c ${CMAKE_SOURCE_DIR}/src/hash_table/hash_table_open_addressing.c)
target_include_directories(test_hash_table PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR})
target_compile_features(test_hash_table PRIVATE c_std_17)

add_executable(test_sorting test_sorting.cpp)
target_include_directories(test_sorting PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_compile_features(test_sorting PRIVATE cxx_std_17)

add_executable(test_searching test_searching.cpp)
target_include_directories(test_searching PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_compile_features(test_searching PRIVATE cxx_std_17)
