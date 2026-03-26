/**
 * 0010_variant_optional_any.cpp
 * 
 * Demonstrates type-safe containers introduced in C++17:
 * 1. std::optional: Represents an optional value.
 * 2. std::variant: Represents a type-safe union.
 * 3. std::any: A container that can hold any type.
 */
#include <iostream>
#include <string>
#include <optional>
#include <variant>
#include <any>

// optional: May or may not return a value
std::optional<int> findValue(bool found) {
    if (found) return 42;
    return std::nullopt;
}

int main() {
    // 1. optional
    auto result = findValue(true);
    if (result) std::cout << "Optional value: " << *result << std::endl;

    // 2. variant: Type-safe union
    std::variant<int, std::string> v = "Hello";
    std::cout << "Variant contains string: " << std::get<std::string>(v) << std::endl;
    v = 100;
    std::cout << "Variant now contains int: " << std::get<int>(v) << std::endl;

    // 3. any: Dynamic type container
    std::any a = 5;
    std::cout << "Any contains int: " << std::any_cast<int>(a) << std::endl;
    a = std::string("Dynamic");
    std::cout << "Any now contains string: " << std::any_cast<std::string>(a) << std::endl;

    return 0;
}
