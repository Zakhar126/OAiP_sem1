#include <iostream>
#include <cmath>

int main() {
    double a, b, c; 
    std::cout << "Введите a, b, c: ";
    std::cin >> a >> b >> c;
    if (a == 0) {
        std::cout << "a не может быть равен 0";
        return 0;
    }
    double D = b * b - 4 * a * c;

    if (D > 0) {
        double t1 = (-b + sqrt(D)) / (2 * a);
        double t2 = (-b - sqrt(D)) / (2 * a);
        bool hasRoots = false;
        std::cout << "Корни уравнения: ";
        if (t1 >= 0) {
            std::cout << sqrt(t1) << " " << -sqrt(t1) << " " << std::endl;
            hasRoots = true;
        }
        if (t2 >= 0 && t1 != t2) {
            std::cout << sqrt(t2) << " " << -sqrt(t2) << " " << std::endl;
            hasRoots = true;
        }
        if (!hasRoots) {
            std::cout << "Действительных корней нет (t1 и t2 < 0)" << std::endl;
        } 
        
    } else if (D == 0) {
        double t = -b / (2 * a);
        if (t > 0) {
            std::cout << "Корни уравнения: " << sqrt(t) << " " << -sqrt(t) << std::endl;
        } else if (t == 0) {
            std::cout << "Корень уравнения: 0" << std::endl;
        } else {
            std::cout << "Действительных корней нет (t < 0)" << std::endl;
        }
    } else {
        std::cout << "Корней нет (D < 0)" << std::endl;
    }

    return 0;
}