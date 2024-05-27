#include <iostream>
#include <optional>
#include <pqxx/pqxx>
#include <vector>

class Customer {
   public:
    std::optional<int> id;
    std::string name;
    std::string email;

    Customer(std::optional<int> id, std::string name, std::string email)
        : id(id), name(name), email(email) {}
};

auto getCustomers(pqxx::connection& c) {
    pqxx::nontransaction db{c};
    std::vector<Customer> customers;

    for (auto [id, name, email] : db.query<int, std::string, std::string>(
             "SELECT id, name, email FROM customers")) {
        customers.push_back(Customer{id, name, email});
    }

    return customers;
}

void insertCustomer(pqxx::connection& c, Customer& customer) {
    pqxx::nontransaction db{c};
    std::string query =
        "INSERT INTO customers (name, email) VALUES ($1, $2) RETURNING id";
    auto row = db.exec_params1(query, customer.name, customer.email);
    customer.id = row[0].as<int>();
}

void printCustomers(std::vector<Customer> customers) {
    for (auto customer : customers) {
        std::cout << *customer.id << " ";
        std::cout << customer.name << " ";
        std::cout << customer.email << std::endl;
    }
    std::cout << std::endl;
}

void deleteCustomer(pqxx::connection& c, int id) {
    pqxx::nontransaction db{c};
    db.exec_params("DELETE FROM customers WHERE id=$1", id);
}

void printMenu(pqxx::connection& c) {
    while (true) {
        std::cout << std::endl;
        std::cout << "1. Add a customer" << std::endl;
        std::cout << "2. List customers" << std::endl;
        std::cout << "3. Delete a customer" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (input) {
            case 1: {
                std::string name;
                std::string email;

                std::cout << "Provide a name:" << std::endl;
                std::getline(std::cin, name);

                std::cout << "Provide an email:" << std::endl;
                std::getline(std::cin, email);

                Customer customer{{}, name, email};

                insertCustomer(c, customer);

                break;
            }
            case 2: {
                std::cout << "\n Your customer list: \n" << std::endl;
                auto customers = getCustomers(c);
                printCustomers(customers);
                break;
            }
            case 3: {
                std::cout << "Give us an ID to delete: ";
                int id;
                std::cin >> id;
                deleteCustomer(c, id);
                std::cout << "Deleted customer with id " << id << std::endl;
                break;
            }
            case 4:
                std::cout << "Changes saved!" << std::endl;
                return;
            default:
                std::cout << "Try a valid" << std::endl;
                break;
        }
    }
}

int main() {
    try {
        auto c = pqxx::connection(
            "dbname=postgres user=postgres password=mysecretpassword "
            "hostaddr=127.0.0.1 port=5430");

        std::cout << "Connected to: " << c.dbname() << std::endl;

        printMenu(c);

    } catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}