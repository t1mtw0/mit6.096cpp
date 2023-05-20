#include <iostream>

int main() {
    // Ask for number of integers
    int length;
    std::cout << "Please enter the number of integers in the list\n";
    std::cin >> length;

    // Get integers from user based on length
    std::cout << "Please enter the numbers\n";
    double mean { 0 };
    int min, max;
    for (auto i = 0; i < length; ++i) {
        int num;
        std::cin >> num;
        mean += num;
        if (i == 0) {
            min = num;
            max = num;
        } else {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }

    }
    mean /= length;
    int range { max - min };

    std::cout << "Mean: " << mean << "\n";
    std::cout << "Max: " << max << "\n";
    std::cout << "Min: " << min << "\n";

    std::cout << "Range: " << range << "\n";
}
