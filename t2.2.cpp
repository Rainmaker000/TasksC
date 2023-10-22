//without func
#include <iostream>
#include <iomanip>

int main() {
    double a, b, c, x_start, x_end, h;
    
    std::cout << "Введіть значення a: ";
    std::cin >> a;
    std::cout << "Введіть значення b: ";
    std::cin >> b;
    std::cout << "Введіть значення c: ";
    std::cin >> c;
    std::cout << "Введіть початкове значення x: ";
    std::cin >> x_start;
    std::cout << "Введіть кінцеве значення x: ";
    std::cin >> x_end;
    std::cout << "Введіть крок h: ";
    std::cin >> h;

    std::cout << " x    |   F(x)   " << std::endl;
    std::cout << "----------------" << std::endl;

    for (double x = x_start; x <= x_end; x += h) {
        double result;
        if (x + 5 < 0 && c == 0) {
            result = 1 / (a * x - b);
        } else if (x + 5 > 0 && c != 0) {
            result = x - a / x;
        } else {
            result = 10 * x / c - 4;
        }

        std::cout << std::fixed << std::setprecision(2) << std::setw(3) << x << " | " << result << std::endl;
    }

    return 0;
}
