#include <stdio.h>
#include <stdlib.h>

int main() {
    char repeat;

    while (1) {
        printf("Задание 6: Построить магический квадрат порядка n.\n");
        printf("Выполнил студент Садовский Захар, группа 653503\n\n");

        long ni;
        while (1) {
            printf("Введите порядок квадрата n (от 1 до 4294967295): ");
            scanf("%ld", &ni);

            if (ni > 0 && ni <= 4294967295L) {
                break;
            }
            printf("Ошибка ввода \n");
        }

        if (ni == 2) {
            printf("\nМагического квадрата порядка 2 не существует.\n");
            printf("--------------------------------------------------------\n");
        } else {
            int n = (int)ni;

            long** sq = (long**)malloc(n * sizeof(long*));
            for (int i = 0; i < n; i++) {
                sq[i] = (long*)calloc(n, sizeof(long));
            }

            if (n % 2 == 1) {
                int i = 0;
                int j = n / 2;
                for (long num = 1; num <= (long)n * n; num++) {
                    sq[i][j] = num;
                    int next_i = (i - 1 + n) % n;
                    int next_j = (j + 1) % n;
                    if (sq[next_i][next_j] != 0) {
                        i = (i + 1) % n;
                    } else {
                        i = next_i;
                        j = next_j;
                    }
                }
            } else if (n % 4 == 0) {
                long num = 1;
                long max_num = (long)n * n;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3)) {
                            sq[i][j] = max_num - num + 1;
                        } else {
                            sq[i][j] = num;
                        }
                        num++;
                    }
                }
            } else {
                int h = n / 2;
                long sb = (long)h * h;

                int i = 0;
                int j = h / 2;
                for (long num = 1; num <= sb; num++) {
                    sq[i][j] = num;
                    sq[i + h][j + h] = num + sb;
                    sq[i][j + h] = num + 2 * sb;
                    sq[i + h][j] = num + 3 * sb;

                    int next_i = (i - 1 + h) % h;
                    int next_j = (j + 1) % h;
                    if (sq[next_i][next_j] != 0) {
                        i = (i + 1) % h;
                    } else {
                        i = next_i;
                        j = next_j;
                    }
                }

                int k = (n - 2) / 4;
                for (int r = 0; r < h; r++) {
                    for (int c = 0; c < k; c++) {
                        int col = c;
                        if (r == h / 2) {
                            col = c + 1;
                        }
                        long temp = sq[r][col];
                        sq[r][col] = sq[r + h][col];
                        sq[r + h][col] = temp;
                    }
                    for (int c = 0; c < k - 1; c++) {
                        int col = n - 1 - c;
                        long temp = sq[r][col];
                        sq[r][col] = sq[r + h][col];
                        sq[r + h][col] = temp;
                    }
                }
            }

            printf("\nМагический квадрат порядка %d:\n", n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%4ld ", sq[i][j]);
                }
                printf("\n");
            }
            printf("--------------------------------------------------------\n");

            for (int i = 0; i < n; i++) {
                free(sq[i]);
            }
            free(sq);
        }
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