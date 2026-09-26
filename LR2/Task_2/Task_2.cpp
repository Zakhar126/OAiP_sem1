#include <iostream>

int main() {
    long double x, y, z;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;
    std::cout << "Введите значение z: ";
    std::cin >> z;
    if (x + y - z > 0 && y + z - x > 0 && z + x - y > 0)
        std::cout << "Треугольник существует \n";
    else 
        std::cout << "Треугольника не существует \n";
    return 0;
}