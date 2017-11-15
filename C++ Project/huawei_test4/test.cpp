// ÉîÛÚ»ªÎªÕĞÆ¸

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

bool IsPrimeNumber(const int& number);

int main(int argc, char* argv[])
{
    int begin = 0;
    int end = 0;

    cin >> begin >> end;

    if (begin > end)
    {
        int temp = begin;
        begin = end;
        end = temp;
    }

    for (int i = begin; i <= end; ++i)
    {
        if (IsPrimeNumber(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}

bool IsPrimeNumber(const int& number)
{
    if (number < 2)
    {
        return false;
    }

    int begin = 2;
    int end = static_cast<int>(sqrt(static_cast<double>(number)));

    for (int i = begin; i <= end; ++i)
    {
        if ((number % i) == 0)
        {
            return false;
        }
    }

    return true;
}
