#include <iostream>

// double avg(int data[], int size) {
//     double sum = 0;
//     for (int i = 0; i < size; i++) {
//         sum += data[i];
//     }
//     return sum / size;
// }

void printBoard(char* board, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << board[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T, size_t rows, size_t cols>
void printArray(T(data)[rows][cols]) {
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            std::cout << data[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    char board[][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'},
    };
    char board2[][4] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'},
    };

    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof board[0][0];

    std::cout << rows << " " << cols << std::endl;

    board[0][0] = 'x';
    board[0][1] = 'o';
    board[1][0] = 'x';
    board[0][2] = 'o';
    board[2][0] = 'x';

    printArray<char, 3, 3>(board);
    printArray<char, 3, 4>(board2);

    return 0;
}