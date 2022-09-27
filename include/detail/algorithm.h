#ifndef LTL_DETAIL_ALGORITHM_H_
#define LTL_DETAIL_ALGORITHM_H_

/*
 * all_of
 * any_of
 * none_of
 * for_each
 */

namespace ltl {

template <class InputIt, class UnaryPredicate>
constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) return false;
    }
    return true;
}

template <class InputIt, class UnaryPredicate>
constexpr bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (p(*first)) return true;
    }
    return false;
}

template <class InputIt, class UnaryPredicate>
constexpr bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (p(*first)) return false;
    }
    return true;
}

template <class InputIt, class UnaryFunction>
constexpr UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f) {
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

}  // namespace ltl

#endif  // LTL_DETAIL_ALGORITHM_H_
