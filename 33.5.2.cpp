#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <random>
#include <chrono>
#include <string>


int main() {
    const size_t lakeSize = 9;
    const size_t fishCount = 1;
    const size_t shoesCount = 3;
    //foolproof
    if (lakeSize < fishCount + shoesCount) {
        return -1;
    }

    int lake[fishCount + shoesCount] {0};
    std::mt19937 randGenerator (std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> Rand(1, lakeSize);

    //supply fish
    for (int i = 0; i < fishCount; ) {
        int field = Rand(randGenerator);
        for (int j = 0; j <= i; ++j) {
            if (field == lake[j]) {
                break;
            }
            if (j == i) {
                lake[j] = field;
                ++i;
                break;
            }
        }
    }

    //supply shoes
    for (int i = 0; i < shoesCount; ) {
        int field = Rand(randGenerator);
        for (int j = 0; j <= fishCount + i; ++j) {
            if (field == lake[j]) {
                break;
            }
            if (j == fishCount + i) {
                lake[j] = field;
                ++i;
                break;
            }
        }
    }

    //fishing
    std::cout << "You need to catch fish in the lake." << std::endl;
    while (true) {
        int field;
        std::cin >> field;

    }
}
