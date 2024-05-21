#include <iostream>

enum class ErrorCode {
    None,
    NotFound,
    PermissionDenied,
    Unknown,
};

ErrorCode getError() {
    int input;
    std::cout
        << "Error code (0: None, 1: NotFound, 2: PermissionDenied, 3: Unkown):"
        << std::endl;
    std::cin >> input;
    if (input >= 0 && input < 4) {
        return static_cast<ErrorCode>(input);
    } else {
        std::cout << "invalid error code. Defaulting to unknown" << std::endl;
        return ErrorCode::Unknown;
    }
}

int main() {
    switch (auto error = getError(); error) {
        case ErrorCode::PermissionDenied:
            std::cout << "Access denied" << std::endl;
            break;
        case ErrorCode::NotFound:
            std::cout << "Not Found" << std::endl;
            break;
        case ErrorCode::Unknown:
            std::cout << "Unknown Error" << std::endl;
            break;
        case ErrorCode::None:
            std::cout << "No Errors!" << std::endl;
            break;
    }
}