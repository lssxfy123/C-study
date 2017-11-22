// Copyright 2017.刘珅珅
// author：刘珅珅
// sizeof与strlen
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
    cout << strb << endl;  // 输出为HelloWorld，sizeof会根据最终的结果来确定大小，但不会对表达式进行计算
    func(++strb);

    cout <<"E " << sizeof(stra) << " F " << sizeof(strb++) << endl;

    return 0; 
}
