#include <iostream>
#include <cmath>
int main(){
  double x, p, A, B, z, C, D, K, Y;
  std::cout << "Введите x, p, z, D, K, C: ";
  std::cin >> x >> p >> z >> D >> K >> C;
  A = std::sin(x) - z;
  B = std::abs(p-x);
  Y = std::pow(A+B, 2) - (K/(C*D));
  std::cout << "Y = " << Y << std::endl;
  return 0;
}
  