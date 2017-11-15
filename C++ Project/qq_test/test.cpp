// �齱�㷨������һ��0-100��������Ϊ�齱�ĸ���

#include <iostream>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::endl;

#define N 100

// �齱�㷨
bool Lottery(unsigned int probability);

int main(int argc, char* argv[])
{
    srand( (unsigned)time(NULL));

    int count = 0;

    for (int i = 0; i != 100000; ++i)
    {
        if (Lottery(30))
        {
            ++count;
            // cout << 1 << endl;
        }
        //else
        //{
        //    // cout << 0 << endl;
        //}
    }

    cout << "�н�����Ϊ�� " << count / 100000.0 << endl;
    return 0;
}

bool Lottery(unsigned int probability)
{
    //for (int i = 0; i != 10; ++i)
    //{
    //    cout << rand() % 100 << endl;
    //}

    int r = RAND_MAX - (RAND_MAX + 1) % N;

    int t = rand();

    while (t > r)
    {
        t = rand();
    }

    int result = t % N;
    if (result < probability)
    {
        return true;
    }

    return false;
}
