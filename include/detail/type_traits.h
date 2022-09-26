#ifndef LTL_DETAIL_TYPE_TRAITS_H_
#define LTL_DETAIL_TYPE_TRAITS_H_

namespace ltl {

template <typename T, T v>
struct integral_constant {
    /* static constexpr T value = v; */
    /* typedef T value_type; */
    /* typedef integral_constant<T, v> type; */
    /* constexpr operator value_type() const noexcept { return value; } */
    /* constexpr value_type operator()() const noexcept { return value; } */
};
typedef integral_constant<bool, true> true_type;

template <class T>
struct remove_reference {
    typedef T type;
};

template <typename T>
struct remove_reference<T&> {
    typedef T type;
};

template <typename T>
struct remove_reference<T&&> {
    typedef T type;
};

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

}  // namespace ltl

#endif  // LTL_DETAIL_TYPE_TRAITS_H_
