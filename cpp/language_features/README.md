# C++ Language Features

This directory illustrates important C++ language features, ranging from foundational concepts to advanced modern C++ (C++11/14/17/20) capabilities.

## Concurrency & Parallelism
- [0001_multithreading.cpp](0001_multithreading.cpp) - Basic threading with `std::thread`.
- [0002_mutex_atomic.cpp](0002_mutex_atomic.cpp) - Thread safety using `std::mutex` and `std::atomic`.
- [0003_future_async.cpp](0003_future_async.cpp) - Asynchronous programming with `std::async` and `std::future`.

## Resource Management & RAII
- [0004_raii_rule_of_five.cpp](0004_raii_rule_of_five.cpp) - Resource Acquisition Is Initialization and the Rule of Five/Zero.
- [0005_smart_pointers_advanced.cpp](0005_smart_pointers_advanced.cpp) - Advanced smart pointer usage, including custom deleters.

## Metaprogramming & Templates
- [0006_variadic_templates.cpp](0006_variadic_templates.cpp) - Templates with a variable number of arguments.
- [0007_perfect_forwarding.cpp](0007_perfect_forwarding.cpp) - Forwarding references and `std::forward`.
- [0008_sfinae.cpp](0008_sfinae.cpp) - Substitution Failure Is Not An Error (SFINAE) and `std::enable_if`.
- [0009_concepts.cpp](0009_concepts.cpp) - C++20 Concepts for template constraints.

## Modern Type System (C++17/20)
- [0010_variant_optional_any.cpp](0010_variant_optional_any.cpp) - Type-safe alternatives to unions and null pointers.
- [0011_ranges.cpp](0011_ranges.cpp) - C++20 Ranges library for composable algorithms.
- [0012_filesystem.cpp](0012_filesystem.cpp) - Modern file system manipulation.

## Error Control & Miscellaneous
- [0013_exception_safety.cpp](0013_exception_safety.cpp) - Exception safety guarantees (strong, basic, no-throw).
- [0014_coroutines.cpp](0014_coroutines.cpp) - C++20 Coroutines (basic generator example).
- [0015_rtti_dynamic_cast.cpp](0015_rtti_dynamic_cast.cpp) - Runtime Type Information and safe downcasting.
