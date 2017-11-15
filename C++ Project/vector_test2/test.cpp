// 容器测试：迭代器

#include <iostream>
#include <vector>

using std::vector;

void PrintValue(vector<int>::iterator begin, vector<int>::iterator end);

int main(int argc, char* argv[])
{
    vector<int> vector_int;

    for (int i = 0; i != 10; ++i)
    {
        vector_int.push_back(i);
    }

    vector<int>::iterator iterator_int;  // 定义一个迭代器

    for (iterator_int = vector_int.begin(); iterator_int != vector_int.end(); ++iterator_int)
    {
        std::cout << *iterator_int << std::endl;
    }

    for (iterator_int = vector_int.begin(); iterator_int != vector_int.end(); ++iterator_int)
    {
        *iterator_int = 10;  // 通过迭代器修改容器元素的值
    }

    PrintValue(vector_int.begin(), vector_int.end());


    vector<int>::const_iterator const_iterator_int;  // 定义一个const迭代器
    const_iterator_int = vector_int.begin();
    // *const_iterator_int = 80;  // error：不能给常量赋值
    ++const_iterator_int;

    const vector<int>::iterator iterator_const_int = vector_int.begin();
    *iterator_const_int = 80;
    // ++iterator_const_int;  // error不能修改迭代器本身

    return 0;
}

void PrintValue(vector<int>::iterator begin, vector<int>::iterator end)
{
    while (begin != end)
    {
        std::cout << *begin << std::endl;
        ++begin;
    }
}
