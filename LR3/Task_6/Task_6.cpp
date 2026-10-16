#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа определяет минимальное значение из величин a=sinx, b=cosx, c=ln|x| \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        double x;
        cout << "\nВведите значение x: ";
        
        if (!(cin >> x)) {
            cout << "Ошибка ввода. Пожалуйста, введите число.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue; 
        }

        if (x == 0) {
            cout << "Ошибка: при x = 0 функция ln|x| не определена (логарифм нуля).\n";
        } else {
            double a = sin(x);
            double b = cos(x);
            double c = log(abs(x));

            cout << "a = sin(x) = " << a << endl;
            cout << "b = cos(x) = " << b << endl;
            cout << "c = ln|x|  = " << c << endl;

            double min_value = a;

            if (b < min_value) {
                min_value = b;
            }
            if (c < min_value) {
                min_value = c;
            }

            cout << "Минимальное значение: " << min_value << endl;
        }

        char user_choice;
        while (true) {
            cout << "Если хотите завершить программу нажмите 1, если нет: 2 : ";
            cin >> user_choice;
            if (user_choice == '1' || user_choice == '2') {
                break;
            }
            cout << "Ошибка ввода \n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (user_choice == '1') {
            cout << "Программа завершена" << endl;
            break;
        }
    }

    return 0;
}