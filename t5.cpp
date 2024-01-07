#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

bool isVowel(char ch) {
    ch = std::tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

bool isConsonant(char ch) {
    ch = std::tolower(ch);
    return std::isalpha(ch) && !isVowel(ch);
}

void copyFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Failed to open files" << std::endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        output.put(ch);
    }
}

int countWordsStartingWithVowel(const std::string& inputFile) {
    std::ifstream input(inputFile);

    if (!input.is_open()) {
        std::cerr << "Failed to open file: " << inputFile << std::endl;
        return -1;
    }

    int count = 0;
    std::string word;
    while (input >> word) {
        if (!word.empty() && std::isalpha(word[0]) && isVowel(word[0])) {
            count++;
        }
    }

    return count;
}

int countWordsWithOddConsonants(const std::string& inputFile) {
    std::ifstream input(inputFile);

    if (!input.is_open()) {
        std::cerr << "Failed to open file: " << inputFile << std::endl;
        return -1;
    }

    int count = 0;
    std::string word;
    while (input >> word) {
        if (!word.empty() && std::isalpha(word[0])) {
            int consonantCount = 0;
            for (char ch : word) {
                if (isConsonant(ch)) {
                    consonantCount++;
                }
            }

            if (consonantCount > 0 && consonantCount % 2 != 0) {
                count++;
            }
        }
    }

    return count;
}

void removeNumbersFromFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile, std::ios::app);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Failed to open files." << std::endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        if (!std::isdigit(ch)) {
            output.put(ch);
        }
    }

    input.close();
    output.close();
}

int main() {
    const std::string inputFile = "C:\\Users\\home\\Desktop\\lab.bp\\input.txt";
    const std::string outputFile = "C:\\Users\\home\\Desktop\\lab.bp\\output.txt";

    copyFile(inputFile, outputFile);

    int vowelWordsCount = countWordsStartingWithVowel(inputFile);
    int oddConsonantWordsCount = countWordsWithOddConsonants(inputFile);

    std::ofstream output(outputFile, std::ios::app);
    output << "Number of words starting with a vowel: " << vowelWordsCount << std::endl;
    output << "Number of words with an odd number of consonant letters: " << oddConsonantWordsCount << std::endl;

    output.close();

    removeNumbersFromFile(inputFile, outputFile);

    return 0;
}
