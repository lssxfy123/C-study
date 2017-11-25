// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ÕûÊıË³Ğòµßµ¹
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int DataProcess(int iInput, int& iNum, char* strRst, int& iOutput);

int main(int argc, char* argv[])
{
    int iInput = 0;

    cin >> iInput;

    if (iInput > 99999)
    {
        iInput = iInput % 100000;
    }
    else if (iInput < -99999)
    {
        iInput = iInput % 100000;
    }

    int iNum = 0;
    char strRst[12] = {0};
    int iOutput = 0;


    DataProcess(iInput, iNum, strRst, iOutput);

    cout << iNum << ", " << strRst << ", " << iOutput << endl;
    return 0;
}

int DataProcess(int iInput, int& iNum, char* strRst, int& iOutput)
{
    iNum = 0;
    int index = 0;

    int input = abs(iInput);

    while (input != 0)
    {
        strRst[iNum] = (input % 10) + '0';
        input = static_cast<int>(input / 10);
        ++iNum;
    }

    iOutput = atoi(strRst);

    if (iInput < 0)
    {
        iOutput = -iOutput;
    }

    char* temp = new char[iNum * 2];
    memset(temp, 0, (iNum * 2));

    for (int i = 0; i != iNum; ++i)
    {
        temp[i * 2] = strRst[i];
        temp[i * 2 + 1] = ' ';
    }
    temp[iNum * 2 - 1] = '\0';


    for (int i = 0; i != (iNum * 2); ++i)
    {
        strRst[i] = temp[i];
    }

    strRst = _strrev(strRst);

    if (strRst[iNum * 2 - 2] == '0')
    {
        strRst[iNum * 2 - 2] = '\0';
    }

    // cout << strRst << endl;

    //if (iInput < 0)
    //{
    //    for (int i = (iNum * 2 + 1); i != 1; --i)
    //    {
    //        strRst[i] = strRst[i - 2];
    //    }

    //    strRst[0] = '-';
    //    strRst[1] = ' ';
    //}

    delete temp;
    temp = NULL;

    return 0;
}
