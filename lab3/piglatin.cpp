#include <iostream>
#include <string>

const std::string VOWELS = "aeiou";

std::string pigLatinify(std::string str) {
    if (str.substr(0, 2) == "qu") {
        return str.substr(2) + str.substr(0, 2) + "ay";
    } else if (VOWELS.find(str[0]) != std::string::npos) {
        return str + "way";
    } else {
        return str.substr(1) + str[0] + "ay";
    }
}

int main() {
    std::cout << "Enter a word: ";
    std::string message;
    std::cin >> message;

    std::string pigLatinMessage = pigLatinify(message);
    std::cout << pigLatinMessage << "\n";
}
