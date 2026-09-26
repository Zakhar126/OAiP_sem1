#include <iostream>
#include <cmath>
int main(){
  double x, k, A, B, z, C, D, Y;
  std::cout << "Ввести x, k, z, D, C: ";
  std::cin >> x >> k >> z >> D >> C;
  A = std::log(x) - k;
  B = std::sqrt(z);
  Y = std::pow(D, 2) + (std::pow(C, 2)/(0.75*A)) + B;
  std::cout << "Y = " << Y << std::endl;
  return 0;
}
  