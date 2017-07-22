// author�����|�|
// STL����
#include <deque>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    const vector<int> cvec = { 1, 2, 3 };
    // cvec.push_back(3);  // error�������������ܲ���ֵ
    // cvec[0] = 5;  // �����޸ĳ���������Ԫ��

    vector<int> v1 = { 2, 3, 4, 5 };
    vector<int> v2 = move(v1);
    PrintElements(v2, "move :     ");
    PrintElements(v1, "after move:  ");
    cout << "v1 size " << v1.size() << endl;
    return 0;
}
