#include <stdio.h>
#include <stdlib.h>

int main() {
    char repeat;

    while (1) {
        printf("Задание 5: Дополнить поле для игры в «Сапёр» размером n*m числами,\n");
        printf("как в оригинальной игре ('.' - пусто, '*' - бомба).\n");
        printf("Выполнил студент Садовский Захар, группа 653503\n\n");

        int n, m;
        while (1) {
            printf("Введите количество строк n (n > 0): ");
            scanf("%d", &n);

            if (n > 0) {
                break;
            }
            printf("Ошибка ввода \n");
        }

        while (1) {
            printf("Введите количество столбцов m (m > 0): ");
            scanf("%d", &m);

            if (m > 0) {
                break;
            }
            printf("Ошибка ввода \n");
        }

        char** field = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            field[i] = (char*)malloc(m * sizeof(char));
        }

        printf("\nВведите элементы поля ('.' или '*'):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (1) {
                    printf("field[%d][%d] = ", i, j);
                    scanf(" %c", &field[i][j]);

                    if (field[i][j] == '.' || field[i][j] == '*') {
                        break;
                    }
                    printf("Ошибка ввода \n");
                }
            }
        }

        printf("\nИсходное поле:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%c ", field[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '.') {
                    int b = 0;

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di;
                            int nj = j + dj;

                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (field[ni][nj] == '*') {
                                    b++;
                                }
                            }
                        }
                    }

                    field[i][j] = b + '0';
                }
            }
        }

        printf("\nПоле с числами:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%c ", field[i][j]);
            }
            printf("\n");
        }
        printf("--------------------------------------------------------\n");

        for (int i = 0; i < n; i++) {
            free(field[i]);
        }
        free(field);

        while (1) {
            printf("Если хотите завершить программу нажмите 1, если нет 2: ");
            scanf(" %c", &repeat);

            if (repeat == '1' || repeat == '2') {
                break;
            }
            printf("Ошибка ввода \n");
        }

        if (repeat == '1') {
            printf("Программа завершена\n");
            break;
        }
    }

    return 0;
}