#include <iostream>
#include <cmath>
int main(){
  double x, p, h, A, B, C, D, K, Y;
  std::cout << "Введите x, p, h, K, C, D: ";
  std::cin >> x >> p >> h >> K >> C >> D;
  A = x - p;
  B = log(h);
  Y = 0.78 * B + pow(A, 3)/(K*C*D);
  std::cout << "Y = " << Y << std::endl;
  return 0;
}