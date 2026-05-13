# Coding Guidelines

This document defines the coding standards and conventions for the Data Structures and Algorithms project.

## Naming Conventions

| Element          | Convention        | Example                    |
|------------------|-------------------|----------------------------|
| Files            | `snake_case`      | `sequential_list.c`        |
| Directories      | `snake_case`      | `linear_list/`             |
| Variables        | `snake_case`      | `node_count`               |
| Functions        | `snake_case`      | `list_insert()`            |
| Type names       | `PascalCase`      | `LinkedList`, `TreeNode`   |
| Macros/Constants | `UPPER_SNAKE`     | `MAX_SIZE`, `INIT_CAPACITY`|

## File Organization

Each module follows a consistent directory structure:

```
module_name/
├── module_name.h        # Public header (declarations, Doxygen comments)
├── module_name.c        # Implementation (C17)
├── module_name.cpp      # Implementation (C++17, alternative)
└── module_name.main.c   # Main entry with self-test
```

- One module per directory
- Header files contain only declarations and Doxygen documentation
- Implementation files contain the logic
- `.main.c` / `.main.cpp` files contain the self-test entry point

## Memory Management

### C Modules (`.c` files)
- Use `malloc()` / `calloc()` / `realloc()` for allocation
- Use `free()` for deallocation
- **Always** check the return value of allocation functions:
  ```c
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return -1;
  }
  ```

### C++ Modules (`.cpp` files)
- Use `new` / `new[]` for allocation
- Use `delete` / `delete[]` for deallocation
- **Always** check the return value:
  ```cpp
  int *arr = new (std::nothrow) int[size];
  if (arr == nullptr) {
      std::cerr << "Memory allocation failed" << std::endl;
      return -1;
  }
  ```

### No Mixing
- Never use `malloc`/`free` in `.cpp` files
- Never use `new`/`delete` in `.c` files
- Never mix C and C++ memory management within the same module

## Cross-Platform Compatibility

### Conditional Compilation
Use preprocessor directives for platform-specific code:

```c
#ifdef _WIN32
    system("cls");
    system("pause");
#else
    system("clear");
#endif
```

### Prohibited Headers
- Do **not** use `conio.h` (Windows-specific)
- Do **not** use `windows.h` (Windows-specific)
- Use standard C/C++ library headers only

## Error Handling

- **Check return values** of all functions that can fail (allocation, file I/O, etc.)
- **Use `assert`** for debugging invariants:
  ```c
  #include <assert.h>
  assert(index >= 0 && index < size);
  ```
- Provide meaningful error messages to `stderr`
- Return error codes from functions rather than silently failing

## Comments

### Doxygen Style for Headers
All public headers must include Doxygen-style comments:

```c
/**
 * @file sequential_list.h
 * @brief Dynamic array implementation of a sequential list
 *
 * Provides create, destroy, insert, delete, and access operations
 * for a dynamically-sized sequential list.
 */

/**
 * @brief Insert an element at the specified position
 *
 * @param list Pointer to the sequential list
 * @param index Position to insert at (0-based)
 * @param value Value to insert
 * @return 0 on success, -1 on failure
 */
int sequential_list_insert(SequentialList *list, int index, int value);
```

### Doxygen Tags Reference

| Tag        | Usage                          |
|------------|--------------------------------|
| `@file`    | File name and description      |
| `@brief`   | Brief description              |
| `@param`   | Function parameter description |
| `@return`  | Return value description       |
| `@note`    | Additional notes               |
| `@warning` | Warnings and caveats           |

## Complexity Annotation

Every algorithm **must** document its time and space complexity:

```c
/**
 * @brief Binary search in a sorted array
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * @param arr Sorted array to search
 * @param size Number of elements
 * @param target Value to find
 * @return Index of target, or -1 if not found
 */
int binary_search(const int *arr, int size, int target);
```

## Self-Test Requirement

Every module **must** include a self-test that validates core functionality:

```c
#include "tests/self_test.h"

void test_sequential_list(void) {
    SequentialList *list = sequential_list_create();
    ASSERT_NOT_NULL(list);

    sequential_list_insert(list, 0, 42);
    ASSERT_EQ(42, sequential_list_get(list, 0));
    ASSERT_EQ(1, sequential_list_size(list));

    sequential_list_destroy(list);
}

int main(void) {
    TEST_BEGIN("Sequential List");
    test_sequential_list();
    TEST_END();
}
```

Self-tests should cover:
- Normal cases (typical inputs)
- Edge cases (empty structures, single element, boundary indices)
- Error cases (invalid inputs, allocation failures)

## Python Coding Guidelines

### File Organization

Each Python module follows a consistent structure:

```
module_name/
├── __init__.py          # Package init with public exports and __all__
├── module_name.py       # Implementation with type annotations
└── ...
```

- All public functions must be exported in `__init__.py` with `__all__`
- Use Python 3.10+ type annotations for all function signatures
- Each module must include a `if __name__ == "__main__":` self-test block

### Type Annotations

All function signatures must include type annotations:

```python
def binary_search(arr: list[int], target: int) -> int:
    ...
```

### Naming Conventions

| Element          | Convention        | Example                    |
|------------------|-------------------|----------------------------|
| Modules          | `snake_case`      | `binary_search.py`         |
| Functions        | `snake_case`      | `binary_search()`          |
| Classes          | `PascalCase`      | `SequentialList`           |
| Constants        | `UPPER_SNAKE`     | `MAX_CAPACITY`             |
| Type variables   | `PascalCase`      | `T`, `KT`, `VT`           |

### Complexity Annotation

Every algorithm must document its time and space complexity in the docstring:

```python
def binary_search(arr: list[int], target: int) -> int:
    """Binary search in a sorted array.

    Time Complexity: O(log n)
    Space Complexity: O(1)
    ...
    """
```
