#include <iostream>

double my_abs(double x) {
    if (x < 0) return -x;
    return x;
}
double my_sqrt(double x) {
    const double eps = 1e-12L;
    double l, r;  
    if (x >= 1) {
        l = 1; 
        r = x; 
    }  
    else {
        l = x;
        r = 1; 
    }  

    while (r - l > eps) {  
        double mid = l / 2 + r / 2;
        if (mid * mid <= x)  
            l = mid;  
        else  
            r = mid;  
    }  
    return l;  
}

double my_arcsin(double x) {
    const double eps = 1e-12L;
    double term = x;
    double sum  = 0;
    int n = 0;
    int safety = 1000000;
    while ((my_abs(term) > eps) && (safety-- > 0)) {  
        sum += term;  
        term *= x * x * (2 * n + 1) * (2 * n + 1)  
                / ((2 * n + 2) * (2 * n + 3));  
        n++;  
    }  
    return sum;  
}

int main() {
    const double PI = 3.14;
    double x1, y1, x2, y2, x3, y3, S, a, b, c, ha, hb, hc, ma, mb, mc, la, lb, lc, R, p, r, rada, radb, radc, sa, sb, sc, degA, degB, degC, Sr, Lr, SR, LR, S_geron, S_angle;  
    std::cout << "Введите x1, y1, x2, y2, x3, y3 через пробел: ";  
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;  

    // Площадь
    S = my_abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;  

    // Стороны
    a = my_sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)); // BC  
    b = my_sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); // CA  
    c = my_sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // AB  
    std::cout << "Длины сторон a, b, c: " << a << " " << b << " " << c << std::endl;  

    // Высоты
    ha = 2 * S / a;  
    hb = 2 * S / b;  
    hc = 2 * S / c;  
    std::cout << "Длины высот ha, hb, hc: " << ha << " " << hb << " " << hc << std::endl;  

    // Медианы  
    ma = my_sqrt(2 * b * b + 2 * c * c - a * a) / 2;  
    mb = my_sqrt(2 * a * a + 2 * c * c - b * b) / 2;  
    mc = my_sqrt(2 * a * a + 2 * b * b - c * c) / 2;  
    std::cout << "Длины медиан ma, mb, mc: " << ma << " " << mb << " " << mc << std::endl;  

    // Биссектрисы  
    la = my_sqrt(b * c * ((b + c) * (b + c) - a * a)) / (b + c);  
    lb = my_sqrt(a * c * ((a + c) * (a + c) - b * b)) / (a + c);  
    lc = my_sqrt(a * b * ((a + b) * (a + b) - c * c)) / (a + b);  
    std::cout << "Длины биссектрис la, lb, lc: " << la << " " << lb << " " << lc << std::endl;  

    // Радиусы   
    R = a * b * c / (4 * S);  
    // Полупериметр  
    p = (a + b + c) / 2;  
    // r = S / p  
    r = S / p;  
    std::cout << "Радиус вписанной r и описанной R окружностей: " << r << " " << R << std::endl;  

    // Углы  
    sa = a / (2 * R); // sin(A)  
    sb = b / (2 * R); // sin(B)  
    sc = c / (2 * R); // sin(C)  

    if (sa >  1) sa =  1;  if (sa < -1) sa = -1;  
    if (sb >  1) sb =  1;  if (sb < -1) sb = -1;  
    if (sc >  1) sc =  1;  if (sc < -1) sc = -1;  

    rada = (a * a <= b * b + c * c) ? my_arcsin(sa) : PI - my_arcsin(sa);  
    radb = (b * b <= a * a + c * c) ? my_arcsin(sb) : PI - my_arcsin(sb);  
    radc = (c * c <= b * b + a * a) ? my_arcsin(sc) : PI - my_arcsin(sc);  

    degA = rada / PI * 180;  
    degB = radb / PI * 180;  
    degC = radc / PI * 180;  
    std::cout << "Углы в градусах A, B, C: " << degA << " " << degB << " " << degC << std::endl;  
    std::cout << "Углы в радианах A, B, C: " << rada << " " << radb << " " << radc << std::endl;  

    // Площадь и длина окружности 
    Sr = PI * r * r;  
    Lr = 2 * PI * r;  
    SR = PI * R * R;  
    LR = 2 * PI * R;  
    std::cout << "Площадь и длина вписанной окружности: " << Sr << " " << Lr << std::endl;  
    std::cout << "Площадь и длина описанной окружности: " << SR << " " << LR << std::endl;  

    // Способ 1 — векторный   
    std::cout << "Площадь (векторная) = " << S << std::endl;  

    // Способ 2 — Герон 
    S_geron = my_sqrt(p * (p - a) * (p - b) * (p - c));  
    std::cout << "Площадь (Герон) = " << S_geron << std::endl; 

    // Способ 3 — через две стороны и угол 
    S_angle = 0.5L * b * c * sa;   
    std::cout << "Площадь (через sin) = " << S_angle << std::endl;  

    // Периметр
    std::cout << "Периметр = " << 2 * p << std::endl;  

    return 0;  
}