#include <stdlib.h>

int buildMagicSquare(long** sq, int n) {
    if (n <= 0 || n == 2 || sq == NULL) {
        return 0;
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

    return 0;
}