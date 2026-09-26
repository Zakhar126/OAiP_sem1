#include <iostream>
#include <cmath>

int main(){
  double B, C, D, K, p, n, x, Q;
  std::cout << "Введите p, n, x, D, K: ";
  std::cin >> p >> n >> x >> D >> K;
  B = cos(x);
  C = p - n;
  Q = pow(B, 2)/(K*D) + (B*pow(C, 3));
  std::cout << "Q = " << Q << std::endl;
  return 0;
}