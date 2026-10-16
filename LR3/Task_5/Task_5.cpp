#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        
    cout << "Программа приближенно находит корень уравнения f(x) = 0 методом перебора\n";
    cout << "Вариант 11: f(x) = sin(lg(x)) + x * cot(x^2) на [0.5; 1.5]\n";
    cout << "Выполнил студент Садовский Захар, группа 653503\n\n";

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