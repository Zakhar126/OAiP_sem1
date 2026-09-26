#include <iostream>

int main() {
    long double x, y, f1, f2;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    y = x*x;
    f1 = 69*y+8;
    f2 = (23*y+32)*x;
    std::cout << "Значение первого выражения: " << f1+f2 << std::endl;
    std::cout << "Значение второго выражения: " << f1-f2 << std::endl;
    return 0;
}