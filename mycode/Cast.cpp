#include <iostream>

class Base {
    public:
    virtual void foo(const int *p) const {
        int *q = const_cast<int*>(p);
        *q = 10;
        std::cout << "I'm Base func : " << *q << std::endl;
    }
};

class Derived : public Base {
    public:
    void foo(const int *p) const override {
        int *q = const_cast<int*>(p);
        *q = 36;
        std::cout << "I'm Derived func : " << *q << std::endl;
    }
};

int main() {
    // static_cast
    float f = 38.50;
    auto a = static_cast<char>(f);
    std::cout << "static_cast result : " << a << std::endl;

    // dynamic_cast
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);
    if (d) {
        std::cout << "dynamic_cast success" << std::endl;
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }
    int x = 5;

    // const_cast
    d->foo(&x);
    std::cout << "const variable changed : " << x << std::endl;
    delete b;

    // reinterpret_cast
    auto p = reinterpret_cast<char*>(&x);
    std::cout << "reinterpret_cast result : " << *p << std::endl;
    
    return 0;
}