// Lesson: std::chrono, time points, durations, timing code
// Compile: g++ -o 0082_chrono 0082_chrono.cpp -std=c++11

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();

    std::this_thread::sleep_for(milliseconds(100));

    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);
    std::cout << "Elapsed: " << elapsed.count() << " ms\n";

    auto now_system = system_clock::now();
    auto now_time_t = system_clock::to_time_t(now_system);
    std::cout << "System time: " << ctime(&now_time_t);

    duration<double> sec = end - start;
    std::cout << "Elapsed in seconds: " << sec.count() << "\n";
    return 0;
}
