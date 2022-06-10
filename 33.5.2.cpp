#include <iostream>
#include <exception>
#include <random>
#include <chrono>


struct WinException : std::exception {
    [[nodiscard]] const char* what() const noexcept override {return "You win!\n";}
};

struct LoseException : std::exception {
    [[nodiscard]] const char* what() const noexcept override {return "You lose!\n";}
};


int main() {
    constexpr size_t lakeSize = 9;
    constexpr size_t fishCount = 1;
    constexpr size_t shoesCount = 3;
    /*
    //foolproof
    if (lakeSize < fishCount + shoesCount) {
        return -1;
    }
    */

    char lake[lakeSize] {0};
    std::mt19937 randGenerator (std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> Rand(0, lakeSize-1);

    //supply fish
    for (int i = 0; i < fishCount; ) {
        int field = Rand(randGenerator);
        if (lake[field] == 0) {
            lake[field] = 1;
            ++i;
        }
    }

    //supply shoes
    for (int i = 0; i < shoesCount; ) {
        int field = Rand(randGenerator);
        if (lake[field] == 0) {
            lake[field] = 2;
            ++i;
        }
    }

    //fishing
    std::cout << "You need to catch fish in the " << lakeSize << "-sector lake." << std::endl;
    try {
        while (true) {
            int field;
            std::cin >> field;
            if (field < 1 or field > lakeSize) {
                std::cout << "Incorrect sector." << std::endl;
                std::cin.clear();
                continue;
            }
            else if (lake[field-1] == 1) throw WinException();
            else if (lake[field-1] == 2) throw LoseException();
            std::cout << "Empty..." << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}
