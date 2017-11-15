// 引用数组形参

#include <iostream>

void PrintValue(int (&array)[10]);

int main(int argc, char* argv[])
{
    int array1[10];
    int array2[5];

    for (int i = 0; i != 10; ++i)
    {
        array1[i] = i + 1;
    }

    PrintValue(array1);
    // PrintValue(array2);  // error，长度不匹配
}

void PrintValue(int (&array)[10])
{
    for (int i = 0; i != 10; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}
