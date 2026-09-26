#include <iostream>

int main() {
    long double n, b1, S;
    n = 27;
    std::cout << "Введите первый член геометрической прогрессии b1: ";
    std::cin >> b1;
    S = b1 * (1 + 1/n);
    std::cout << "Сумма всех членов убывающей геометрической прогрессии: " << S << std::endl; 
    return 0;
}