#include <iostream>
#include <cmath>

int main() {
    int x1, y1, r1, x2, y2, r2;
    double h;
    std::cout << "Введите x1, y1, r1, x2, y2, r2: ";
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    h = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); // находим как гипотенузу
    if( r2 > r1 + h ){
        std::cout << "Да" << std::endl; //1 окружность внутри второй
    }else if( r1 > r2 + h ){
        std::cout << "Да, но справедливо обратное для двух фигур" << std::endl; //2 окружность внутри первой
    }else if( h <= r1 + r2 ){
        std::cout << "Фигуры пересекаются" << std::endl; 
    }else{
        std::cout << "Ни одно условие не выполнено" << std::endl;
    }
    return 0;
}