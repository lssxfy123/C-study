// Copyright 2017.刘珅珅
// author：刘珅珅
// vector作为形参
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int func(std::vector<int> vec)
{ 
    static int k = 2;

    // 这里定义的迭代器和下面注释掉的迭代器相比是反转的
    std::vector<int>::reverse_iterator it;

    // 从容器的最后一个元素向前迭代
    for (it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << "*it = " << *it << endl;

        k += (*it % 2 == 0) ? ++*it : (*it)++;
    }

    //std::vector<int>::iterator it;

    //for(it = vec.begin(); it != vec.end(); ++it)
    //{
    //    k += (*it%2== 0) ? ++*it: (*it)++;
    //}
    return k;
}

int main(void)
{ 
    std::vector<int>vec;

    for (int i = 0; i < 4; i++)
    {
        vec.push_back(i);
        cout << func(vec) << " " << endl;
    }

    return 0;
}
