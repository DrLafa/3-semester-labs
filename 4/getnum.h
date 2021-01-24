#include <iostream>

namespace oop3 {
    template <typename T>
    T getNum() {
        T num = 0;
        if (std::cin.eof()){
          throw "EOF";
        }
        if (!(std::cin >> num)) {
            std::cin.clear();
            std::cin.ignore();
            throw std::invalid_argument("invalid input");
        }
        return num;
    }
}
