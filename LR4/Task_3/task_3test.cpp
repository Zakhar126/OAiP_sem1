#include <gtest/gtest.h>
#include "task3.h"

TEST(Task3Test, NoNegativeRows) {
    double r0[] = {1.0, -5.0,  2.0};
    double r1[] = {0.0,  3.0, -4.0};
    double r2[] = {7.0,  8.0,  9.0};
    double* matrix[] = {r0, r1, r2};

    EXPECT_EQ(getDiagonalSum(matrix, 3, -1), 0.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  1), 0.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  0), 0.0);
}

TEST(Task3Test, AllNegativeRows) {
    double r0[] = {-1.0, 2.0, 3.0};
    double r1[] = {-4.0, 5.0, 6.0};
    double r2[] = {-7.0, 8.0, 9.0};
    double* matrix[] = {r0, r1, r2};

    EXPECT_EQ(getDiagonalSum(matrix, 3, -1), -3.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  1), 11.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  0), 13.0);
}

TEST(Task3Test, MixedRows) {
    double r0[] = { 5.0, 10.0, 20.0};
    double r1[] = {-2.0,  3.0,  4.0};
    double r2[] = { 0.0, -9.0,  1.0};
    double* matrix[] = {r0, r1, r2};

    EXPECT_EQ(getDiagonalSum(matrix, 3, -1), -2.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  1),  4.0);
    EXPECT_EQ(getDiagonalSum(matrix, 3,  0),  3.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}