#include <iostream>

class Person {
   public:
    Person(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    void setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }

    void setLastName(const std::string& lastName) { this->lastName = lastName; }

    std::string getName() { return firstName + " " + lastName; }

   private:
    std::string firstName;
    std::string lastName;
};

int main() {
    Person p1("Caleb", "Curry");
    std::cout << p1.getName() << std::endl;
}