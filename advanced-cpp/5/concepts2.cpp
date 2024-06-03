#include <concepts>
#include <iostream>
#include <type_traits>

template <typename T>
concept Clearable = requires(T x) {
    { x.clear() } -> std::same_as<void>;
};

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
    void clear() { content = ""; }
};

template <typename F>
    requires requires(F x) {
        { x.clear() } -> std::same_as<void>;
    }
void processFile(F& file) {
    file.clear();
}

int main() {
    TextFile textFile("Some example data");
    processFile(textFile);
}