#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#define ltl std

class A {
public:
    int x;
    A(int x = 0) : x(x) {}
    ~A() { std::cout << "~A(" << x << ")" << std::endl; }
};

void func(ltl::shared_ptr<A> pa) { std::cout << pa.use_count() << std::endl; }

void func_ref(ltl::shared_ptr<A>& pa) { std::cout << pa.use_count() << std::endl; }

TEST(shared_ptr, shared_ptr) {
    { ltl::shared_ptr<A> pa(new A); }  // ~A(0)

    ltl::shared_ptr<A> pa(new A(1));
    std::cout << pa.use_count() << std::endl;  // 1
    {
        ltl::shared_ptr<A> pa2(pa);
        std::cout << pa2.use_count() << std::endl;  // 2
    }
    std::cout << pa.use_count() << std::endl;  // 1
    func(pa);                                  // 2 传值
    func_ref(pa);                              // 1 引用

    ltl::shared_ptr<A> pa2(pa);
    pa2 = nullptr;
    std::cout << pa.use_count() << std::endl;  // 1
    pa.reset(new A(2));                        // ~A(1)
    pa = nullptr;                              // ~A(2)

    auto pa3 = ltl::make_shared<A>(3);
    std::cout << pa3->x << std::endl;  // 3

    std::cout << "----" << std::endl;
}
