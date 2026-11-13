#include <gtest/gtest.h>
#include "task6.h"

TEST(Task6Test, OddSquare3x3) {
    long a[3][3] = {0};
    long* sq[] = {a[0], a[1], a[2]};

    buildMagicSquare(sq, 3);

    EXPECT_EQ(sq[0][0] + sq[0][1] + sq[0][2], 15);
    EXPECT_EQ(sq[0][0] + sq[1][0] + sq[2][0], 15);
    EXPECT_EQ(sq[0][0] + sq[1][1] + sq[2][2], 15);
}

TEST(Task6Test, DoublyEvenSquare4x4) {
    long a[4][4] = {0};
    long* sq[] = {a[0], a[1], a[2], a[3]};

    buildMagicSquare(sq, 4);

    EXPECT_EQ(sq[0][0] + sq[0][1] + sq[0][2] + sq[0][3], 34);
    EXPECT_EQ(sq[0][1] + sq[1][1] + sq[2][1] + sq[3][1], 34);
    EXPECT_EQ(sq[0][3] + sq[1][2] + sq[2][1] + sq[3][0], 34);
}

TEST(Task6Test, SinglyEvenSquare6x6) {
    long a[6][6] = {0};
    long* sq[] = {a[0], a[1], a[2], a[3], a[4], a[5]};

    buildMagicSquare(sq, 6);

    EXPECT_EQ(sq[0][0] + sq[0][1] + sq[0][2] + sq[0][3] + sq[0][4] + sq[0][5], 111);
    EXPECT_EQ(sq[0][0] + sq[1][1] + sq[2][2] + sq[3][3] + sq[4][4] + sq[5][5], 111);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}