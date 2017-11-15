// �ַ������ң������Ӵ���һ�γ��ֵ�λ�ã�û�з���-1

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int Find(char* src, char* substr);

// �����Ӵ��ĸ���
int FindCount(char* src, char* substr);

// �����Ӵ�����
int FindCount(string src, string substr);

// ���������ַ����Ƿ�����ͬ���Ӵ�
// �Ӵ��鵽����1
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

        if (substr[j] == '\0')  // �ж��Ƿ�Ϊ�����ַ����Ϳ����ж��Ӵ��Ƿ����
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

    // find�ķ���ֵҪ����start
    // �䷵��ֵ�������Ӵ���λ��
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
