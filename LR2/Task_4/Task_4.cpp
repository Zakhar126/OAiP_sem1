#include <iostream>

int main() {
    long long int X, Y, X1, Y1;
    long double A, B, C, K, A1, B1, C1;
    std::cout << "Введите числа X, Y, A, B, C, K через пробел: ";
    std::cin >> X >> Y >> A >> B >> C >> K;
    if (X > Y) {X1 = X;} else {X1=0;}
    if (Y > X) {Y1 = Y;} else {Y1=0;}
    if (A > B && A > C) {A1 = A - K;} else {A1 = A;}
    if (B > C && B > A) {B1 = B - K;} else {B1 = B;}
    if (C > A && C > B) {C1 = C - K;} else {C1 = C;}
    X = X1;
    Y = Y1;
    A = A1;
    B = B1;
    C = C1;
    std::cout << X << " " << Y << " " << A << " " << B << " " << C << std::endl;
    return 0;
}