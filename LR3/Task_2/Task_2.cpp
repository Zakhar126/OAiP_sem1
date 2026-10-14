#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму ряда dn = 1/(2^n + 1/3^n с точностью 10^-3 \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";
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
     
     while (true) {
     
        cout << "Если хотите завершить программу нажмите 1, если нет: 2 :" ;
     cin >> user_choice;
     
     if (user_choice == '1' || user_choice == '2') {
        break;
     }
    
     cout << "Ошибка ввода \n";
     cin.clear();
     cin.ignore(1000, '\n');

     }
        

     if (user_choice == '1'){
        cout << "Программа завершена" << endl;
        break;
     }
     cin.clear();
     cin.ignore(1000, '\n');
     
    }

    return 0;

}