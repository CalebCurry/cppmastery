#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> sharedCounter(0);

void incrementCounter() {
    for (int i = 0; i < 10000; i++) {
        sharedCounter += 2;
    }
}

int main() {
    std::vector<std::jthread> threads;

    for (int i = 0; i < 10; i++) {
        threads.emplace_back(incrementCounter);
    }

    // join all the threads
    for (int i = 0; i < 10; i++) {
        threads.at(i).join();
    }

    std::cout << sharedCounter << std::endl;
}
