#include <iostream>

using namespace std;

int main() {
    char repeat;

    while (true) {
        cout << "Вариант 11: В строках, начинающихся с отрицательного элемента,\n";
        cout << "найти суммы элементов ниже, выше и на главной диагонали матрицы.\n";
        cout << "Выполнил студент Садовский Захар, группа 653503\n\n";

        int n;
        while (true) {
            cout << "Введите порядок квадратной матрицы N (N > 0): ";
            cin >> n;

            if (n > 0) {
                break;
            }
            cout << "Ошибка ввода \n";
        }
        double** matrix = new double*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new double[n];
        }

        cout << "Введите элементы матрицы (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "matrix[" << i << "][" << j << "] = ";
                cin >> matrix[i][j];
            }
        }

        cout << "\nИсходная матрица:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
        double sumB = 0, sumA = 0, sumD = 0;  

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] < 0) {
                for (int j = 0; j < n; j++) {
                    if (i > j) {
                        sumB += matrix[i][j];
                    }else if (i < j) {
                        sumA += matrix[i][j];
                    }else {
                        sumD += matrix[i][j];
                    }
                }
            }
        }
        cout << "\nРезультаты (для строк, начинающихся с отрицательного элемента):\n";
        cout << "Сумма элементов ниже главной диагонали: " << sumB << "\n";
        cout << "Сумма элементов выше главной диагонали: " << sumA << "\n";
        cout << "Сумма элементов на главной диагонали:   " << sumD << "\n";
        cout << "-----------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

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
        cout << "\n";
    }

    return 0;
}