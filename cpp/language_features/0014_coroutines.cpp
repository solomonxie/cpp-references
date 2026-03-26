/**
 * 0014_coroutines.cpp
 * 
 * Demonstrates C++20 Coroutines.
 * Simple Generator example using co_yield.
 */
#include <iostream>
#include <coroutine>

template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T value;
        auto get_return_object() { return Generator{handle_type::from_promise(*this)}; }
        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }
        void unhandled_exception() { std::terminate(); }
        auto yield_value(T v) {
            value = v;
            return std::suspend_always{};
        }
        void return_void() {}
    };

    handle_type h;
    Generator(handle_type h) : h(h) {}
    ~Generator() { if (h) h.destroy(); }
    
    T next() {
        h.resume();
        return h.promise().value;
    }
    bool done() { return h.done(); }
};

Generator<int> countToThree() {
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

int main() {
    auto gen = countToThree();
    while (!gen.done()) {
        std::cout << "Generated: " << gen.next() << std::endl;
    }
    return 0;
}
