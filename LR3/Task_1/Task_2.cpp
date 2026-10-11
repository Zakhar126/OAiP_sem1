#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму ряда dn = 1/(2^n + 1/3^n с точностью 10^-3" << endl;
    cout << "Выполнил студент Садовский Захар, группа 653503" << endl;
    while (true) {
    int n = 1;
    double sum = 0.0, dn, epsilon = pow(10, -3);

    do { 
        dn = 1 / pow(2, n) + 1 / pow(3, n);
        sum += dn;
        n++;
    } while (dn >= epsilon);
     cout << "Сумма ряда: " << sum << endl;
     char user_choice;
     cout << "Если хотите завершить программу нажмите 1, если нет: 2 :" ;
     cin >> user_choice;
    
     if (user_choice != '2'){
        cout << "Программа завершена" << endl;
        break;
     }
    }

    return 0;

}