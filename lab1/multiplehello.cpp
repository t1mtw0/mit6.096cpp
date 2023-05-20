#include <iostream>

void multiple_hello(int n);

int main() {
    multiple_hello(5);
}

void multiple_hello(int n) {
    int i { 0 };
    do {
        std::cout << "Hello, World!\n";
        i++;
    }
    while (i < n);
}
