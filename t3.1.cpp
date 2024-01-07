#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cout << "Введіть розмір масиву: ";
    cin >> N;
    cout << "Введіть елементи масиву: ";
    vector<double> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    double sum_positive = 0;
    double product = 1;
    int max_abs_idx = 0;
    int min_abs_idx = 0;

    for(int i = 0; i < N; i++) {
        if(arr[i] > 0) {
            sum_positive += arr[i];
        }

        if(abs(arr[i]) > abs(arr[max_abs_idx])) {
            max_abs_idx = i;
        }

        if(abs(arr[i]) < abs(arr[min_abs_idx])) {
            min_abs_idx = i;
        }
    }

    if(max_abs_idx > min_abs_idx) {
        for(int i = min_abs_idx + 1; i < max_abs_idx; i++) {
            product *= arr[i];
        }
    }

    cout << "Сума позитивних елементів масиву: " << sum_positive << endl;
    cout << "Добуток елементів між мінімальним та максимальним(за модулем): " << product << endl;

    sort(arr.begin(), arr.end(), std::greater<double>());

    cout << "Елементи масиву за спаданням: ";
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
} 
