#include <fstream>
#include <iostream>
#include <vector>

class Person {
   public:
    Person(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    Person() : firstName(""), lastName("") {}

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

    void swapNames() {
        std::string temp = firstName;
        firstName = lastName;
        lastName = temp;
    }

    friend std::ostream& operator<<(std::ostream& os, Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);

    // identity
    //  bool operator==(const Person& other) const { return this == &other; }

   private:
    std::string firstName;
    std::string lastName;
};

std::istream& operator>>(std::istream& is, Person& p) {
    std::string fn;
    std::string ln;
    if (is >> fn >> ln) {
        p.firstName = fn;
        p.lastName = ln;
    } else {
        // if something goes wrong
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Person& p) {
    os << p.firstName << " " << p.lastName;
    return os;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::vector<Person> people;

    if (!input.is_open()) {
        std::cerr << "Something went wrong with reading input file"
                  << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cerr << "Something went wrong with reading output file"
                  << std::endl;
        return 1;
    }

    Person p;
    while (input >> p) {
        people.push_back(p);
    }

    for (auto& p : people) {
        p.swapNames();
    }
    // manipulate the data
    // save the data back to disk

    for (auto& p : people) {
        output << p << std::endl;
    }
}