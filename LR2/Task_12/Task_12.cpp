#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "Введите a, b, c:";
    std::cin >> a >> b >> c;
    if (a == 0) {
        std::cout << " a не должен быть равен 0";
        return 0;
    }
    
    double D_t = b * b - 4 * a * (c - 2 * a);

    if (D_t < 0) {
        std::cout << "Нет действительных корней" << std::endl;
        return 0;
    }

    double t1 = (-b + sqrt(D_t)) / (2 * a);
    double t2 = (-b - sqrt(D_t)) / (2 * a);
    bool hasRoots = false;

    double D_1 = t1 * t1 - 4;
    if (D_1 > 0) {
        std::cout << " x1 = " << (t1 + sqrt(D_1)) / 2 << std::endl;
     std::cout << " x2 = " << (t1 - sqrt(D_1)) / 2 << std::endl;
        hasRoots = true;
    } else if (D_1 == 0) {
        std::cout << " x1 = " << t1 / 2 << std::endl;
        hasRoots = true;
    }

    if (D_t > 0) { 
        double D_2 = t2 * t2 - 4;
        if (D_2 > 0) {
            std::cout << " x3 = " << (t2 + sqrt(D_2)) / 2 << std::endl;
            std::cout << " x4 = " << (t2 - sqrt(D_2)) / 2 << std::endl;
            hasRoots = true;
        } else if (D_2 == 0) {
            std::cout << " x3 = " << t2 / 2 << std::endl;
            hasRoots = true;
        }
    }

    if (!hasRoots) {
        std::cout << "Нет действительных корней" << std::endl;
    }

    return 0;
}