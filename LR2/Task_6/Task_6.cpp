#include <iostream>
#include <cmath>
int main(){
  double A, D, x, b, S;
 std::cout << "Ввести D, x: ";
 std::cin >> D >> x;
  b = x + D;
  A = D*x/b;
  S = (pow(A, 2) + b*cos(x))/(pow(D, 3) + (A + D - b));
  std::cout << "S = " << S;
  return 0;
}