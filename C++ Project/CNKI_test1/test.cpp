// Copyright 2017.刘珅珅
// author：刘珅珅
// 求一个正整数的所有连续相加的正整数的序列
// 从数学的角度考虑，这是一个等差数列

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

    for (unsigned int i = 2;i <= k; ++i)  // i代表等差数列的项数
    {
        for (unsigned int x = 1; x < k; ++x)
        {
            // x代表首项
            // y代表末项
            unsigned int y = (i - 1) + x;

            if (((x + y) * i) == (2 * n))  // 等差数列的求和公式
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

