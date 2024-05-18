#include <iostream>

class Algo {
   private:
    mutable int bonus = 50;
    mutable int calculationCount = 0;

   public:
    int calculateBonus(int value) const {
        calculationCount++;
        auto result = value + bonus;
        bonus -= 10;
        return result;
    }
    void setBonus(int b) { bonus = b; }
    int getCalculationCount() { return calculationCount; }
};

int main() {
    Algo algo;
    Algo algo2;
    std::cout << algo.calculateBonus(10) << std::endl;
    std::cout << algo.getCalculationCount() << std::endl;
    std::cout << algo.calculateBonus(10) << std::endl;
    std::cout << algo.getCalculationCount() << std::endl;
    std::cout << algo.calculateBonus(10) << std::endl;
    std::cout << algo.getCalculationCount() << std::endl;
    std::cout << algo.calculateBonus(10) << std::endl;
    std::cout << algo.getCalculationCount() << std::endl;
    std::cout << algo2.getCalculationCount() << std::endl;
}