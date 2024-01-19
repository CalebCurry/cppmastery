#include <iomanip>
#include <iostream>

int main() {
    bool friendly = true;
    std::cout << friendly << std::endl;

    char firstInitial = 'C';
    std::cout << firstInitial << std::endl;

    signed short s = SHRT_MIN;
    std::cout << s << std::endl;

    signed short s2 = s - 1;
    std::cout << s2 << std::endl;

    int x = INT_MAX;
    std::cout << x << std::endl;

    unsigned long x2 = ULONG_MAX;
    std::cout << x2 << std::endl;

    unsigned long long x3 = ULLONG_MAX;
    std::cout << x3 << std::endl;

    float weight = 305.5;
    double weightKG = weight * .45359237;
    std::cout << weight << " " << weightKG << std::endl;

    float a = 1.1;
    double b = 1 / 3.0;
    std::cout << std::setprecision(30);
    std::cout << a << " " << b << std::endl;

    return 0;
}