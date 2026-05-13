# Contributing to Data Structures and Algorithms

Welcome! We're excited that you'd like to contribute to this project. This document provides guidelines and instructions for contributing.

## How to Contribute

1. **Fork** the repository to your own GitHub account
2. **Clone** the fork to your local machine
3. **Create a branch** for your feature or fix:
   ```bash
   git checkout -b feat/your-feature-name
   ```
4. **Make your changes** and commit them following our commit message format
5. **Push** your branch to your fork:
   ```bash
   git push origin feat/your-feature-name
   ```
6. **Open a Pull Request** against the `master` branch of the original repository

## Code Style Requirements

- **Language Standard**: C17 for `.c` files, C++17 for `.cpp` files
- **Naming Convention**: `snake_case` for files, directories, variables, and functions
- **No Global Variables**: Avoid global state; use parameters and return values instead
- **Cross-Platform**: Code must compile and run on Linux, macOS, and Windows
  - Use conditional compilation for platform-specific code (e.g., `system("cls")` vs `system("clear")`)
  - Do **not** use `conio.h` or `windows.h`
- **No C/C++ Mixing**: Do not mix C and C++ within the same module
  - `.c` files use `<stdio.h>`, `<stdlib.h>`, etc.
  - `.cpp` files use `<iostream>`, `<vector>`, etc.
  - Never include C++ headers in `.c` files or vice versa
- **File Encoding**: All source files (`.c`, `.cpp`, `.h`, `.md`, `.py`, `CMakeLists.txt`) **must** use UTF-8 encoding with BOM
  - This ensures Chinese characters display correctly across all platforms (Windows, macOS, Linux)
  - Do **not** use GBK, GB2312, or any other encoding
  - The `.gitattributes` file enforces UTF-8 encoding for text files
  - If you see garbled characters (乱码), the file is likely in the wrong encoding — convert it using:
    ```bash
    iconv -f GBK -t UTF-8 source_file.c > source_file_utf8.c
    ```

## Self-Test Requirement

Every new module **must** include a self-test. Use the framework provided in `tests/self_test.h`:

```c
#include "tests/self_test.h"

void test_my_module(void) {
    ASSERT_EQ(expected, actual);
    ASSERT_TRUE(condition);
    // ...
}

int main(void) {
    TEST_BEGIN("My Module");
    test_my_module();
    TEST_END();
}
```

## Commit Message Format

We follow [Conventional Commits](https://www.conventionalcommits.org/). Each commit message should be structured as:

```
<type>: <description>
```

### Allowed Types

| Type       | Description                        |
|------------|------------------------------------|
| `feat`     | A new feature or data structure    |
| `fix`      | A bug fix                          |
| `docs`     | Documentation only changes         |
| `refactor` | Code refactoring without behavior change |
| `test`     | Adding or updating tests           |
| `chore`    | Build, CI, or auxiliary changes    |

### Examples

```
feat: add red-black tree implementation
fix: correct off-by-one error in binary search
docs: update DIRECTORY.md with new modules
refactor: simplify merge sort recursion
test: add edge cases for hash table self-test
chore: update CI to use cmake 3.20
```

## Pull Request Checklist

Before submitting your PR, ensure the following:

- [ ] Code follows the project's style guidelines
- [ ] New module includes a self-test using `tests/self_test.h`
- [ ] All existing tests still pass
- [ ] Commit messages follow the Conventional Commits format
- [ ] No C/C++ header mixing within the same module
- [ ] Code is cross-platform (no OS-specific headers without conditional compilation)
- [ ] Time and space complexity is documented in comments
- [ ] Doxygen-style comments are added to public headers

## Build Verification

Before pushing, verify that the project builds successfully:

```bash
cmake -B build
cmake --build build
```

Make sure there are no compiler warnings or errors. If self-tests are available, run them to confirm all tests pass.

## Python Contribution

When contributing Python code to `python/algorithms/`:

- **Python Version**: Python 3.10+ (for type annotation support)
- **Type Annotations**: All function signatures must include type annotations
- **Package Exports**: Add new functions to the subpackage's `__init__.py` and `__all__` list
- **Self-Test**: Each module must include a `if __name__ == "__main__":` self-test block
- **Dependencies**: If a module requires third-party packages, add them to `python/requirements.txt`
- **Testing**: Run `python -m algorithms.run_all` from the `python/` directory to verify all 57 modules pass

### Python Build Verification

```bash
cd python
python -m algorithms.run_all
```

Ensure all 57 algorithm modules pass their self-tests before pushing.

Thank you for contributing!
