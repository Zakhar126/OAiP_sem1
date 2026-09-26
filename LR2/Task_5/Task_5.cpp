#include <iostream>

int main() {
    long double X, Y;
    std::cout << "Введите X, Y через пробел: ";
    std::cin >> X >> Y;
    bool l = X > Y;
    std::cout << (l == 1 ? 'X' : 'Y') << std::endl;
    return 0;
}