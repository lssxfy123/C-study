// Copyright 2017.���|�|
// author�����|�|
// smartָ�룺unique_ptr
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class A
{
public:
    A()
    {
        cout << "construct A" << endl;
    }

    A(const A& src)
    {
        cout << "copy construct A" << endl;
    }

    ~A()
    {
        cout << "destruct A" << endl;
    }
};

class Test
{
public:
    // ����ڳ�ʼ��ptr2ʱ��newʧ��
    // ��ôptr1Ҳ���ͷ��ѷ�����ڴ�
    Test() : ptr1(new A), ptr2(new A)
    {
    }

    // �������캯���Ǳ�Ҫ��
    // unique_ptr���ܱ�Ĭ�Ͽ���
    // TestҲ���ܽ��п�������
    Test(const Test& src) : ptr1(new A(*src.ptr1)), ptr2(new A(*src.ptr2))
    {
    }

    // ��ֵ����������Ǳ�Ҫ��
    // unique_ptr���ܱ�Ĭ�ϸ�ֵ
    const Test& operator= (const Test& src)
    {
        *ptr1 = *src.ptr1;
        *ptr2 = *src.ptr2;
        return *this;
    }

    // ������Ժ�����������
    // unique_ptr���Զ��ͷſ��ٵ���Դ

private:
    unique_ptr<A> ptr1;
    unique_ptr<A> ptr2;
};

class ADeleter
{
public:
    void operator() (A* ptr)
    {
        cout << "call delete for class A object" << endl;
        delete ptr;
    }
};

int main(int argc, char* argv[])
{
    Test t1;
    Test t2(t1);

    // ����ʱ�����
    // unique_ptr����delete������ӵ�еĶ���������
    // ��C++��������delete[]
    // unique_ptr<string> up(new string[10]);  // runtime error
    
    // �����ƫ�ػ��汾�У�unique_ptr����ʹ��*��->
    // ����ʹ��[]
    unique_ptr<string[]> up(new string[5]);  // ok

    // �Զ���ɾ��
    // template��2��ʵ�α����Ǻ��������ã�����ָ���������
    unique_ptr<int, function<void(int*)>> up1(new int[10], [](int* p) {
        delete[] p;
    });

    unique_ptr<int, void(*)(int*)> up2(new int[10], [](int* p) {
        delete[] p;
    });

    unique_ptr<A, ADeleter> up3(new A);
    return 0;
}
