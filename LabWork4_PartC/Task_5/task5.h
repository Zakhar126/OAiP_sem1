#include <stdlib.h>

int fillMinesweeper(char** field, int n, int m) {
    if (n <= 0 || m <= 0 || field == NULL) {
        return 0;
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

    return 0;
}