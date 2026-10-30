#include <iostream>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму: a0 - 2*a1 + 4*a2 - ... + (2^(n-1))*((-1)^(n-1))*an-1\n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        int n;
        cout << "\nВведите количество элементов n: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Ошибка ввода! Введите положительное целое число: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        long long sum = 0;
        long long current_coefficient = 1;

        cout << "Введите " << n << " целых элементов последовательности через пробел:\n";
        for (int i = 0; i < n; i++) {
            long long a;
            while (!(cin >> a)) {
                cout << "Ошибка ввода! Введите целое число для элемента a[" << i << "]: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
            sum += current_coefficient * a;
            current_coefficient *= -2; 
        }

        cout << "Результат вычисления выражения: " << sum << endl;

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
        
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return 0;
}