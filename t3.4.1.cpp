#include <iostream>

using namespace std;

int main() {

    int N;
    cout << "Введіть розмір матриці NxN: ";
    cin >> N;
    
    int **matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int k = -1;
    for (int i = 0; i < N; ++i) {
        bool match = true;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                match = false;
                break;
            }
        }
        if (match) {
            k = i;
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < 0) {
                for (int l = 0; l < N; ++l) {
                    sum += matrix[i][l];
                }
                break;
            }
        }
    }

    cout << "k: " << k << endl;
    cout << "Сума елементів в рядках із від'ємними елементами: " << sum << endl;

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

