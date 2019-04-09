#include <iostream>
#include "scanner/scaner.h"

int main() {
    Scanner* scan = new Scanner("../src/resources/code.txt");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}