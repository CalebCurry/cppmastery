#include <fstream>
#include <iostream>
#include <vector>

class Person {
   public:
    virtual void work() = 0;
    Person(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    Person() : firstName(""), lastName("") {}

    virtual ~Person() { std::cout << "Destroying " << *this << std::endl; }

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

class Student final : public Person {
   public:
    std::string major;
    void work() {
        std::cout << "I am working on studying " << major << std::endl;
    }

    ~Student() { std::cout << "Destroying student " << *this << std::endl; }
};

class Teacher final : public Person {
   public:
    std::vector<std::string> classes;
    void work() {
        for (auto c : classes) {
            std::cout << "Teaching " << c << std::endl;
        }
    }

    ~Teacher() { std::cout << "Destroying teacher " << *this << std::endl; }
};

int main() {
    // Student s;
    // s.setFirstName("Caleb").setLastName("Curry");
    // std::cout << s << std::endl;

    // Teacher t;
    // t.setFirstName("Kale").setLastName("Cork");
    // std::cout << t << std::endl;

    Person* p = new Student();
    p->setFirstName("Caleb").setLastName("Curry");
    delete p;
}