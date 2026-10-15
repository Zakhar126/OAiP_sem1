#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет функцию Y(x) и ряд S(x) для Варианта 11\n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    char user_choice;
    while (true) {
        int n, count_x;

        cout << "Введите количество членов ряда (n): ";
        cin >> n;

        cout << "Введите количество чисел, от которых хотите посчитать функцию: ";
        cin >> count_x;

        for (int i = 0; i < count_x; i++) {
            double x;
            cout << "Введите число x (от 0.1 до 1): ";
            cin >> x;

            double sum = 1.0;
            double current_term = 1.0;

            for (int k = 1; k < n; k++) {
                double multiplier = - (2.0 * k * k + 1.0) / (2.0 * (k - 1) * (k - 1) + 1.0) 
                                 * (x * x) / ((2.0 * k - 1.0) * (2.0 * k));
                current_term *= multiplier;
                sum += current_term;
            }

            double y_exact = (1.0 - (x * x) / 2.0) * cos(x) - (x / 2.0) * sin(x);

            cout << "Результаты для x = " << x << ":\n";
            cout << "  S(x) (значение ряда)      = " << sum << endl;
            cout << "  Y(x) (точная функция)     = " << y_exact << endl;
            cout << "---------------------------------------------------------\n";
        }

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
            cout << "Программа завершена << \n";
            break;
        }

        cin.clear();
        cin.ignore(1000, '\n');
    }

    return 0;
}