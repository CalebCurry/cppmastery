#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int sharedCounter = 0;
std::mutex mtx;

void incrementCounter() {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        sharedCounter++;
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
