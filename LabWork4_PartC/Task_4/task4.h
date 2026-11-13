#include <stdlib.h>

long long findMaxDiagonalSum(int*** arr, int n) {
    if (n <= 0 || arr == NULL) {
        return 0;
    }

    long long d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    for (int i = 0; i < n; i++) {
        d1 += arr[i][i][i];
        d2 += arr[i][i][n - 1 - i];
        d3 += arr[i][n - 1 - i][i];
        d4 += arr[n - 1 - i][i][i];
    }

    long long S = d1;
    if (d2 > S) S = d2;
    if (d3 > S) S = d3;
    if (d4 > S) S = d4;

    return S;
}