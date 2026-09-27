#include <iostream>
#include <cmath>
int main(){
  double x, d, A, B, C, K, Y;
  std::cout << "Введите x, d, K, C: ";
  std::cin >> x >> d >> K >> C;
  A = log10(x);
  B = x + exp(d);
  Y = A+B - (C*C)/K;
  std::cout << "Y = " << Y << std::endl;
  return 0;
}