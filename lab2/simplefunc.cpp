#include <iostream>

void f(const int a = 5) {
    std::cout << a * 2 << "\n";
}

int a = 123;
int main() {
    f(1); // 2
    f(a); // 246
    int b = 3;
    f(b); // 6
    a = 4;
    f(a); // 8
    f(); // 10
}
