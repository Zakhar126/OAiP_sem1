#include <iostream>
#include <cmath>
int main(){
  double A, B, D, C, x, y, K, z, T;
  std::cout << "Введите x, y, z, K, C, D: ";
  std::cin >> x >> y >> z >> K >> C >> D;
  B = sqrt(z);
  A = x - y;
  T = cos(x) + pow(A, 2)/(K - (C*D)) - B;
  std::cout << "T = " << T << std::endl;
  return 0;
}