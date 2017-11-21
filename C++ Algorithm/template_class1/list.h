#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class T> class List; // 类模板的声明

template <class T> std :: ostream& operator << (std :: ostream&, const List <T>&); // 函数模板的声明

// 类模板的定义
template <class T> class Node
{
public:
    friend class List <T>;

    //这种声明友元函数的形式只能在vs2008及以上版本中使用，不能在VC6.0中使用
    friend std :: ostream& operator << <T> (std :: ostream&, const List <T>&);

    Node() : pNext(0), pT(0) {}

private:
    Node   *pNext; //在类本身的作用域内部，使用类模板的名字时可以不指定形参
    T *pT;
};

template <class T> class List
{
public:
    friend std :: ostream& operator<< <T> (std :: ostream&, const List <T>&);

    List();
    void Add(T&);
    void Remove(T&);
    T* Find(T&);
private:
    Node <T> *pFirst;  // 注意：使用类模板的名字时，必须指定类型形参
};

template <class T> List <T> :: List()
{
    pFirst = 0;
}

//添加链表节点
template <class T> void List <T> :: Add(T& t)
{
    Node <T> *temp = new Node <T>; 
    temp->pT = &t;
    temp->pNext = pFirst;
    pFirst = temp;
}

//删除链表节点
template <class T> void List <T> :: Remove(T& t)
{
    Node <T> *q = 0;

    if (*(pFirst ->pT) == t)
    {
        q = pFirst;
        pFirst = pFirst->pNext;
    }
    else
    {
        for (Node <T> *p = pFirst; p->pNext; p = p->pNext)
        {
            if (*(p->pNext->pT) == t)
            {
                q= p->pNext;
                p->pNext = q->pNext;
                break;
            }
        }
    }

    if(q)
    {
        delete q->pT;
        delete q;
    }

}

template <class T> T* List <T> :: Find(T& t)
{
    for (Node <T> *p = pFirst; p; p = p->pNext)
    {
        if (*(p->pT) == t)
        {
            return p->pT;
        }
    }

    return 0;
}

template <class T> std :: ostream& operator << (std :: ostream &os, const List <T> &q)
{
    os << "重载输出操作符" << endl;

    for(Node <T> *p = q.pFirst; p; p = p->pNext)
    {
        os << *(p->pT) << " ";
    }

    return os;
}

#endif