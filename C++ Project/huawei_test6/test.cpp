
#include <iostream>
#include <string>
using namespace std;

void HeadTrim(string& input);
void EndTrim(string& input);

int main(int argc, char* argv[])
{
    string input;

    getline(cin, input);

    if (input.length() > 100)
    {
        input.resize(100);
    }

    HeadTrim(input);
    EndTrim(input);

    string substr;
    int count = 0;
    while (input.length() != 0)
    {
        count = 0;
        if ((input.find(' ') > input.length()) && (input.find(',') > input.length()))
        {
            substr = input;
            ++count;
            input.erase(0, input.length());
            cout << substr << " = " << count << endl;
            continue;
        }

        for (int i = 0; i != input.length(); ++i)
        {
            if ((input[i] == ' ') || (input[i] == ','))
            {
                substr = input.substr(0, i);
                input.erase(0, i);
                EndTrim(input);
                HeadTrim(input);
                ++count;
                break;
            }
        }

        for (int j = 0; j < input.length(); ++j)
        {
            if (input.find(substr) < input.length())
            {
                ++count;
                input.erase(input.find(substr), substr.length());
                EndTrim(input);
                HeadTrim(input);
            }
        }

        cout << substr << " = " << count << endl;
    }

    return 0;
}

void EndTrim(string& input)
{
    int length = input.length();

    // 去掉尾部的非有效字符
    for (int i = (length - 1); i >= 0; --i)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            input.erase(i + 1, length - 1 - i);
            break;
        }
    }
}

void HeadTrim(string& input)
{
    int length = input.length();

    // 去掉头部的非有效字符
    for (int i = 0; i != length; ++i)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            input.erase(0, i);
            break;
        } else if (i == (length - 1))
        {
            input.erase(0, length);
        }
    }
}
