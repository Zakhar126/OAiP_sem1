#include <gtest/gtest.h>

#include "task.h"
// Объявляем функцию, чтобы тест о ней знал
int countElementsNearAverage(double arr[], int k);

// Тест 1: все элементы одинаковые
TEST(TaskTest, AllElementsSame) {
    double arr[] = {5.0, 5.0, 5.0};
    EXPECT_EQ(countElementsNearAverage(arr, 3), 3);
}

// Тест 2: элементы сильно отличаются от среднего
TEST(TaskTest, ElementsFarFromAverage) {
    double arr[] = {10.0, 10.0, 22.0};
    EXPECT_EQ(countElementsNearAverage(arr, 3), 0);
}

// Тест 3: элементы близки к среднему
TEST(TaskTest, ElementsCloseToAverage) {
    double arr[] = {10.0, 11.0, 12.0};
    EXPECT_EQ(countElementsNearAverage(arr, 3), 3);
}

// Точка входа для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}