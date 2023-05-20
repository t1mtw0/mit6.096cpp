#include <iostream>

template<class T> requires std::equality_comparable<T> T min(const T a, const T b) {
    return a < b ? a : b;
}

int main() {
    std::cout << min(2.0, 3.0) << "\n";
    std::cout << min("blah", "lah") << "\n";
}

#define min(x, y) (x < y ? x : y)
