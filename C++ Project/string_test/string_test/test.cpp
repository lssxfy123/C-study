#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    char* str = "abd" + 2;  // ���Ϊd����ָ������ƶ�������
    // char* str1 = "abd" + "cde";  // error���޷�������ָ�����
    cout << str << endl;
    return 0;
}