// Copyright 2017.刘珅珅
// author：刘珅珅
// 使用智能指针
#include "counter.cpp"

#include <iostream>

class HasPtr
{
  public:
      HasPtr(int* p, int  i) : ptr(new U_Ptr(p)), val(i) {}

      // 拷贝构造函数
      HasPtr(const HasPtr& orig) : ptr(orig.ptr), val(orig.val)
      {
          ++ptr->use;
      }

      // 赋值运算符重载
      HasPtr& operator=(const HasPtr&);

      ~HasPtr()
      {
          if (--ptr->use == 0)
          {
              delete ptr;
              ptr = 0;
          }
      }

  public:
      int* get_ptr() const {return ptr->ip; }
      int get_int() const {return val; }

      void set_ptr(int* p) {ptr->ip = p; }
      void set_int(int i) { val = i; }

      int get_ptr_val() const {return *ptr->ip; }
      void set_ptr_val(int i) {*ptr->ip = i; }

  private:
    U_Ptr* ptr;  // 计数类指针
    int val;
};

// 重载赋值运算符
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++rhs.ptr->use;

    if (--ptr->use == 0)
    {
        delete ptr;
        ptr = 0;
    }

    ptr = rhs.ptr;  // 直接把计数类的指针
    val = rhs.val;

    return *this;
}


int main(int argc, char* argv[])
{
    int* p = new int(42);

    HasPtr obj(p, 10);
    HasPtr copy(obj);

    copy.set_ptr_val(32);  // 通过副本对象改变指针中保存的值，会同时改变obj中指针所保存的值

    std::cout << obj.get_ptr_val() << std::endl;  // 输出为32

    //delete p;  // 不能手动删除指针p，编译器会在析构对象obj时，自动删除
    //p = NULL;
    return 0;
}

