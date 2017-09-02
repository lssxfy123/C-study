// Copyright 2017.刘珅珅
// author：刘珅珅
// 更易型算法1
#include "../include/algostuff.hpp"

class A
{
public:
    A()
    {
        number_ = 0;
    }

    explicit A(int n) : number_(n)
    {
        cout << "constructor A" << endl;
    }

     A(A& a) : number_(a.number_)
    {
        cout << "copy constru ctor A" << endl;
    }

    A(A&& a) : number_(a.number_)
    {
        cout << "move constructor A" << endl;
    }

    void Output()
    {
        cout << "number is " << number_ << endl;
    }

    A& operator =(A& rhs)
    {
        number_ = rhs.number_;
        return *this;
    }

    A& operator=(const A&& rhs)
    {
        number_ = rhs.number_;
        return *this;
    }

private:
    int number_;
};

int main(int argc, char* argv[])
{
    // copy
    vector<string> coll1 = {"Hello", "this", "is", "an", "example"};
    list<string> coll2;

    // use back_inserter into insert instead of overwrite
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));

    // copy elements to cout using an ostream iterator
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "reverse copy: " << endl;
    // overwriting
    copy(coll1.crbegin(), coll1.crend(), coll2.begin());
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << endl;

    vector<char> source(10, '.');
    for (int c = 'a'; c <= 'f'; ++c)
    {
        source.push_back(c);
    }
    source.insert(source.end(), 10, '.');
    PrintElements(source, "source:   ");
    vector<char> c1(source.cbegin(), source.cend());
    // 源区间与目标区间发生了重叠
    // copy all letters three elements in front of the 'a'
    copy(c1.cbegin() + 10, c1.cbegin() + 16, // source range
        c1.begin() + 7);                                     // destination range
    PrintElements(c1, "c1:   ");

    vector<char> c2(source.cbegin(), source.cend());
    // 源区间与目标区间发生重叠
    // copy all letters three elements behind the 'f'
    copy_backward(c2.cbegin() + 10, c2.cbegin() + 16, c2.begin() + 19);
    PrintElements(c2, "c2:   ");
    cout << endl;

    // move
    list<string> coll3(coll1.size());
    move(coll1.cbegin(), coll1.cend(), coll3.begin());

    // move并未将coll1的元素搬移走
    cout << coll1.size() << endl;
    cout << *coll1.cbegin() << endl;

    list<string> list1 = {"Hello", "World"};
    // 使用搬移迭代器会将list1中的元素搬移到list2中
    // 但list1仍然有空间
    list<string> list2(make_move_iterator(list1.begin()), make_move_iterator(list1.end()));
    cout << list1.size() << endl;
    cout << *list1.begin() << endl;

    vector<A> collA;
    collA.push_back(A(1));
    collA.push_back(A(2));
    collA.push_back(A(3));
    list<A> listA(collA.size());
    move(collA.cbegin(), collA.cend(), listA.begin());
    cout << collA.size() << endl;
    (*collA.begin()).Output();
    //// print elements coll3
    //// use move() because these elements 
    //// in coll3 are not used again
    //move(coll3.cbegin(), coll3.cend(),
    //    ostream_iterator<string>(cout, " "));
    //cout << endl;

    return 0;
}
