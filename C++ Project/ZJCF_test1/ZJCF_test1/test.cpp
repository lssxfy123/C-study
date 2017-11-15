// 字符串查找，返回子串第一次出现的位置，没有返回-1

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int Find(char* src, char* substr);

// 查找子串的个数
int FindCount(char* src, char* substr);

// 查找子串个数
int FindCount(string src, string substr);

// 查找两个字符串是否有相同的子串
// 子串查到大于1
bool FindSameSubStr(char* A, char* B);

int main(int argc, char* argv[])
{
    string str = "bcedaaaa";
    string substr = "aa";

    int n = str.find(substr);

    char* src= "bcedaaaa";
    char* substr1 = "aa";

    int position = Find(src, substr1);

    cout << n << endl;
    cout << position << endl;

    int count = FindCount(str, substr);

    cout << "count = " << count << endl;

    count = FindCount(src, substr1);
    cout << "count = " << count << endl;

}

int Find(char* src, char* substr)
{
    if ((src == NULL)|| (substr == NULL))
    {
        return -1;
    }

    for (int i = 0; src[i] != '\0'; ++i)
    {
        if (src[i] != substr[0])
        {
            continue;
        }

        int j = 0;

        while ((substr[j] != '\0') && (src[i + j] != '\0'))
        {
            ++j;
            if (substr[j] != src[i + j])
            {
                break;
            }
        }

        if (substr[j] == '\0')  // 判断是否为结束字符，就可以判断子串是否出现
        {
            return i;
        }
    }

    return -1;
}

int FindCount(char* src, char* substr)
{
    int count = 0;
    int position = Find(src, substr);
    int sub_length = 0;

    while (substr[sub_length] != '\0')
    {
        ++sub_length;
    }

    while (-1 != position)
    {
        ++count;
        src = src + position + sub_length;
        position = Find(src, substr);
    }

    return count;
}

int FindCount(string src, string substr)
{
    int count = 0;
    int start = 0;

    // find的返回值要赋给start
    // 其返回值代表着子串的位置
    while (-1 != (start = src.find(substr, start)))
    {
        ++count;
        start += substr.length();
    }
    return count;
}

bool FindSameSubStr(char* A, char* B)
{
    return false;
}
