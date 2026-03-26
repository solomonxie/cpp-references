/**
 * 0001_multithreading.cpp
 * 
 * Demonstrates basic multithreading using std::thread.
 * This includes thread creation, passing arguments, and joining threads.
 */
#include <iostream>
#include <thread>
#include <vector>
#include <string>

void workerTask(int id, const std::string& msg) {
    std::cout << "Thread " << id << " is processing: " << msg << std::endl;
}

int main() {
    std::cout << "Main thread starting..." << std::endl;

    // Creating threads
    std::thread t1(workerTask, 1, "Task A");
    std::thread t2(workerTask, 2, "Task B");

    // Using lambda in thread
    std::thread t3([](int id) {
        std::cout << "Thread " << id << " (lambda) is running." << std::endl;
    }, 3);

    // Vector of threads
    std::vector<std::thread> workers;
    for (int i = 4; i <= 6; ++i) {
        workers.emplace_back(workerTask, i, "Bulk Task");
    }

    // Join threads (wait for completion)
    t1.join();
    t2.join();
    t3.join();

    for (auto& w : workers) {
        if (w.joinable()) {
            w.join();
        }
    }

    std::cout << "Main thread finished." << std::endl;
    return 0;
}
