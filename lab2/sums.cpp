#include <iostream>

// 4.1

int sum(const int a, const int b) {
    return a + b;
}

double sum(const double a, const double b) {
    return a + b;
}

int main() {
    std::cout << sum(1, 2) << "\n";
    std::cout << sum(1.2, 3.4) << "\n";
    // syntax error
    std::cout << sum(1, 10.0) << "\n";
}
