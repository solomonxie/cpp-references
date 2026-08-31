Goal: learn CMake from scratch, one concept per step, by writing tiny buildable projects.

Each step is a self-contained folder — `cd` into it and run the build/run commands from the
top of its `CMakeLists.txt` (typically `cmake -S . -B build && cmake --build build`).

| Step | Path | Adds |
|------|------|------|
| 1  | [01_minimal](01_minimal) | smallest possible project: `cmake_minimum_required`, `project`, `add_executable` |
| 2  | [02_variables_message](02_variables_message) | `set()` variables, `message()`, passing a variable into C++ via `target_compile_definitions` |
| 3  | [03_multiple_sources](03_multiple_sources) | linking multiple `.cpp` files into one executable |
| 4  | [04_static_library](04_static_library) | `add_library(STATIC)` + `target_link_libraries` |
| 5  | [05_include_directories](05_include_directories) | `target_include_directories`, splitting into `include/` + `src/` |
| 6  | [06_subdirectories](06_subdirectories) | `add_subdirectory()`, a child `CMakeLists.txt` |
| 7  | [07_compiler_standard_options](07_compiler_standard_options) | `target_compile_features` (C++ standard), `target_compile_options` (warnings) |
| 8  | [08_build_types](08_build_types) | `CMAKE_BUILD_TYPE`, per-config flags via a first generator expression |
| 9  | [09_find_package_threads](09_find_package_threads) | `find_package(Threads)`, linking an imported target |
| 10 | [10_option_configure_file](10_option_configure_file) | `option()`, `configure_file()` generating a header from `@VAR@` placeholders |
| 11 | [11_install_rules](11_install_rules) | `install(TARGETS ...)`, `install(FILES ...)`, `cmake --install` |
| 12 | [12_testing_ctest](12_testing_ctest) | `enable_testing()`, `add_test()`, running tests with `ctest` |
| 13 | [13_fetchcontent](13_fetchcontent) | `FetchContent` — pulling in an external dependency (fmt) at configure time |
| 14 | [14_generator_expressions](14_generator_expressions) | more generator-expression forms: `BUILD_INTERFACE`/`INSTALL_INTERFACE`, `$<TARGET_FILE:...>` |
| 15 | [15_custom_commands](15_custom_commands) | `add_custom_command()` codegen + `add_custom_target()` |
