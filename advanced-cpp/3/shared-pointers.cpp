#include <iostream>
#include <memory>
#include <vector>

int main() {
    auto ptr = std::make_shared<std::vector<int>>(std::vector{1, 2, 3, 4, 5});

    std::cout << ptr->at(2) << std::endl;

    std::shared_ptr<int> ptr1 = std::make_shared<int>(10);

    std::cout << "Reference count after ptr1: " << ptr1.use_count()
              << std::endl;

    {
        std::shared_ptr<int> ptr2 = ptr1;
        std::cout << "Reference count after ptr2: " << ptr1.use_count()
                  << std::endl;

        {
            std::shared_ptr<int> ptr3 = ptr2;
            std::cout << "Reference count after ptr3: " << ptr1.use_count()
                      << std::endl;
        }

        std::cout << "Reference count after ptr3 goes out of scope: "
                  << ptr1.use_count() << std::endl;
    }

    std::cout << "Reference count after ptr2 goes out of scope: "
              << ptr1.use_count() << std::endl;
}
