#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    float fval1 = 9.87654311;
    float fval2 = 9.87654322;

    // 结果为fval1 = fval2
    // 可见float型只能精确到小数点后6位
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

    // double型可以精确到小数点后15位
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
