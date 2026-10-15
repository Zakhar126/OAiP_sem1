#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет значения функции y = sin(x) - cos(x) на отрезке [A, B] \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    while (true) {
        double A = 0.0;
        double B = acos(-1.0) / 2.0; // PI / 2
        int M = 20;
        double H = (B - A) / M;

        cout << "\nТ1аблица значений функции:\n";
        cout << " i \t   X_i \t\t   Y(x) \n";
        cout << "-------------------------------------\n";

        for (int i = 0; i <= M; i++) {
            double x = A + i * H;
            double y = sin(x) - cos(x);
            
            cout << " " << i << "\t " << x << "\t " << y << "\n";
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