#include <iostream>

#include "gtest/gtest.h"
#include "mockcpp/mockcpp.hpp"

int add(int a, int b) {
    return a + b;
}

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

TEST(test_mock, sample_mock_test ) {
    MOCKER(add).stubs().will(returnValue(100));
    int c = add(a, b);
    EXPECT_EQ(100, c);
    GlobalMockObject::verify();
}
