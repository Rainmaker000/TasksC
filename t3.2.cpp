#include <iostream>
#include <vector>

int countNonzeroColumns(std::vector<std::vector<int>>& matrix) {
    int numColumns = matrix[0].size();
    int count = 0;

    for (int j = 0; j < numColumns; ++j) {
        bool hasZero = false;
        for (auto& row : matrix) {
            if (row[j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
   
    return count;
}

int main() {
    int numRows, numColumns;

    std::cout << "Введіть кількість рядків: ";
    std::cin >> numRows;

    std::cout << "Введіть кількість стовпців: ";
    std::cin >> numColumns;

    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numColumns));

    for (int i = 0; i < numRows; ++i) {
        std::cout << "Введіть елементи рядка " << i + 1 << ": ";
        for (int j = 0; j < numColumns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int nonzeroColumns = countNonzeroColumns(matrix);
    std::cout << "Кількість стовпців без нульових елементів: " << nonzeroColumns << std::endl;
}
