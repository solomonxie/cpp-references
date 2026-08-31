#include <iostream>
#include <thread>

int main() {
    std::thread t([] { std::cout << "Step 9: hello from a std::thread\n"; });
    t.join();
    return 0;
}
