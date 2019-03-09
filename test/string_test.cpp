#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mystr.h"

TEST(TestSerialization, DateJson) {
    mystr a(0);
    mystr b("0");
    EXPECT_TRUE(a == b);
}