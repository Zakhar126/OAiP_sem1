#include <iostream>
#include <cmath>

int main(){
  double A, B, C, D, K, p, x, Y;
  std::cout << "Введите x, p, K, C, D: ";
  std::cin >> x >> p >> K >> C >> D;
  A = x + sin(p);
  B = exp(K);
  Y = 1 + (pow(K, 2)/(2*A*B)) -B + (D*C);
  std::cout << "Y = " << Y << std::endl;
  return 0;
}