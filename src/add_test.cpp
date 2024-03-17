#include <gtest/gtest.h>
#include "add.h"

TEST(add_test, answer_0_plus_0){
    EXPECT_EQ(0, add(0, 0));     // 成功
}

TEST(add_test, answer_1_plus_2){
    EXPECT_EQ(3, add(1, 2));     // 成功
}

TEST(add_test, answer_1_plus_3){
    EXPECT_EQ(3, add(1, 3));     // 失敗(テスト誤り)
}
