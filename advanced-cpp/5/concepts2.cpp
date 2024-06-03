#include <concepts>
#include <iostream>
#include <type_traits>

template <typename T>
concept FileHandler = requires(T x, const std::string& data) {
    { x.read() } -> std::same_as<std::string>;
    { x.write(data) } -> std::same_as<void>;
};

class TextFile {
   public:
    std::string content;
    TextFile(std::string content) : content(content) {}
    std::string read() { return content; }
    void write(std::string content) { this->content = content; }
};

template <FileHandler F>
void processFile(F& file) {
    std::cout << "Current file content: " << file.read() << std::endl;
    file.write("Updated content");
    std::cout << "File has been updated" << std::endl;
}

int main() {
    TextFile textFile("Some example data");
    processFile(textFile);
}