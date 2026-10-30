#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму ряда dn = 1/(2^n + 1/3^n) с точностью 10^-3 \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    char repeat;

    while (true) {
        int n = 1;
        double sum = 0.0, dn, eps = pow(10, -3);

        do {
            dn = 1 / (pow(2, n) + 1 / pow(3, n));
            sum += dn;
            n++;
        } while (dn >= eps);

        cout << "Сумма ряда: " << sum << endl;

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