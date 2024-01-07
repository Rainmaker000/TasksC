#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool checkBrackets(std::string &input) {
    int roundBrackets = 0;
    int squareBrackets = 0;

    for (char c : input) {
        if (c == '(') roundBrackets++;
        else if (c == ')') roundBrackets--;
        else if (c == '[') squareBrackets++;
        else if (c == ']') squareBrackets--;
    }

    return roundBrackets == 0 && squareBrackets == 0;
}

    std::string findLongestWord(std::string &input) {
    std::string longestWord;
    std::string currentWord;
    
    for (char c : input) {
        if (std::isalpha(c)) {
            currentWord += c;
        }
        else {
            if (!currentWord.empty() && currentWord.length() > longestWord.length()) {
                longestWord = currentWord;
            }
            currentWord.clear();
        }
    }

    if (!currentWord.empty() && currentWord.length() > longestWord.length()) {
        longestWord = currentWord;
    }

    return longestWord;
}

void removeLatinWords(std::string &input) {
    std::string result;
    std::string currentWord;

    for (char c : input) {
        if (std::isalpha(c)) {
            currentWord += c;
        }
        else {
            if (currentWord.empty() || !std::all_of(currentWord.begin(), currentWord.end(), isalpha)) {
                result += currentWord;
            }
            currentWord.clear();
            result += c;
        }
    }

    if (!currentWord.empty() && !std::all_of(currentWord.begin(), currentWord.end(), isalpha)) {
        result += currentWord;
    }

    input = result;
}

int main() {
    std::string input;
    std::cout << "Введіть текстовий рядок: ";
    std::getline(std::cin, input);

    if (checkBrackets(input)) {
        std::cout << "Кількість відкритих і закритих дужок співпада." << std::endl;
    } else {
        std::cout << "Кількість відкритих і закритих дужок не співпада." << std::endl;
    }

    std::string longestWord = findLongestWord(input);
    if (!longestWord.empty()) {
        std::cout << "Найдовше слово: " << longestWord << std::endl;
    } else {
        std::cout << "Текст не містить слів." << std::endl;
    }

    removeLatinWords(input);
    std::cout << "Текст після видалення слів із латинських літер: " << input << std::endl;

    return 0;
}

