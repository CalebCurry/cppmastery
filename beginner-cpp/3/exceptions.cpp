#include <iostream>
#include <vector>

int main() {
    try {
        std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << numbers.at(numbers.size()) << std::endl;

        std::vector<int*> data;
        for (long long i = 0; i < 100000000000; i++) {
            data.push_back(new int[10000000]);
            std::cout << i << std::endl;
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Something failed: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Something failed: " << e.what() << std::endl;
    } catch (const char* msg) {
        std::cerr << "Something failed: " << msg << std::endl;
    } catch (...) {
        std::cerr << "Something failed" << std::endl;
    }
}