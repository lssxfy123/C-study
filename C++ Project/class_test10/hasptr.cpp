// Copyright 2017.���|�|
// author�����|�|
// ʹ������ָ��
#include "counter.cpp"

#include <iostream>

class HasPtr
{
  public:
      HasPtr(int* p, int  i) : ptr(new U_Ptr(p)), val(i) {}

      // �������캯��
      HasPtr(const HasPtr& orig) : ptr(orig.ptr), val(orig.val)
      {
          ++ptr->use;
      }

      // ��ֵ���������
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
    U_Ptr* ptr;  // ������ָ��
    int val;
};

// ���ظ�ֵ�����
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++rhs.ptr->use;

    if (--ptr->use == 0)
    {
        delete ptr;
        ptr = 0;
    }

    ptr = rhs.ptr;  // ֱ�ӰѼ������ָ��
    val = rhs.val;

    return *this;
}


int main(int argc, char* argv[])
{
    int* p = new int(42);

    HasPtr obj(p, 10);
    HasPtr copy(obj);

    copy.set_ptr_val(32);  // ͨ����������ı�ָ���б����ֵ����ͬʱ�ı�obj��ָ���������ֵ

    std::cout << obj.get_ptr_val() << std::endl;  // ���Ϊ32

    //delete p;  // �����ֶ�ɾ��ָ��p��������������������objʱ���Զ�ɾ��
    //p = NULL;
    return 0;
}

