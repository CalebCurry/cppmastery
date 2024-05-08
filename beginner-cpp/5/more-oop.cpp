#include <iostream>

class Person {
   public:
    Person(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    // void setFirstName(const std::string& firstName) {
    //     this->firstName = firstName;
    // }

    Person& setFirstName(const std::string& firstName) {
        this->firstName = firstName;
        return *this;
    }

    void setLastName(const std::string& lastName) { this->lastName = lastName; }

    std::string getName() { return firstName + " " + lastName; }

    bool operator==(const Person& other) const {
        return (this->firstName == other.firstName &&
                this->lastName == other.lastName);
    }

    void print() { std::cout << *this << std::endl; }

    friend std::ostream& operator<<(std::ostream& os, Person& p);

    // identity
    //  bool operator==(const Person& other) const { return this == &other; }

   private:
    std::string firstName;
    std::string lastName;
};

std::ostream& operator<<(std::ostream& os, Person& p) {
    os << p.firstName << " " << p.lastName;
    return os;
}

int main() {
    Person p1("Caleb", "Curry");
    Person p2 = p1;

    p1.setFirstName("John").setLastName("Smith");

    std::cout << p1 << std::endl;
    p1.print();

    if (p1 == p2) {
        // std::cout << "they are equal" << std::endl;  // same person
    }
}