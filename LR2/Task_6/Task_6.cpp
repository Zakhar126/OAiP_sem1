#include <iostream>
#include <cmath>
int main(){
  int A, Y, C, x, y;
  double D, K, S;
  std::cout << "Введите x, y, C, K: ";
  std::cin >> x >> y >> C >> K;
  A = x + y;
  D = abs(C-A);
  S = 10.1 + (A/C) + D/pow(K, 2);
  std::cout << "S = " << S << std::endl;
  return 0;
}
  