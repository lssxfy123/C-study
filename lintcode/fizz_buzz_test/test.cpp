// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// fizz buzzÎÊÌâ
#include <iostream>
#include <vector>
#include <sstream>
#include "..\..\include\print.hpp"
using namespace std;

vector<string> fizzBuzz(int n) {
    // write your code here
    vector<string> result;
    for (int i = 1; i <= n; ++i)
    {
        int n1 = i % 3;
        int n2 = i % 5;
        if (n1 == 0 || n2 == 0)
        {
            (n1 == n2) ? result.push_back("fizz buzz") : (n1 == 0) ? result.push_back("fizz") : result.push_back("buzz");
        }
        else
        {
            stringstream ss;
            ss << i;
            result.push_back(ss.str());
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    vector<string> result = fizzBuzz(15);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ",";
    }
    cout << endl;
    return 0;
}
