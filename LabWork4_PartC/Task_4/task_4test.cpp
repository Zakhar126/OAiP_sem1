#include <gtest/gtest.h>
#include "task4.h"

TEST(Task4Test, AllElementsSame) {
    int a[2][2][2] = {{{5, 5}, {5, 5}}, {{5, 5}, {5, 5}}};
    int* r0[] = {a[0][0], a[0][1]};
    int* r1[] = {a[1][0], a[1][1]};
    int** arr[] = {r0, r1};

    EXPECT_EQ(findMaxDiagonalSum(arr, 2), 10);
}

TEST(Task4Test, FirstDiagonalMax) {
    int a[2][2][2] = {{{10, 1}, {1, 1}}, {{1, 1}, {1, 20}}};
    int* r0[] = {a[0][0], a[0][1]};
    int* r1[] = {a[1][0], a[1][1]};
    int** arr[] = {r0, r1};

    EXPECT_EQ(findMaxDiagonalSum(arr, 2), 30);
}

TEST(Task4Test, SingleElementCube) {
    int a[1][1][1] = {{{42}}};
    int* r0[] = {a[0][0]};
    int** arr[] = {r0};

    EXPECT_EQ(findMaxDiagonalSum(arr, 1), 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}