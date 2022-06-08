#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <stdexcept>


class Basket {
public:
    void add (std::string& _article, int _number) {
        if (_number <= 0) {
            throw std::invalid_argument ("Incorrect number");
        }
        try {
            myBasket.at(_article) += _number;
            return;
        }
        catch (const std::out_of_range& oor){
            myBasket.emplace(_article, _number);
        }
    }

    void remove (std::string& _article, int _number) {
        auto basketArticle = myBasket.find(_article);
        if (basketArticle == myBasket.end() or _number < 0 or _number > basketArticle->second) {
            throw std::invalid_argument ("The article not found or incorrect the number");
        }
        basketArticle->second -= _number;
        if (basketArticle->second == 0) {
            myBasket.erase(basketArticle);
        }
    }

    void show () noexcept {
        for (const auto& it : myBasket) {
            std::cout << std::setw(25) << std::left << it.first << it.second << std::endl;
        }
    }

private:
    std::map<std::string, int> myBasket;
};


int main() {
    Basket basket;
    std::cout << "Support command: add, remove, show, exit\nSyntax add/remove command: command article number\nExample: add apple 15\n" << std::endl;
    while (true) {
        std::string command;
        std::string article;
        std::string numberStr;
        int number;
        std::cin >> command;
        try {
            if (command == "add") {
                std::cin >> article >> numberStr;
                number = std::stoi(numberStr);
                basket.add(article, number);
            }
            else if (command == "remove") {
                std::cin >> article >> numberStr;
                number = std::stoi(numberStr);
                basket.remove(article, number);
            }
            else if (command == "show") {
                basket.show();
            }
            else if (command == "exit") {
                return 0;
            }
            else {
                throw std::runtime_error("Incorrect command");
            }
        }
        catch (const std::runtime_error& runtimeError) {
            std::cerr << runtimeError.what() << std::endl;
            std::cin.sync();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
