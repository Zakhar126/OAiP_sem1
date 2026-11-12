#include <gtest/gtest.h>

#include "task2.h"

TEST(MatrixRowTest, OriginalRows) {
    int row1[4] = {5, -2, 12, 3};
    int row2[4] = {8, 14, 0, -5};
    int row3[4] = {-1, 6, 4, 9};
    EXPECT_EQ(findRowMax(row1), 12);
    EXPECT_EQ(findRowMax(row2), 14);
    EXPECT_EQ(findRowMax(row3), 9);
}

TEST(MatrixRowTest, AllNegativeElements) {
    int row[4] = {-5, -12, -3, -8};
    EXPECT_EQ(findRowMax(row), -3);
}

TEST(MatrixRowTest, MaxAtTheEnd) {
    int row[4] = {1, 5, 2, 99};
    EXPECT_EQ(findRowMax(row), 99);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}