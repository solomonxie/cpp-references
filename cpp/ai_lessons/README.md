# C++ AI Lessons

This folder includes AI-generated code pieces that each file can be executed independently.
Each file demonstrates one particular C++ concept: syntax, features, or skills.

**Format:** `NNNN_topic.cpp` (e.g. `0001_helloworld.cpp`).

---

## Curriculum

### 1. Fundamentals (0001–0012)

| # | Filename | Concept |
|---|----------|--------|
| 0001 | `0001_helloworld.cpp` | Minimal program, `main()`, `cout`, `\n` |
| 0002 | `0002_data_types.cpp` | `int`, `double`, `bool`, `char`, `size_t` |
| 0003 | `0003_variables.cpp` | Declaration, definition, initialization, `auto` |
| 0004 | `0004_literals.cpp` | Integer/float/char/string literals, suffixes (`u`, `l`, `f`) |
| 0005 | `0005_operators_arithmetic.cpp` | `+ - * / %`, precedence, integer vs float division |
| 0006 | `0006_operators_comparison.cpp` | `== != < > <= >=`, result type `bool` |
| 0007 | `0007_operators_logical.cpp` | `&& \|\| !`, short-circuit evaluation |
| 0008 | `0008_comments.cpp` | `//` and `/* */`, style and Doxygen |
| 0009 | `0009_const.cpp` | `const` variables and const correctness |
| 0010 | `0010_type_conversion.cpp` | Implicit conversion, `static_cast` |
| 0011 | `0011_keywords.cpp` | Reserved keywords overview |
| 0012 | `0012_namespace.cpp` | `namespace`, `using`, `std::` |

### 2. I/O and Console (0013–0017)

| # | Filename | Concept |
|---|----------|--------|
| 0013 | `0013_cout_cin.cpp` | `cout`, `cin`, `>>`, `<<`, basic formatting |
| 0014 | `0014_getline.cpp` | `std::getline()`, whitespace, `cin` vs `getline` |
| 0015 | `0015_iomanip.cpp` | `setw`, `setprecision`, `fixed`, `left`/`right` |
| 0016 | `0016_cerr_endl.cpp` | `cerr`, `endl` vs `'\n'`, buffering |
| 0017 | `0017_stringstream.cpp` | `std::istringstream` / `std::ostringstream` |

### 3. Control Flow (0018–0024)

| # | Filename | Concept |
|---|----------|--------|
| 0018 | `0018_if_else.cpp` | `if` / `else if` / `else` |
| 0019 | `0019_switch.cpp` | `switch`, `case`, `break`, `default` |
| 0020 | `0020_for_loop.cpp` | `for (init; condition; step)` |
| 0021 | `0021_while_loop.cpp` | `while`, `do-while` |
| 0022 | `0022_range_for.cpp` | Range-based `for (auto x : range)` |
| 0023 | `0023_break_continue.cpp` | `break`, `continue` in loops |
| 0024 | `0024_ternary.cpp` | Ternary operator `? :` |

### 4. Functions (0025–0031)

| # | Filename | Concept |
|---|----------|--------|
| 0025 | `0025_functions.cpp` | Function declaration, definition, call, return |
| 0026 | `0026_function_overload.cpp` | Overloading by parameter list |
| 0027 | `0027_default_arguments.cpp` | Default parameter values |
| 0028 | `0028_inline.cpp` | `inline` functions |
| 0029 | `0029_pass_by_value_reference.cpp` | Value vs reference parameters |
| 0030 | `0030_return_reference.cpp` | Returning by value vs reference |
| 0031 | `0031_lambda.cpp` | Lambda syntax `[](){}`, capture `[=]`/`[&]` |

### 5. Arrays and Strings (0032–0038)

| # | Filename | Concept |
|---|----------|--------|
| 0032 | `0032_array_cstyle.cpp` | C-style arrays, size, indexing |
| 0033 | `0033_std_array.cpp` | `std::array<T,N>`, `.size()`, bounds |
| 0034 | `0034_std_string.cpp` | `std::string`, concatenation, `.size()`, indexing |
| 0035 | `0035_cstring.cpp` | C-string `char[]`, `\0`, `strlen`, `strcpy` |
| 0036 | `0036_vector_basics.cpp` | `std::vector`, `push_back`, `size`, indexing |
| 0037 | `0037_vector_operations.cpp` | `insert`, `erase`, `clear`, iteration |
| 0038 | `0038_multidimensional.cpp` | 2D array / `vector<vector<T>>` |

### 6. Pointers and References (0039–0043)

| # | Filename | Concept |
|---|----------|--------|
| 0039 | `0039_pointers.cpp` | Pointer declaration, `&` address-of, `*` dereference |
| 0040 | `0040_pointers_arithmetic.cpp` | Pointer arithmetic, array relationship |
| 0041 | `0041_references.cpp` | References, binding, no null reference |
| 0042 | `0042_pass_pointer_reference.cpp` | Functions taking pointer vs reference |
| 0043 | `0043_nullptr.cpp` | `nullptr` vs `NULL`/`0` |

### 7. Struct and Class (OOP) (0044–0052)

| # | Filename | Concept |
|---|----------|--------|
| 0044 | `0044_struct.cpp` | `struct`, members, initialization |
| 0045 | `0045_class_basics.cpp` | `class`, `public`/`private`, member functions |
| 0046 | `0046_constructors.cpp` | Default, parameterized, delegating constructors |
| 0047 | `0047_destructor.cpp` | Destructor `~Class()`, RAII idea |
| 0048 | `0048_this.cpp` | `this` pointer |
| 0049 | `0049_inheritance.cpp` | Base/derived, `public` inheritance |
| 0050 | `0050_polymorphism.cpp` | `virtual`, override, base pointer to derived |
| 0051 | `0051_encapsulation.cpp` | Getters/setters, design rationale |
| 0052 | `0052_static_member.cpp` | `static` data and function members |

### 8. Memory (0053–0058)

| # | Filename | Concept |
|---|----------|--------|
| 0053 | `0053_stack_heap.cpp` | Stack vs heap, lifetime, scope |
| 0054 | `0054_new_delete.cpp` | `new`/`delete`, `new[]`/`delete[]` |
| 0055 | `0055_unique_ptr.cpp` | `std::unique_ptr`, ownership, `make_unique` |
| 0056 | `0056_shared_ptr.cpp` | `std::shared_ptr`, `make_shared`, reference count |
| 0057 | `0057_weak_ptr.cpp` | `std::weak_ptr`, breaking cycles |
| 0058 | `0058_memory_operation.cpp` | Manual allocation patterns, common pitfalls |

### 9. STL – Containers and Iterators (0059–0066)

| # | Filename | Concept |
|---|----------|--------|
| 0059 | `0059_iterators.cpp` | Iterators as cursor over container, `begin`/`end` |
| 0060 | `0060_map.cpp` | `std::map`, key-value, `[]` vs `.at()` |
| 0061 | `0061_set.cpp` | `std::set`, uniqueness, ordering |
| 0062 | `0062_pair_tuple.cpp` | `std::pair`, `std::tuple`, `get` |
| 0063 | `0063_algorithms.cpp` | `std::sort`, `find`, `for_each` from `<algorithm>` |
| 0064 | `0064_deque_list.cpp` | `std::deque`, `std::list`, when to use |
| 0065 | `0065_iterators_categories.cpp` | Input/output/forward/bidirectional/random-access |
| 0066 | `0066_cursor.cpp` | Cursor-style iteration (custom iterator or index-based) |

### 10. Advanced Language (0067–0073)

| # | Filename | Concept |
|---|----------|--------|
| 0067 | `0067_templates_function.cpp` | Function templates, type deduction |
| 0068 | `0068_templates_class.cpp` | Class templates |
| 0069 | `0069_exceptions.cpp` | `try`/`catch`/`throw`, `std::exception` |
| 0070 | `0070_enum.cpp` | `enum`, `enum class` (scoped enum) |
| 0071 | `0071_preprocessor.cpp` | `#define`, `#ifdef`, `#if`, macros caveats |
| 0072 | `0072_typedef_using.cpp` | `typedef`, `using` for type aliases |
| 0073 | `0073_move_semantics.cpp` | Rvalue reference, `std::move`, move constructor/assignment |

### 11. Headers and Project Structure (0074–0077)

| # | Filename | Concept |
|---|----------|--------|
| 0074 | `0074_headers.cpp` | Multi-file: `.h`/`.hpp` vs `.cpp`, `#include` |
| 0075 | `0075_include_guards.cpp` | `#ifndef`/`#define`/`#endif` or `#pragma once` |
| 0076 | `0076_forward_declaration.cpp` | Forward declare class/function to reduce includes |
| 0077 | `0077_cmake.cpp` | CMake: `CMakeLists.txt`, `add_executable`, `target_sources` |

### 12. File and Data (0078–0082)

| # | Filename | Concept |
|---|----------|--------|
| 0078 | `0078_file.cpp` | `<fstream>`, `ifstream`/`ofstream`, open, read/write lines |
| 0079 | `0079_file_binary.cpp` | Binary read/write, `read`/`write` |
| 0080 | `0080_json.cpp` | JSON: parse and serialize (e.g. nlohmann/json) |
| 0081 | `0081_socket.cpp` | Sockets: minimal TCP client or server |
| 0082 | `0082_chrono.cpp` | `std::chrono`, time points, durations, timing code |

---

**Total:** 82 lesson files (`0001_helloworld.cpp` through `0082_chrono.cpp`).

**Dependencies:** Most lessons use only the standard library. Exceptions: JSON library for `0080_json.cpp`, CMake for `0077_cmake.cpp`, platform APIs for `0081_socket.cpp`.
