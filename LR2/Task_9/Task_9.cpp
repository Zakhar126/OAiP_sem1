#include <iostream>
#include <cmath>

int main(){
    int n, z, a, b;
    double x, f, y;
    std::cout << "Введите n, z, a, b: ";
    std::cin >> n >> z >> a >> b;
    x = z > 0 ? (1.0 / (z * z + 2 * z)) : (1.0 - pow(z, 3));

    switch(n){
      case 1:
        f = 2.0 * x;
        break;
      case 2:
        f = pow(x, 3);
        break;
      case 3:
        f =  x/3.0;
        break;
      default:
        break;
    }

    y = (2.5 * a * exp(-3.0 * x) - 4.0 * b * x * x) / (log(std::abs(x)) + f);

    std::cout << "y = " << y << std::endl;

    return 0;
}