#include <iostream>
#include "dialog.h"
using namespace oop4;
int main() {
    try {
        dialog();
    }
    catch (std::exception &ex) {
        std::cout << "Exception detected: " << ex.what() << std::endl;
    }
}
