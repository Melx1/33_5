#include <iostream>


bool cinFail () {
    if (std::cin.fail()) {
        std::cout << "Incorrect arguments." << std::endl;
        std::cin.clear();
        std::cin.sync();
        return true;
    }
    return false;
}

template <typename T>
void input (T array[8]) {
    std::cout << "Fill the array (8): ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> array[i];
        if (cinFail()) --i;
    }
}

template <typename T>
void average (T array[8]) {
    T sum {0};
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    std::cout << sum / 8;
}


int main () {
    float array[8] {0};
    input(array);
    average(array);
}