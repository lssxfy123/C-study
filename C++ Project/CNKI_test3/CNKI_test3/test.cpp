#include <iostream>
#include <locale>
using std::cout;
using std::wcout;
using std::endl;
using namespace std;

void reverse(wchar_t* str);

locale loc("chs");

int main(int argc, char* argv[])
{
    //// �������������
    //// �ο�C����ѧϰ13-���顢ָ���뺯��.docx
    //// ��������char* str = "abcde"�����лᱨ��
    //// ԭ����ָ��ָ���Ϊ�����ַ����������޸���ֵ
    //// ����������򲻻������⣬��������ջ��
    //// char str[] = "abcde";
    wchar_t str[] = L"A������ӭ��";  // ��Ҫ��L����ʾ���ַ�
    // cout << wcslen(str) << endl;
    reverse(str);

    wcout.imbue(loc);
    wcout << str << endl;
    return 0;
}

void reverse(wchar_t* str)
{
    int length = 0;
    wchar_t* temp = str;
    wchar_t c;

    if (!str)
    {
        printf("����ת���ַ�����Ч\n");
        return;
    }

    // �ж��ַ����ĳ���
    while ((*str) != '\0')
    {
        ++length;
        ++str;
    }

    cout << "length = " << length << endl;

    // printf("length = %d\n", length);

    str = temp;
    temp = str + length - 1;

    while (temp > str)
    {
        c = *temp;
        *temp = *str;
        *str = c;
        ++str;
        --temp;
        // printf("%c", c);
    }
    // printf("\n");
}


