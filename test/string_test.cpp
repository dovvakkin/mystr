#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mystr.h"

TEST(MatrixTest, Constructors) {
    mystr a(0);
    mystr b("0");
    mystr c(b);
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(c == b);
    EXPECT_TRUE(a == c);

    mystr d("11");
    mystr e('1', 2);
    EXPECT_TRUE(d == e);
}

TEST(MatrixTest, Operators) {
    mystr a(11);
    mystr b(1);
    mystr c(1);

    b = "11";
    EXPECT_TRUE(b == a);
    EXPECT_FALSE(b != a);
    c = b;
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a != c);
    a = "1";
    b = "2";
    c = "12";
    EXPECT_TRUE(c == (a + b));
    EXPECT_FALSE(c != (a + b));
    a += b;
    EXPECT_TRUE(c == a);
    EXPECT_FALSE(c != a);

    EXPECT_TRUE(c[0] == '1');
    EXPECT_FALSE(c[0] != '1');
    c[0] = '&';
    EXPECT_TRUE(c[0] == '&');
    EXPECT_FALSE(c[0] != '&');

}

TEST(MatrixTest, Streams) {
    mystr a(0);
    mystr b("0");
    EXPECT_TRUE(a == b);
}