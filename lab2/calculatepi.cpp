#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

const int THROWS = 50'000'000;

struct coord {
    double x;
    double y;
};

int main() {
    int num_inside_circle {0};
    std::srand(std::time(nullptr));

    for (auto i = 0; i < THROWS; ++i) {
        coord c{(double)std::rand() / RAND_MAX, (double)std::rand() / RAND_MAX};
        double distance = std::sqrt(std::pow(c.x, 2) + std::pow(c.y, 2));
        if (distance < 1) {
            num_inside_circle++;
        }
    }

    std::cout << ((double)num_inside_circle / THROWS) * 4;
}
