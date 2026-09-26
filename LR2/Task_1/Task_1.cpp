#include <iostream>

int main() {
    long double x, y, f1, f2;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    y = x*x;
    std::cout << "Значение y: " << y << std::endl;
    f1 = 69*y+8;
    std::cout << "Значение f1: " << f1 << std::endl;
    f2 = (23*y+32)*x;
    std::cout << "Значение f2: " << f2 << std::endl;
    std::cout << "Значение первого выражения: " << f1+f2 << std::endl;
    std::cout << "Значение второго выражения: " << f1-f2 << std::endl;
    return 0;
}