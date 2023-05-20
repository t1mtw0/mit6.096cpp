#include <iostream>

bool is_prime(int num);

int main() {
    // read a number from the user
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    // find first n primes
    int num { 1 };
    int found { 0 };
    while (found != n) {
        if (is_prime(num)) {
            std::cout << num << "\n";
            found++;
        }
        num++;
    }
}

bool is_prime(int num) {
    for (auto i = 2; i < num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
