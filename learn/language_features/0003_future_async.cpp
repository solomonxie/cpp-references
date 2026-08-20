/**
 * 0003_future_async.cpp
 * 
 * Demonstrates asynchronous programming with:
 * 1. std::async: Running a function asynchronously.
 * 2. std::future: Getting the result of an async task.
 * 3. std::promise: Setting a value to be retrieved via future.
 */
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int calculateValue(int input) {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate heavy work
    return input * 10;
}

int main() {
    // 1. std::async and std::future
    std::cout << "Starting async calculation..." << std::endl;
    std::future<int> result_future = std::async(std::launch::async, calculateValue, 5);

    std::cout << "Doing other work in main thread..." << std::endl;

    // Get value (waits if not ready)
    int result = result_future.get();
    std::cout << "Async result: " << result << std::endl;

    // 2. std::promise and std::future
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();

    std::thread t([](std::promise<std::string> p) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        p.set_value("Message from thread via promise");
    }, std::move(prom));

    std::cout << "Waiting for promise..." << std::endl;
    std::cout << "Promise result: " << fut.get() << std::endl;
    t.join();

    return 0;
}
