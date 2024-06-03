#include <iostream>
#include <thread>

int main() {
    std::jthread t([]() {
        std::cout << "Hello from thread!\n";
        std::this_thread::sleep_for(
            std::chrono::seconds(2));  // Simulate some work
        std::cout << "Thread work complete.\n";
    });

    std::cout << "Main thread continues immediately.\n";
    t.join();  // wait for thread
    std::cout << "Main thread is now exiting.\n";
}