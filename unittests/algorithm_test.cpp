#include "algorithm"

#include <forward_list>

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

TEST(algorithm, is_sorted) {
    // 向前迭代器
    std::forward_list<int> data{1, 3, 2};
    ASSERT_FALSE(ltl::is_sorted(data.begin(), data.end()));

    data.sort();
    ASSERT_TRUE(ltl::is_sorted(data.begin(), data.end()));
}

TEST(algorithm, is_sorted_until) {
    std::forward_list<int> data{1, 3, 2};
    EXPECT_EQ(ltl::is_sorted_until(data.begin(), data.end()), std::is_sorted_until(data.begin(), data.end()));

    std::forward_list<int> data2{1, 2, 3};
    EXPECT_EQ(ltl::is_sorted_until(data2.begin(), data2.end()), std::is_sorted_until(data2.begin(), data2.end()));

    std::forward_list<int> data3;
    EXPECT_EQ(ltl::is_sorted_until(data3.begin(), data3.end()), std::is_sorted_until(data3.begin(), data3.end()));
}
