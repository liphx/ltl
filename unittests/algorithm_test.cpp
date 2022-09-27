#include "algorithm"

#include "gtest/gtest.h"

TEST(algorithm, all_of) {
    std::vector<int> data{1, 2, 3};
    auto p = [](int x) { return x > 0; };
    EXPECT_TRUE(ltl::all_of(data.begin(), data.end(), p));
    EXPECT_TRUE(ltl::any_of(data.begin(), data.end(), p));
    EXPECT_FALSE(ltl::none_of(data.begin(), data.end(), p));
}

TEST(algorithm, for_each) {
    std::vector<int> data{1, 2, 3};
    int sum = 0;
    ltl::for_each(data.begin(), data.end(), [&sum](int x) { sum += x; });
    EXPECT_EQ(sum, 6);
}
