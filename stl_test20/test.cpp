// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// type trait£ºÀàĞÍÌØÕ÷
#include <iostream>
using namespace std;

template <typename T>
void FooImpl(const T& value, true_type)
{
    cout << "Foo() called for pointr to " << *value << endl;
}

template <typename T>
void FooImpl(const T& value, false_type)
{
    cout << "Foo() called for value to " << value << endl;
}

template <typename T>
void Foo(const T& value)
{
    FooImpl(value, is_pointer<T>());
}

int main(int argc, char* argv[])
{
    int n = 5;
    Foo<int>(n);

    int* ptr = new int(4);
    Foo<int*>(ptr);

    delete ptr;
    return 0;
}
