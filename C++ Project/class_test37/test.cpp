// Ƕ�������ռ�

#include <iostream>
using std::cout;  // using ����
using std::endl;

namespace xxcig
{
    int n = 0;

    namespace sgcc
    {
        int n = 1;  // ����xxcig�е�n
        int k = 2;
    }

    int func()
    {
        // return k;  // error��δ�����ı�ʶ��
        return sgcc::k;  // ok
    }
}

int main(int argc, char* argv[])
{
    cout << xxcig::sgcc::n << endl;

    namespace X = xxcig::sgcc;  // �����ռ����

    cout << X::n << endl;
    return 0;
}
