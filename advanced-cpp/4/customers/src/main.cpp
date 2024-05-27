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

auto getCustomers(pqxx::work& tx) {
    std::vector<Customer> customers;

    for (auto [id, name, email] : tx.query<int, std::string, std::string>(
             "SELECT id, name, email FROM customers")) {
        customers.push_back(Customer{id, name, email});
    }

    return customers;
}

void insertCustomer(pqxx::work& tx, Customer& customer) {
    std::string query =
        "INSERT INTO customers (name, email) VALUES ($1, $2) RETURNING id";
    auto row = tx.exec_params1(query, customer.name, customer.email);
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

void deleteCustomer(pqxx::work& tx, int id) {
    tx.exec_params("DELETE FROM customers WHERE id=$1", id);
}

int main() {
    try {
        auto c = pqxx::connection(
            "dbname=postgres user=postgres password=mysecretpassword "
            "hostaddr=127.0.0.1 port=5430");

        std::cout << "Connected to: " << c.dbname() << std::endl;

        pqxx::work tx{c};

        std::string name;
        std::string email;

        std::cout << "Provide a name and email:" << std::endl;
        std::cin >> name;
        std::cin >> email;

        Customer customer{{}, name, email};

        insertCustomer(tx, customer);

        std::cout << *customer.id << std::endl;

        auto customers = getCustomers(tx);

        printCustomers(customers);

        tx.commit();

    } catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}