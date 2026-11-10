#include <cmath>

// Функция принимает обычный массив и его реальный размер k
int countElementsNearAverage(double arr[], int k) {
    if (k <= 0) return 0;

    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    
    double a = sum / k; // Среднее значение
    
    int c = 0; // Количество подходящих элементов
    for (int i = 0; i < k; i++) {
        if (std::fabs(arr[i] - a) <= 3.0) {
            c++;
        }
    }
    
    return c;
}