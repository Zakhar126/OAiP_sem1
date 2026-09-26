#include <iostream>
#include <cmath>
int main(){
  int n, m;
  double A, D, x, K, Y;
  std::cout << "Введите x, n, m, K: ";
  std::cin >> x >> n >> m >> K;
  D = tan(x);
  A = abs(n + m);
  Y = 1.29 + (K/A) + pow(D, 2);
  std::cout << "Y = " << Y << std::endl;
  return 0;
}