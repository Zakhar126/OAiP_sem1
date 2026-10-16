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
            cout << "Ошибка ввода\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue; 
        }

        if (x == 0) {
            cout << "Ошибка: при x = 0 функция ln|x| не определена \n";
        } else {
            
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