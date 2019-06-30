// Copyright 2019.刘珅珅
// author：刘珅珅
// 转换字符串到整数
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

bool isValid(char c)
{
    return c >= '0' && c <= '9';
}

bool isSymbol(char c)
{
    return c == '-' || c == '+';
}

string trim(const string& str)
{
    string::size_type pos = str.find_first_not_of(' ');
    if (pos == string::npos)
    {
        return str;
    }
    string::size_type pos2 = str.find_last_not_of(' ');
    if (pos2 != string::npos)
    {
        return str.substr(pos, pos2 - pos + 1);
    }
    return str.substr(pos);
}

int atoi(string& str)
{
    str = trim(str);
    if (str.length() == 0)
    {
        return 0;
    }
    int result = 0;
    string valid_str = "";
    int length = str.length();
    for (int i = 0; i < str.length(); ++i)
    {
        if (i == 0 && isSymbol(str[i]))
        {
            continue;
        }

        if (!isValid(str[i]))
        {
            length = i;
            break;
        }
    }

    if (length > 0)
    {
        valid_str = str.substr(0, length);
    }
    
    if (valid_str.length() == 0)
    {
        return 0;
    }
    
    bool isNegative = false;
    if (isSymbol(valid_str[0]))
    {
        isNegative = valid_str[0] == '-';
        if (valid_str.length() > 1)
        {
            valid_str = valid_str.substr(1);
        }
        else
        {
            return 0;
        }
    }

    // 合法的字符串转整数
    int pow = 1;
    string max_int = "2147483647";
    string min_int = "2147483648";
    if (valid_str.length() > max_int.length())
    {
        string tmp = valid_str.substr(0, valid_str.length() - max_int.length());
        for (auto& c : tmp)
        {
            if (c > '0')
            {
                if (isNegative)
                {
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }
    }
    else if (valid_str.length() == max_int.length())
    {
        if (isNegative && valid_str.compare(min_int) >= 0)
        {
            return INT_MIN;
        }
        else if (!isNegative && valid_str.compare(max_int) >= 0)
        {
            return INT_MAX;
        }

    }

    for (int j = valid_str.length() - 1; j >= 0; --j)
    {
        result += (valid_str[j] - '0') * pow;
        pow *= 10;
    }

    if (isNegative)
    {
        result = -result;
    }

    return result;
}

int main(int argc, char* argv[])
{
    string str1 = " 15+4";
    string str2 = "10000000000";
    string str3 = "-009";
    string str4 = "3147483648";
    string str5 = "00905";
    string str6 = "-1234567890123456789";
    cout << atoi(str1) << endl;
    cout << atoi(str2) << endl;
    cout << atoi(str3) << endl;
    cout << atoi(str4) << endl;
    cout << atoi(str5) << endl;
    cout << atoi(str6) << endl;
    return 0;
}
