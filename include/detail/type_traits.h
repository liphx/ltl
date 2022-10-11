#ifndef LTL_DETAIL_TYPE_TRAITS_H_
#define LTL_DETAIL_TYPE_TRAITS_H_

#include <type_traits>

#include "cstddef"  // nullptr_t

namespace ltl {

// helper class
template <class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant<T, v>;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};

template <bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

// helper class

// remove cv

template <class T>
struct remove_cv {
    using type = T;
};

template <class T>
struct remove_cv<const T> {
    using type = T;
};

template <class T>
struct remove_cv<volatile T> {
    using type = T;
};

template <class T>
struct remove_cv<const volatile T> {
    using type = T;
};

template <class T>
using remove_cv_t = typename remove_cv<T>::type;

// remove cv

template <class T, class U>
struct is_same : public false_type {};

template <class T>
struct is_same<T, T> : public true_type {};

// primary type categories

template <class T>
struct is_void : public is_same<void, remove_cv_t<T>> {};
template <class T>
struct is_null_pointer : is_same<nullptr_t, remove_cv_t<T>> {};
template <class T>
struct is_integral;
template <class T>
struct is_floating_point;
template <class T>
struct is_array;

template <class T>
struct is_pointer_helper : false_type {};
template <class T>
struct is_pointer_helper<T *> : true_type {};
template <class T>
struct is_pointer : is_pointer_helper<remove_cv_t<T>> {};

template <class T>
struct is_lvalue_reference;
template <class T>
struct is_rvalue_reference;
template <class T>
struct is_member_object_pointer;
template <class T>
struct is_member_function_pointer;
template <class T>
struct is_enum;
template <class T>
struct is_union;
template <class T>
struct is_class;
template <class T>
struct is_function;

// primary type categories

template <class T>
struct remove_reference {
    typedef T type;
};

template <class T>
struct remove_reference<T&> {
    typedef T type;
};

template <class T>
struct remove_reference<T&&> {
    typedef T type;
};

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

}  // namespace ltl

#endif  // LTL_DETAIL_TYPE_TRAITS_H_
