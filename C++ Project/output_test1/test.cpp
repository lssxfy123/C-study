#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    float fval1 = 9.87654311;
    float fval2 = 9.87654322;

    // ���Ϊfval1 = fval2
    // �ɼ�float��ֻ�ܾ�ȷ��С�����6λ
    if (fval1 < fval2)
    {
        cout << "fva1 < fval2" << endl;
    } else if (fval1 == fval2)
    {
        cout << "fval1 = fval2" << endl;
    } else
    {
        cout << "fval1 > fval2" << endl;
    }

    // double�Ϳ��Ծ�ȷ��С�����15λ
    double dval1 = 9.8765432187654321;
    double dval2 = 9.8765432187654322;

    if (dval1 < dval2)
    {
        cout << "dva1 < dval2" << endl;
    } else if (dval1 == dval2)
    {
        cout << "dval1 = dval2" << endl;
    } else
    {
        cout << "dval1 > dval2" << endl;
    }

    return 0;
}
