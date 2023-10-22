//t32

#include <iostream>
#include <string>

int main() {
    std::string inputString;
    char charToDelete;

    std::cout << "Введіть рядок символів: ";
    std::getline(std::cin, inputString);

    std::cout << "Введіть символ для видалення: ";
    std::cin >> charToDelete; 
 
    for (size_t i = 0; i < inputString.length(); ++i) {
        if (inputString[i] == charToDelete) {
            inputString.erase(i, 1);
            --i;
        }
    }
    
    std::cout << "Результат: " << inputString << std::endl;

    return 0;
}
