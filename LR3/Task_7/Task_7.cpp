#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа выводит все числа Армстронга, меньше введённого пользователем числа \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        long long limit;
        cout << "\nВведите верхнюю границу (целое число): ";
    
        if (!(cin >> limit)) {
            cout << "Ошибка ввода! Ожидается целое число.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (limit <= 1) {
            cout << "Чисел Армстронга меньше " << limit << " не обнаружено.\n";
        } else {
            cout << "Числа Армстронга меньше " << limit << ":\n";
            bool found = false;

            for (long long i = 1; i < limit; ++i) {
                long long temp = i;
                int num_digits = 0;

                while (temp > 0) {
                    num_digits++;
                    temp /= 10;
                }

                temp = i;
                long long sum = 0;

                while (temp > 0) {
                    int digit = temp % 10;
                    sum += round(pow(digit, num_digits));
                    temp /= 10;
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