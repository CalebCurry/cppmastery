#include <iostream>

class Data {
   private:
    std::string data;

   public:
    // protect encapsulation
    // while still saving memory (references)
    const std::string& getData() const { return data; }
    void setData(const std::string& d) { data = d; }
};

int main() {
    Data me;
    me.setData("Caleb");
    const std::string& value = me.getData();  // reference to interal state
    std::cout << me.getData() << std::endl;
}