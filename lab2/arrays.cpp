#include <iostream>

const int WIDTH = 2;
const int LENGTH = 5;

void printArray(const int arr[], const int len) {
    for (auto i = 0; i < len; ++i) {
        std::cout << arr[i];
        if (i < len - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

void reverseArray(int arr[], const int len) {
    for (auto i = 0; i < len / 2; ++i) {
        int indexFromEnd = len - i - 1;
        int tmp = *(arr + i);
        arr[i] = *(arr + indexFromEnd);
        *(arr + indexFromEnd) = tmp;
    }
}

void transpose(const int input[][LENGTH], int output[][WIDTH]) {
    for (auto i = 0; i < WIDTH; ++i) {
        for (auto j = 0; j < LENGTH; ++j) {
            output[j][i] = input[i][j];
        }
    }
}

int ret_transpose(const int input[][LENGTH]) {
    int output[LENGTH][WIDTH];
    for (auto i = 0; i < WIDTH; ++i) {
        for (auto j = 0; j < LENGTH; ++j) {
            output[j][i] = input[i][j];
        }
    }
    return output;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    printArray(arr, 4);

    reverseArray(arr, 4);
    printArray(arr, 4);

    int arr1[WIDTH][LENGTH] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int arr2[LENGTH][WIDTH];
    //transpose(arr1, arr2);
    //int output[LENGTH][WIDTH] = ret_transpose(arr1);

    printArray(arr2[0], 2);
}
