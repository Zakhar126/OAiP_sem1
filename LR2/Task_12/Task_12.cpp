#include <iostream>
#include <cmath>

int main() {
    double p, q;
    std::cout << "Введите p, q : ";
    if (!(std::cin >> p >> q)) {
        std::cout << "Ошибка ввода " << std::endl;
        return 1;
    }

    double D = pow(p / 3.0, 3) + pow(q / 2.0, 2);

    if (D > 0) {
        double sqrt_D = sqrt(D);
        double x1 = cbrt(-q / 2.0 + sqrt_D) + cbrt(-q / 2.0 - sqrt_D);
        std::cout << "Один корень: x1 = " << x1 << std::endl;
    } 
    else if (D == 0) {
        double u = cbrt(-q / 2.0);
        std::cout << "Корни: x1 = " << 2 * u << " x2, x3 = " << -u << std::endl;
    } 
    else {
        double r = sqrt(-pow(p / 3.0, 3));
        double phi = acos(-q / (2.0 * r));

        double x1 = 2.0 * sqrt(-p / 3.0) * cos(phi / 3.0);
        double x2 = 2.0 * sqrt(-p / 3.0) * cos((phi + 2.0 * M_PI) / 3.0);
        double x3 = 2.0 * sqrt(-p / 3.0) * cos((phi + 4.0 * M_PI) / 3.0);

        std::cout << "Три разных корня:";
        std::cout << " x1 = " << x1 << " x2 = " << x2 << "x3 = " << x3 << std::endl;
    }

    return 0;
}