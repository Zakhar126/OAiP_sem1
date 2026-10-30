#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа определяет минимальное значение из величин a=sinx, b=cosx, c=ln|x| \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        double x;
        cout << "Введите значение x: ";
        cin >> x;

        if (x == 0) {
            cout << "Ошибка: при x = 0 функция ln|x| не определена (логарифм нуля).\n";
            continue;
        }

        double a = sin(x);
        double b = cos(x);
        double c = log(abs(x));

        cout << "a = sin(x) = " << a << endl;
        cout << "b = cos(x) = " << b << endl;
        cout << "c = ln|x| = " << c << endl;

        double min_v = a;

        if (b < min_v) {
            min_v = b;
        }
        if (c < min_v) {
            min_v = c;
        }

        cout << "Минимальное значение: " << min_v << endl;

        char repeat;
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