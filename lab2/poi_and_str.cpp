#include <iostream>

int strlen(char *str) {
    int len = 0;
    while (*(str + len) != NULL) {
        len++;
    }
    return len;
}

void swap(int& num1, int& num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void swapptrs(int **ptr1, int **ptr2) {
    int *tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

int main() {
    char *message = "blah";
    int len = strlen(message);
    std::cout << len << "\n";

    int num1 = 2;
    int num2 = 5;
    swap(num1, num2);
    std::cout << num1 << " " << num2 << "\n";

    int *ptr1 = &num1, *ptr2 = &num2;
    swapptrs(&ptr1, &ptr2);
    std::cout << *ptr1 << " " << *ptr2 << "\n";

    // 7.5
    std::cout << "\n";
    char *oddOrEven = "Never odd or even";
    char *nthCharPtr = &oddOrEven[5];
    nthCharPtr -= 2;
    std::cout << *nthCharPtr << "\n";
    char **pointerPtr = &nthCharPtr;
    std::cout << **pointerPtr << "\n";
    nthCharPtr = oddOrEven + 1;
    std::cout << nthCharPtr - oddOrEven;
}
