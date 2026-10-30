#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа выводит все числа Армстронга, меньше введённого пользователем числа \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        long l;
        cout << "Введите целое число: ";
        cin >> l;

        if (l <= 1) {
            cout << "Чисел Армстронга меньше " << l << " не обнаружено.\n";
        } else {
            cout << "Числа Армстронга меньше " << l << ":\n";
            bool found = false;

            for (long i = 1; i < l; ++i) {
                long t = i;
                int nd = 0;

                while (t > 0) {
                    nd++;
                    t /= 10;
                }

                t = i;
                long long sum = 0;

                while (t > 0) {
                    int d = t % 10;
                    sum += round(pow(d, nd));
                    t /= 10;
                }

                if (sum == i) {
                    cout << i << " ";
                    found = true;
                }
            }

            if (!found) {
                cout << "Нет подходящих чисел.";
            }
            cout << endl;
        }

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