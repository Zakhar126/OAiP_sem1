#include <iostream>
int main(){
    int h1, h2, min1, min2, s, t1, t2;
    std::cout << "Введите h1, h2, min1, min2: ";
    std::cin >> h1 >> h2 >> min1 >> min2;
    h2 = h2 < h1 ? h2 + 24 : h2;
    t1 = h1 * 60 + min1;
    t2 = h2 * 60 + min2;
    s = t2 - t1;
    std::cout << s/60 << "h " << s % 60 << "min" << std::endl;
    return 0;
}

