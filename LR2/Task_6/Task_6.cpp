#include <iostream>
#include <cmath>
int main(){
  double x, k, A, B, z, C, D, Y;
  std::cout << "Введите x, k, z, D, C: ";
  std::cin >> x >> k >> z >> D >> C;
  A = log(x) - k;
  B = sqrt(z);
  Y = pow(D, 2) + (pow(C, 2)/(0.75*A)) + B;
  std::cout << "Y = " << Y << std::endl;
  return 0;
}
  