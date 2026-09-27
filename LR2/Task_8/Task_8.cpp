#include <iostream>

// Модуль числа: |x| = x, если x >= 0, иначе -x
double my_abs(double x) {
    if (x < 0) return -x;
    return x;
}

// Корень квадратный методом деления отрезка пополам.
// Ищем такое r, что r*r == x. Работаем на отрезке [l, r].
// Для x >= 1 корень лежит в [1, x], для 0 <= x < 1 — в [x, 1].
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
        double mid = l / 2 + r / 2; // защита от переполнения
        if (mid * mid <= x)  
            l = mid;  
        else  
            r = mid;  
    }  
    return l;  
}

// Арксинус через ряд Тейлора:
// arcsin(x) = x + (1/2)(x^3)/3 + (13)/(24)(x^5)/5 + ...
// Рекуррентно: a_{n+1} = a_n * x^2 * (2n+1)^2 / ((2n+2)*(2n+3))
// Сходится при |x| <= 1 (на границе — очень медленно).
double my_arcsin(double x) {
    const double eps = 1e-12L;
    double term = x;   // текущий член ряда, начинаем с a_0 = x
    double sum  = 0;   // накопленная сумма
    int n = 0;
    int safety = 1000000;   // защита от зацикливания
    while ((my_abs(term) > eps) && (safety-- > 0)) {  
        sum += term;  
        // переход к следующему члену: домножаем на x^2 * (2n+1)^2 / ((2n+2)*(2n+3))  
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

    // Площадь (векторное произведение)
    // S = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2  
    S = my_abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;  

    // Стороны
    // d = sqrt((x2-x1)^2 + (y2-y1)^2)  
    a = my_sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)); // BC  
    b = my_sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); // CA  
    c = my_sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // AB  
    std::cout << "Длины сторон a, b, c: " << a << " " << b << " " << c << std::endl;  

    // Высоты
    // h = 2S / сторона  
    ha = 2 * S / a;  
    hb = 2 * S / b;  
    hc = 2 * S / c;  
    std::cout << "Длины высот ha, hb, hc: " << ha << " " << hb << " " << hc << std::endl;  

    // Медианы  
    // m_a = 0.5 * sqrt(2b^2 + 2c^2 - a^2)  
    ma = my_sqrt(2 * b * b + 2 * c * c - a * a) / 2;  
    mb = my_sqrt(2 * a * a + 2 * c * c - b * b) / 2;  
    mc = my_sqrt(2 * a * a + 2 * b * b - c * c) / 2;  
    std::cout << "Длины медиан ma, mb, mc: " << ma << " " << mb << " " << mc << std::endl;  

    // Биссектрисы  
    // l_a = sqrt( b*c*((b+c)^2 - a^2) ) / (b+c)  
    la = my_sqrt(b * c * ((b + c) * (b + c) - a * a)) / (b + c);  
    lb = my_sqrt(a * c * ((a + c) * (a + c) - b * b)) / (a + c);  
    lc = my_sqrt(a * b * ((a + b) * (a + b) - c * c)) / (a + b);  
    std::cout << "Длины биссектрис la, lb, lc: " << la << " " << lb << " " << lc << std::endl;  

    // Радиусы  
    // R = a*b*c / (4S)  
    R = a * b * c / (4 * S);  
    // Полупериметр  
    p = (a + b + c) / 2;  
    // r = S / p  
    r = S / p;  
    std::cout << "Радиус вписанной r и описанной R окружностей: " << r << " " << R << std::endl;  

    // Углы  
    // По теореме косинусов: cos(A) = (b^2 + c^2 - a^2) / (2bc)  
    // A = arcsin(a / (2R)) для острых, A = pi - arcsin(a / (2R)) для тупых.  
    // Признак тупого угла: a^2 > b^2 + c^2.  
    sa = a / (2 * R); // sin(A)  
    sb = b / (2 * R); // sin(B)  
    sc = c / (2 * R); // sin(C)  

    // ограничиваем синус в [-1, 1] из-за погрешности  
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

    // Площадь и длина окружностей  
    // Круг: S = pi*r^2, L = 2*pi*r  
    Sr = PI * r * r;  
    Lr = 2 * PI * r;  
    SR = PI * R * R;  
    LR = 2 * PI * R;  
    std::cout << "Площадь и длина вписанной окружности: " << Sr << " " << Lr << std::endl;  
    std::cout << "Площадь и длина описанной окружности: " << SR << " " << LR << std::endl;  

    // Площадь 3 способами
    // Способ 1 — векторный (посчитан выше: S).  
    std::cout << "Площадь (векторная) = " << S << std::endl;  

    // Способ 2 — Герон: S = sqrt(p(p-a)(p-b)(p-c))  
    S_geron = my_sqrt(p * (p - a) * (p - b) * (p - c));  
    std::cout << "Площадь (Герон) = " << S_geron << std::endl; 

    // Способ 3 — через две стороны и угол: S = 0.5 * b * c * sin(A)  
    // sin(A) уже есть как sa.  
    S_angle = 0.5L * b * c * sa;   
    std::cout << "Площадь (через sin) = " << S_angle << std::endl;  

    // Периметр
    std::cout << "Периметр = " << 2 * p << std::endl;  

    return 0;  
}