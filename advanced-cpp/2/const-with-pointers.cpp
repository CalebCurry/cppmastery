#include <iostream>
#include <vector>

void doSomething(const std::vector<const int*>& vec) {}

int main() {
    int data = 5;  // optionally const

    // pointer to const
    // const int* ptr = &data;

    // const pointer
    // int* const ptr = &data;

    // const pointer to a const
    // const int* const ptr = &data;

    // regular pointer
    int* ptr = &data;

    // change the actual data
    data = 10;
    std::cout << data << " " << *ptr << std::endl;

    // change data indirectly
    *ptr = 15;
    std::cout << data << " " << *ptr << std::endl;

    // change where the pointer points
    int other = 20;
    ptr = &other;
    std::cout << other << " " << data << " " << *ptr << std::endl;

    int a = 1;
    int b = 2;
    int c = 3;

    const std::vector<const int*> vec{&a, &b, &c};

    doSomething(vec);

    std::cout << *vec.at(0) << " " << *vec.at(1) << " " << std::endl;
}