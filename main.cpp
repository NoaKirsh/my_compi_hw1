#include <iostream>
#include <stdio.h>
#define watch(x) #x

int main_tt() {
    std::cout << "Hello, World!" << std::endl;
    int x = 3;
    std::cout << watch(x) << std::endl;
    return 0;
}