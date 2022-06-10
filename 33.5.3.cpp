#include <iostream>
#include <vector>
#include <string>


template <typename KeyType, typename DataType>
class Registry {
public:
    void add (const KeyType& _key, const DataType& _data) {
        data.emplace_back(_key, _data);
    }

    void find (const KeyType& _key, std::vector< std::pair<KeyType, DataType>* >& _resultVector) {
        for (auto& item : data) {
            if (item.first == _key) {
                _resultVector.push_back(&item);
            }
        }
    }

    void erase (KeyType& _key) {
        std::erase_if(data, [&_key](std::pair<KeyType, DataType> item) {return item.first == _key;});
    }

    void show () {
        for (auto& item : data) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }

private:
    std::vector<std::pair<KeyType, DataType>> data;
};

bool cinFail () {
    if (std::cin.fail()) {
        std::cout << "Incorrect arguments." << std::endl;
        std::cin.clear();
        std::cin.sync();
        return true;
    }
    return false;
}

template <typename KeyType, typename DataType>
void interface (Registry<KeyType, DataType>& _registry) {
    std::string command;
    KeyType key;
    DataType data;
    while (true) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> key >> data;
            if (cinFail()) continue;
            _registry.add(key, data);
        } else if (command == "remove") {
            std::cin >> key;
            if (cinFail()) continue;
            _registry.erase(key);
        } else if (command == "print") {
            _registry.show();
        } else if (command == "find") {
            std::cin >> key;
            if (cinFail()) continue;
            std::vector<std::pair<KeyType, DataType> *> result;
            _registry.find(key, result);
            for ( const auto& item : result) {
                std::cout << item->second << std::endl;
            }
        } else if (command == "exit") {
            return;
        } else {
            std::cout << "Incorrect command" << std::endl;
            std::cin.clear();
        }
    }
}


int main () {
    Registry<std::string, int> registry;
    interface<std::string, int> (registry);
}