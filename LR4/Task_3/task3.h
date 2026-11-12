
double getDiagonalSum(double** matrix, int n, int mode) {
    if (n <= 0) return 0;

    double sum = 0;
    for (int i = 0; i < n; i++){
        if (matrix[i][0] < 0) {
            for (int j = 0; j < n; j++) {
                if (mode == -1 && i > j) {
                    sum += matrix[i][j];
                } else if (mode == 1 && i < j) {
                    sum += matrix[i][j];
                } else if (mode == 0 && i == j) {
                    sum += matrix[i][j];
                }
            }
        }
    }

    return sum;
}