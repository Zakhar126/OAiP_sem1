#include <iostream>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму: a0 - 2*a1 + 4*a2 - ... + (2^(n-1))*((-1)^(n-1))*an-1\n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        int n;

        while (true) {
            cout << "Введите количество элементов n: ";
            cin >> n;

            if (n > 0) {
                break;
            }

            cout << "Ошибка ввода! Введите положительное целое число \n";
        }

        long sum = 0;
        long c = 1;

        cout << "Введите " << n << " целых элементов последовательности через пробел:\n";
        for (int i = 0; i < n; i++) {
            long a;
            cin >> a;
            
            sum += c * a;
            c *= -2;
        }

        cout << "Результат вычисления выражения: " << sum << endl;

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