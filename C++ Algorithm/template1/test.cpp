// Copyright 2017.���|�|
// author�����|�|
// ����ģ��Ĳ���   
#include <iostream>
using namespace std;

//����һ������ģ��
template <typename T>
void compare(const T &a, const T &b)
{
    //ע��C++��̵Ĺ淶��

    if (a > b)
        cout << "a>b" << endl;
    else if (a < b)
        cout << "a<b" << endl;
    else
        cout << "a=b" << endl;
} 

//����һ����������ģ��
//ע��inline�ؼ���Ҫ���ڷ�������֮ǰ
template <typename T>
inline T min(const T&, const T&)
{

}

int main(int argc, char *argv[])
{
    compare(1, 0);
    compare(2.1, 2.1) ;

    char *str1 = "abcd";
    char *str2 ="efgh";

    compare(*str1, *str2);

    return 0;
}