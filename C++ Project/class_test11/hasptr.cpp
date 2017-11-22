// Copyright 2017.���|�|
// author�����|�|
// ����ֵ����

#include <iostream>

class HasPtr
{
  public:
    HasPtr(const int& p, int i): ptr(new int(p)), val(i)
    {
        std::cout << "���ù��캯��" << std::endl;
    }

    HasPtr(const HasPtr& orig): ptr(new int(*orig.ptr)), val(orig.val)
    {
        std::cout << "���ÿ������캯��" << std::endl;
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
    std::cout << "��ֵ���������" << std::endl;

    *ptr = *rhs.ptr;  // ��ָ��ָ���ֵ�����µĶ��󣬶�����ֱ�ӽ�ָ�븳���µĶ���
    val = rhs.val;
    return *this;
}

int main(int argc, char* argv[])
{
    int i = 42;

    HasPtr obj(i, 10);
    HasPtr copy(obj);  // ���ÿ������캯��
    HasPtr copy1 = obj;  // ���ÿ������캯��

    HasPtr copy2(i, 32);

    copy2 = obj;  // ��ֵ���������
    return 0;
}
