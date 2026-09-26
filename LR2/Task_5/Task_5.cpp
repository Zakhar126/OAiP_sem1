#include <iostream>

int main() {
    long double X, Y;
    std::cout << "Введите X, Y через пробел: ";
    std::cin >> X >> Y;
    if (X > Y) {
        std::cout << "X" << std::endl;
    }
    else {
        std::cout << "Y" << std::endl;
    }
    return 0;
}