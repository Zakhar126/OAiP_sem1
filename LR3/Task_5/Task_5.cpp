#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа приближенно находит корень уравнения f(x) = 0 методом перебора\n";
    cout << "Вариант 11: f(x) = sin(lg(x)) + x * cot(x^2) на [0.5; 1.5]\n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n\n";

    char repeat;

    while (true) {
        double a = 0.5;
        double b = 1.5;
        int n;

        while (true) {
            cout << "Введите количество частей, на которое разделить отрезок (n > 0): ";
            cin >> n;

            if (n > 0) {
                break;
            }

            cout << "Ошибка ввода \n";
        }

        double h = (b - a) / n;
        double min_x = a;

        double fx = sin(log10(a)) + a * (1.0 / tan(a * a));
        double min_f = fabs(fx);

        for (int i = 0; i <= n; i++) {
            double x = a + i * h;
            if (x > b) x = b;

            fx = sin(log10(x)) + x * (1.0 / tan(x * x));

            if (fabs(fx) < min_f) {
                min_f = fabs(fx);
                min_x = x;
            }
        }

        cout << "Приближенный корень x = " << min_x << endl;
        cout << "Минимальное значение |f(x)| = " << min_f << endl;
        cout << "-----------------------------------\n" << endl;

        while (true) {
            cout << "Если хотите завершить программу нажмите 1, если нет 2: ";
            cin >> repeat;

            if (repeat == '1' || repeat == '2') {
                break;
            }

            cout << "Ошибка ввода \n";
        }

        if (repeat == '1') {
            cout << "Программа завершена" << endl;
            break;
        }
    }

    return 0;
}