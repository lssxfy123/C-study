// Copyright 2016.���|�|
// author�����|�|
// Observer�۲���ģʽ

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Subject;

// �����ߣ��۲��ߣ�����
class Observer {
public:

    // ����������
    virtual ~Observer() {}

    virtual void Received(Subject* sender) = 0;

protected:
    Observer() {}
};

// �����߻���
// �ڻ�����ά���۲��߶���
class Subject
{
public:
    virtual ~Subject() {}

    virtual void Attach(Observer* object);
    virtual void Detach(Observer* object);
    virtual void Notify();

private:
    list<Observer*> observers;  // �۲��߶���
};

// ����۲��߶���
void Subject::Attach(Observer* object)
{
    observers.push_back(object);
}

// �ӹ۲��߶����Ƴ�
void Subject::Detach(Observer* object)
{
    observers.remove(object);
}

// ֪ͨ���ж�����
void Subject::Notify()
{
    for (list<Observer*>::iterator iter = observers.begin();
        iter != observers.end(); ++iter)
    {
        static_cast<Observer*>(*iter)->Received(this);
    }
}


// ����ķ�������
// ������һ��ֻ��һ��
class Mobile : public Subject
{
public:
    Mobile() { check_list_ = "";}
    void SimulateCheckList();
    string GetCheckList();

private:
    string check_list_;  // �����嵥
};

void Mobile::SimulateCheckList()
{
    cout << "--------�����嵥--------" << endl;
    check_list_ = "�л����ѣ�17.52\t\t��;����57.00\n���ţ�5.00\n";

    Notify();
}

string Mobile::GetCheckList()
{
    return check_list_;
}

// ����Ĺ۲�����
class Jerry : public Observer
{
public:
    void Received(Subject* sender);
};

void Jerry::Received(Subject* sender)
{
    cout << "Jerry�յ�����֪ͨ:" << endl
        << static_cast<Mobile*>(sender)->GetCheckList() << endl;
}

// ��һ������۲�����
class Anco : public Observer
{
public:
    void Subscribe(Subject* subject);
    void Unsubscribe(Subject* subject);
    void Received(Subject* sender);
};


void Anco::Received(Subject* sender)
{
    cout << "Anco�յ�����֪ͨ:" << endl
        << static_cast<Mobile*>(sender)->GetCheckList() << endl;
}

// ��������
void Anco::Subscribe(Subject* subject)
{
    subject->Attach(this);
}

// ȡ������
void Anco::Unsubscribe(Subject* subject)
{
    subject->Detach(this);
}

int main(int argc, char* argv[])
{
    Mobile mobile;

    Jerry jerry;
    Anco anco;

    // ����
    // ���ֶ��ķ�ʽ��������Subject
    // ά����observers�����һ����¼
    mobile.Attach(&jerry);
    anco.Subscribe(&mobile);

    // �����߷�����Ϣ
    cout << "\t[�µ���...�ƶ����ͻ����嵥��]" << endl;
    mobile.SimulateCheckList();

    return 0;
}
