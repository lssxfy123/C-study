// Copyright 2017.���|�|
// author�����|�|
// ��һ��������������������ӵ�������������
// ����ѧ�ĽǶȿ��ǣ�����һ���Ȳ�����

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    unsigned int n = 0;

    cin >> n;

    unsigned int k = 0;

    if (n % 2 == 0)
    {
        k = static_cast<unsigned int>(n / 2);
    }
    else
    {
        k = static_cast<unsigned int>(n / 2) + 1;
    }

    for (unsigned int i = 2;i <= k; ++i)  // i����Ȳ����е�����
    {
        for (unsigned int x = 1; x < k; ++x)
        {
            // x��������
            // y����ĩ��
            unsigned int y = (i - 1) + x;

            if (((x + y) * i) == (2 * n))  // �Ȳ����е���͹�ʽ
            {
                for (unsigned int j = x; j <= y; ++j)
                {
                    cout << j << " ";
                }

                cout << endl;
            }
        }
    }
    return 0;
}

