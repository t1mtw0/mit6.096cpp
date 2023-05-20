#include <iostream>

int sum(const int nums...) {
    std::cout << nums;
    std::cout << nums;
    /*
    int sum {0};
    for (auto n : nums) {
        sum += n;
    }
    return sum;
    */
}

int main() {
    //std::cout << sum(1, 2, 3);
    sum(2, 3);
    return 0;
}
