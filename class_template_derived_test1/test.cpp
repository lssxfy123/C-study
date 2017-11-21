// Copyright 2016.���|�|
// author�����|�|
// ��ģ��ļ̳�
#include <iostream>
using namespace std;

template<class CountedType>
class ObjectCounter {
public:
    static size_t LiveCount()
    {
        return count;
    }

protected:
    ObjectCounter()
    {
        ++count;
    }

    ObjectCounter(CountedType const &)
    {
        ++count;
    }

    ~ObjectCounter() {
        --count;
    }

private:
    static size_t count;
};

template<class CountedType>
size_t ObjectCounter<CountedType>::count = 0;

// �ݹ�ģ��̳У��������౾����Ϊģ��������ݸ�����
class MyClass : public ObjectCounter<MyClass>
{

};

int main(int argc, char* argv[])
{
    MyClass m1;
    cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 1

    {
        MyClass m2;
        cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 2
    }

    // m2�ѽ�������
    cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 1
    return 0;
}