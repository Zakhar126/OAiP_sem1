#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char repeat;

    while (true) {
        cout << "Вариант 11: Найти количество элементов массива,\n";
        cout << "отличающихся от среднего значения не более чем на 3.\n";
        cout << "Выполнил студент Садовский Захар, группа 653503\n";

        const int S = 100;
        double arr[S];
        int k;

        while (true) {
            cout << "Введите количество элементов массива k (от 1 до " << S << "): ";
            cin >> k;

            if (k > 0 && k <= S) {
                break;
            }
            cout << "Ошибка ввода \n";
        }

        cout << "Введите " << k << " чисел:\n";
        for (int i = 0; i < k; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }

        cout << "\nИсходный массив: [ ";
        for (int i = 0; i < k; i++) {
            cout << arr[i] << " ";
        }
        cout << "]\n";

        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        double a = sum / k;
        cout << "Среднее значение всех элементов: " << a << "\n";

        int c = 0;
        for (int i = 0; i < k; i++) {
            if (fabs(arr[i] - a) <= 3.0) {
                c++;
            }
        }

        cout << "Количество подходящих элементов: " << c << "\n";
        cout << "---------------------------------------------------------\n";

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