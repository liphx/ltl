#include "type_traits"

#include "gtest/gtest.h"

namespace type_traits_test {

struct version : public ltl::integral_constant<int, 100> {};

TEST(type_traits, integral_constant) {
    EXPECT_EQ(version(), 100);
    version value;
    EXPECT_EQ(value, 100);

    EXPECT_TRUE(ltl::true_type());
    EXPECT_FALSE(ltl::false_type());
}

TEST(type_traits, type_categories) {
    // is_void
    EXPECT_TRUE(ltl::is_void<void>::value);
    EXPECT_TRUE(ltl::is_void<const void>::value);
    EXPECT_TRUE(ltl::is_void<volatile void>::value);
    EXPECT_TRUE(ltl::is_void<const volatile void>::value);
    EXPECT_FALSE(ltl::is_void<int>::value);

    // is_null_pointer, is_pointer
    EXPECT_TRUE(ltl::is_null_pointer<decltype(nullptr)>::value);
    EXPECT_FALSE(ltl::is_null_pointer<int *>::value);
    EXPECT_FALSE(ltl::is_pointer<decltype(nullptr)>::value);
    EXPECT_TRUE(ltl::is_pointer<int *>::value);
}

}  // namespace type_traits_test
