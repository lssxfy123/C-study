#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

void GetNext(const char* substr, int* next);
int KMP(const char* src, const char* substr);
// void GetNext1(const char* substr, int* next);

int main(int argc, char* argv[])
{
    //char* substr = "aaaab";
    //int* next = new int[strlen(substr)];

    //GetNext(substr, next);

    //for (int i = 0; i != strlen(substr); ++i)
    //{
    //    cout << next[i] << " ";
    //}
    //cout << endl;

    char* src= "bcedaaaa";
    char* substr = "aa";

    int position = KMP(src, substr);

    cout << "position = " << position << endl;
    return 0;
}

void GetNext(const char* substr,int* next)
{
    // 求模式串T的next函数值并存入数组 next。
    int j = 0;
    int k = -1;
    next[0] = -1;  // 初始条件

    int len = strlen(substr);

    while (j < len - 1)
    {
        // ||运算符前面的条件满足，不会再计算后面的条件
        if (k == -1 || substr[j] == substr[k])
        {
            ++k;
            ++j;
            next[j] = k;  // 对应算法中的P[j]=P[k]
        }
        else
        {
            k = next[k];  // 对应算法中的P[j] != P[k]
        }
    }
}

int KMP(const char* src, const char* substr)
{
    if ((src == NULL) || (substr == NULL))
    {
        return -1;
    }

    int* next = NULL;
    int substr_length = strlen(substr);
    int src_length = strlen(src);

    if (src_length < substr_length)
    {
        return -1;
    }
    next = new int[substr_length];

    GetNext(substr, next);

    int i = 0;
    int j = 0;

    while ((i != src_length) && (j != substr_length))
    {
        // next[0] = -1，所以这里要判断j是否为-1
        if ((j == -1) || (src[i] == substr[j]))
        {
            ++i;
            ++j;
        }
        else {
            j = next[j];  // 失配状况发生
        }
    }

    if (j == substr_length)
    {
        return (i - j);
    }

    return -1;
}
