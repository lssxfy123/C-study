// Copyright 2017.刘珅珅
// author：刘珅珅
// 定义值型类

#include <iostream>

class HasPtr
{
  public:
    HasPtr(const int& p, int i): ptr(new int(p)), val(i)
    {
        std::cout << "调用构造函数" << std::endl;
    }

    HasPtr(const HasPtr& orig): ptr(new int(*orig.ptr)), val(orig.val)
    {
        std::cout << "调用拷贝构造函数" << std::endl;
    }

    HasPtr& operator=(const HasPtr&);

    ~HasPtr() {delete ptr; ptr = 0;}

  public:
    int get_ptr_val() const {return *ptr;}
    int get_int() const {return val;}

    void set_ptr(int* p) {ptr = p; }
    void set_int(int i) {val = i; }

    int* get_ptr() const {return ptr; }
    void set_ptr_val(int i) {*ptr = i; }

  private:
    int* ptr;
    int val;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    std::cout << "赋值运算符重载" << std::endl;

    *ptr = *rhs.ptr;  // 把指针指向的值赋给新的对象，而不能直接将指针赋给新的对象
    val = rhs.val;
    return *this;
}

int main(int argc, char* argv[])
{
    int i = 42;

    HasPtr obj(i, 10);
    HasPtr copy(obj);  // 调用拷贝构造函数
    HasPtr copy1 = obj;  // 调用拷贝构造函数

    HasPtr copy2(i, 32);

    copy2 = obj;  // 赋值运算符重载
    return 0;
}
