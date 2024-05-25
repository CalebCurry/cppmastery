#include <iostream>
#include <pqxx/pqxx>

auto getCustomers(pqxx::work& tx) {
    return tx.query<int, std::string, std::string>(
        "SELECT id, name, email FROM customers");
}

void insertCustomer(pqxx::work& tx, std::string name, std::string email) {
    std::string query = "INSERT INTO customers (name, email) VALUES ($1, $2)";
    // std::cout << query << std::endl;
    tx.exec_params(query, name, email);
}

void printCustomers(
    pqxx::internal::result_iteration<int, std::string, std::string> customers) {
    for (auto [id, name, email] : customers) {
        std::cout << id << " ";
        std::cout << name << " ";
        std::cout << email << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    try {
        auto c = pqxx::connection(
            "dbname=postgres user=postgres password=mysecretpassword "
            "hostaddr=127.0.0.1 port=5430");

        std::cout << "Connected to: " << c.dbname() << std::endl;

        pqxx::work tx{c};

        std::string name = "Sandra";
        std::string email = "san@dra.tech";

        insertCustomer(tx, name, email);

        auto customers = getCustomers(tx);

        printCustomers(customers);

        tx.commit();

    } catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}