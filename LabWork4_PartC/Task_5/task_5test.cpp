#include <gtest/gtest.h>
#include "task5.h"

TEST(Task5Test, OneBombField) {
    char a[2][2] = {{'*', '.'}, {'.', '.'}};
    char* field[] = {a[0], a[1]};

    fillMinesweeper(field, 2, 2);

    EXPECT_EQ(field[0][0], '*');
    EXPECT_EQ(field[0][1], '1');
    EXPECT_EQ(field[1][0], '1');
    EXPECT_EQ(field[1][1], '1');
}

TEST(Task5Test, NoBombsField) {
    char a[2][2] = {{'.', '.'}, {'.', '.'}};
    char* field[] = {a[0], a[1]};

    fillMinesweeper(field, 2, 2);

    EXPECT_EQ(field[0][0], '0');
    EXPECT_EQ(field[0][1], '0');
    EXPECT_EQ(field[1][0], '0');
    EXPECT_EQ(field[1][1], '0');
}

TEST(Task5Test, CenterBombField) {
    char a[3][3] = {
        {'.', '.', '.'},
        {'.', '*', '.'},
        {'.', '.', '.'}
    };
    char* field[] = {a[0], a[1], a[2]};

    fillMinesweeper(field, 3, 3);

    EXPECT_EQ(field[0][0], '1');
    EXPECT_EQ(field[1][1], '*');
    EXPECT_EQ(field[2][2], '1');
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}