#include <iostream>

template <typename T, size_t rows, size_t cols>
void printArray(T(data)[rows][cols]) {
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            std::cout << data[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkForWin(char board[][3]) {
    return (board[0][0] == board[0][1] && board[0][1] == board[0][2] &&
            board[0][0] != '-') ||
           (board[1][0] == board[1][1] && board[1][1] == board[1][2] &&
            board[1][0] != '-') ||
           (board[2][0] == board[2][1] && board[2][1] == board[2][2] &&
            board[2][0] != '-') ||
           (board[0][0] == board[1][0] && board[1][0] == board[2][0] &&
            board[0][0] != '-') ||
           (board[0][1] == board[1][1] && board[1][1] == board[2][1] &&
            board[0][1] != '-') ||
           (board[0][2] == board[1][2] && board[1][2] == board[2][2] &&
            board[0][2] != '-') ||
           (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
            board[0][0] != '-') ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
            board[0][2] != '-');
}

int main() {
    char board[][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'},
    };

    printArray<char, 3, 3>(board);

    char current = 'X';

    int count = 0;
    while (true) {
        int row = 0;
        int col = 0;

        std::cout << "Pick a row (1, 2, 3): ";
        std::cin >> row;

        std::cout << "Pick a col (1, 2, 3): ";
        std::cin >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            std::cout << "Out of bounds budddy\n";
            continue;
        }

        if (board[row - 1][col - 1] == '-') {
            board[row - 1][col - 1] = current;
            count++;
        } else {
            std::cout << "That spot is taken! Try again\n";
            continue;
        }

        printArray<char, 3, 3>(board);

        if (checkForWin(board)) {
            std::cout << "Player " << current << " wins!\n";
            break;
        }

        current = current == 'O' ? 'X' : 'O';

        if (count >= 9) {
            std::cout << "There has been a tie!" << std::endl;
            break;
        }
    }

    return 0;
}