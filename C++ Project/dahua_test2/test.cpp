// Copyright 2017.���|�|
// author�����|�|
// sizeof��strlen
#include <iostream>
using std::cout;
using std::endl;

void func(char str[50])
{
    cout << str << endl;
    cout << "A " << sizeof(str) << " B " << strlen(str) << endl;

}
int main(void)
{
    char stra[] = "HelloWorld";
    char *strb = stra;

    cout <<"C " << sizeof(stra) << " D " << sizeof(strb++) << endl;
    cout << strb << endl;  // ���ΪHelloWorld��sizeof��������յĽ����ȷ����С��������Ա��ʽ���м���
    func(++strb);

    cout <<"E " << sizeof(stra) << " F " << sizeof(strb++) << endl;

    return 0; 
}
