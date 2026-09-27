#include <iostream>
#include <cmath>
int main(){
  double x, p, A, B, z, C, D, K, Y;
  std::cout << "Введите x, p, z, D, K, C: ";
  std::cin >> x >> p >> z >> D >> K >> C;
  A = sin(x) - z;
  B = abs(p-x);
  Y = pow(A+B, 2) - (K/(C*D));
  std::cout << "Y = " << Y << std::endl;
  return 0;
}
  