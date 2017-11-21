#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class T> class List; // ��ģ�������

template <class T> std :: ostream& operator << (std :: ostream&, const List <T>&); // ����ģ�������

// ��ģ��Ķ���
template <class T> class Node
{
public:
    friend class List <T>;

    //����������Ԫ��������ʽֻ����vs2008�����ϰ汾��ʹ�ã�������VC6.0��ʹ��
    friend std :: ostream& operator << <T> (std :: ostream&, const List <T>&);

    Node() : pNext(0), pT(0) {}

private:
    Node   *pNext; //���౾����������ڲ���ʹ����ģ�������ʱ���Բ�ָ���β�
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
    Node <T> *pFirst;  // ע�⣺ʹ����ģ�������ʱ������ָ�������β�
};

template <class T> List <T> :: List()
{
    pFirst = 0;
}

//�������ڵ�
template <class T> void List <T> :: Add(T& t)
{
    Node <T> *temp = new Node <T>; 
    temp->pT = &t;
    temp->pNext = pFirst;
    pFirst = temp;
}

//ɾ������ڵ�
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
    os << "�������������" << endl;

    for(Node <T> *p = q.pFirst; p; p = p->pNext)
    {
        os << *(p->pT) << " ";
    }

    return os;
}

#endif