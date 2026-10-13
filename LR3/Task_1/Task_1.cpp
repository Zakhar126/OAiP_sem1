#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа вычисляет сумму (ai-bi)^2 для i от 1 до 30 c помощью цикла while \n";
    cout << "Выполнил студент Садовский Захар, группа 653503 \n";

    char repeat;
    do {
        double N = 0.0;
        int i = 1;

        while (i <= 30) {
            double a, b;
            
            if (i % 2 != 0) {
                a = i;
                b = pow(i, 2);
            } else {
                a = i / 2.0;
                b = pow(i, 3);
            }

            N += pow(a - b, 2);
            i++;
        }

        cout << "N = " << N << endl;

        cout << "Если хотите продолжить нажмите 1, если нет 2: ";
        cin >> repeat;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (repeat == '1');

    return 0;
}