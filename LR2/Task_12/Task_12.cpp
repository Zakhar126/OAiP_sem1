#include <iostream>
#include <cmath>
int main(){
    int a, b, c;
    double x1, x2, x3, x4, t1, t2, D;
    std::cout << "Введите a, b, c: ";
    std::cin >> a >> b >> c;
    // t = x ^ 2, получаем обычное квадратное уравнение
    D = b*b - 4*a*c;
    if(D>=0){
        t1 = (-b + sqrt(D))/(2*a);
        t2 = (-b - sqrt(D))/(2*a);
        if(t1>=0 || t2>=0){
            x1 = sqrt(t1);
            x2 = -x1;
            x3 = sqrt(t2);
            x4 = -x3;
            std::cout << "Корни уравнения: " << x1 << " " << x2 << " " << x3 << " " << x4;
        }
        else{ // t - квадрат, поэтому не может быть < 0
            std::cout << "Корней нет"; 
        }
    }else{
        std::cout << "Корней нет";
    }
    return 0;
}