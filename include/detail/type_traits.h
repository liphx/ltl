#ifndef LTL_DETAIL_TYPE_TRAITS_H_
#define LTL_DETAIL_TYPE_TRAITS_H_

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

#endif  // LTL_DETAIL_TYPE_TRAITS_H_
