#include <stdio.h>
#include <stdlib.h>

int main() {
    char repeat;

    while (1) {
        printf("Задание 4: Определить диагональ с наибольшей суммой чисел\n");
        printf("в трёхмерном динамическом массиве размером n^3.\n");
        printf("Выполнил студент Садовский Захар, группа 653503\n\n");

        int n;
        while (1) {
            printf("Введите размер куба n (n > 0): ");
            scanf("%d", &n);

            if (n > 0) {
                break;
            }
            printf("Ошибка ввода \n");
        }

        int*** arr = (int***)malloc(n * sizeof(int**));
        for (int i = 0; i < n; i++) {
            arr[i] = (int**)malloc(n * sizeof(int*));
            for (int j = 0; j < n; j++) {
                arr[i][j] = (int*)malloc(n * sizeof(int));
            }
        }

        printf("\nВведите %d целых неотрицательных чисел:\n", n * n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    while (1) {
                        printf("arr[%d][%d][%d] = ", i, j, k);
                        scanf("%d", &arr[i][j][k]);

                        if (arr[i][j][k] >= 0) {
                            break;
                        }
                        printf("Ошибка ввода \n");
                    }
                }
            }
        }

        printf("\nИсходный трёхмерный массив (по слоям):\n");
        for (int i = 0; i < n; i++) {
            printf("Слой %d:\n", i);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[i][j][k]);
                }
                printf("\n");
            }
        }

        long long d1 = 0, d2 = 0, d3 = 0, d4 = 0; 

        for (int i = 0; i < n; i++) {
            d1 += arr[i][i][i];
            d2 += arr[i][i][n - 1 - i];
            d3 += arr[i][n - 1 - i][i];
            d4 += arr[n - 1 - i][i][i];
        }

        long long S = d1;
        int bd = 1;

        if (d2 > S) {
            S = d2;
            bd = 2;
        }
        if (d3 > S) {
            S = d3;
            bd = 3;
        }
        if (d4 > S) {
            S = d4;
            bd = 4;
        }

        printf("\nСуммы 4 главных пространственных диагоналей:\n");
        printf("Диагональ 1 [i][i][i]: %lld\n", d1);
        printf("Диагональ 2 [i][i][n-1-i]: %lld\n", d2);
        printf("Диагональ 3 [i][n-1-i][i]: %lld\n", d3);
        printf("Диагональ 4 [n-1-i][i][i]: %lld\n", d4);

        printf("\nРезультат: наибольшая сумма (%lld) у диагонали №%d.\n", S, bd);
        printf("--------------------------------------------------------\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                free(arr[i][j]);
            }
            free(arr[i]);
        }
        free(arr);

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