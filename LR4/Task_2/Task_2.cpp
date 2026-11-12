#include <iostream>

using namespace std;

int main() {
    char repeat;

    while (true) {
        cout << "Вариант 11: Найти в каждой строке матрицы максимальный элемент.\n";
        cout << "Выполнил студент Садовский Захар, группа 653503\n";

        const int M = 3;
        const int N = 4;
        int mat[M][N] = {
            {5, -2, 12, 3},
            {8, 14, 0, -5},
            {-1, 6, 4, 9}
        };

        cout << "\nИсходная матрица:\n";
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        for (int i = 0; i < M; i++) {
            int max_e = mat[i][0];
            for (int j = 1; j < N; j++) {
                if (mat[i][j] > max_e) {
                    max_e = mat[i][j];
                }
            }
            cout << "Максимальный элемент в строке " << i + 1 << ": " << max_e << "\n";
        }

        cout << "-------------------------------------------\n";

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