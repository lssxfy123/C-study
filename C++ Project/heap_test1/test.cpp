// C++���ڴ����

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    int* p = NULL;

    p = new int[3];

    for (int i = 0; i != 3; ++i)
    {
        p[i] = i;
    }

    for (int j = 0; j != 3; ++j)
    {
        std::cout << p[j] << std::endl;
    }

    delete [] p;
    p = NULL;

    int** double_p = NULL;  // ����ָ�룬��һ��ָ�����飬���ܽ�һ����ά���鸳��һ������ָ��
    double_p = new int* [3];
    double_p[0] = new int[3];
    double_p[1] = new int[4];
    double_p[2] = new int[5];

    for (int i = 0; i != 3; ++i)
    {
        double_p[0][i] = i + 1;
    }

    for (int i = 0; i != 4; ++i)
    {
        double_p[1][i] = i + 1;
    }

    for (int i = 0; i != 5; ++i)
    {
        double_p[2][i] = i + 1;
    }

    for (int i = 0; i != 3; ++i)
    {
        cout << double_p[0][i] << ",";
    }
    cout << endl;

    for (int i = 0; i != 4; ++i)
    {
        cout << double_p[1][i] << ",";
    }
    cout << endl;

    for (int i = 0; i != 5; ++i)
    {
        cout << double_p[2][i] << ",";
    }
    cout << endl;

    delete [] double_p[0];
    delete [] double_p[1];
    delete [] double_p[2];
    delete [] double_p;

    return 0;
}
