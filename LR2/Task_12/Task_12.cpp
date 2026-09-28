#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "Введите a, b, c:";
    std::cin >> a >> b >> c;
    if (a == 0) {
        std::cout << " a не равен 0.";
        return 0;
    }

    // 1. Решаем квадратное уравнение относительно t: a*t^2 + b*t + (c - 2a) = 0
    double D_t = b * b - 4 * a * (c - 2 * a);

    if (D_t < 0) {
        std::cout << "Нет действительных корней.";
        return 0;
    }

    double t1 = (-b + sqrt(D_t)) / (2 * a);
    double t2 = (-b - sqrt(D_t)) / (2 * a);
    bool hasRoots = false;

    // 2. Для t1 решаем уравнение: x^2 - t1*x + 1 = 0
    double D_x1 = t1 * t1 - 4;
    if (D_x1 > 0) {
        std::cout << " x1 = " << (t1 + sqrt(D_x1)) / 2;
        std::cout << " x2 = " << (t1 - sqrt(D_x1)) / 2;
        hasRoots = true;
    } else if (D_x1 == 0) {
        std::cout << " x1 = " << t1 / 2 ;
        hasRoots = true;
    }

    // 3. Для t2 (если оно отличается от t1) решаем уравнение: x^2 - t2*x + 1 = 0
    if (D_t > 0) { 
        double D_x2 = t2 * t2 - 4;
        if (D_x2 > 0) {
            std::cout << " x3 = " << (t2 + sqrt(D_x2)) / 2;
            std::cout << " x4 = " << (t2 - sqrt(D_x2)) / 2;
            hasRoots = true;
        } else if (D_x2 == 0) {
            std::cout << " x3 = " << t2 / 2;
            hasRoots = true;
        }
    }

    if (!hasRoots) {
        std::cout << "Нет действительных корней.";
    }

    return 0;
}