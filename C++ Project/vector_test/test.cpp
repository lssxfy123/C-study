// vector����

#include <iostream>
#include <vector>
using std::vector;

int main(int argc, char* argv[])
{
    // vector��һ����ģ��
    vector<int> vector_int;  // ��������Ϊint������Ϊ�գ�Ĭ�Ϲ��캯��

    vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    //vector_int.push_back(1);
    //std::cout << "capacity = " << vector_int.capacity() << " size = " << vector_int.size() << std::endl;

    vector<int> vector_int1(vector_int);  // �������캯����vector_int1Ϊvector_int�ĸ���

    vector<int> vector_int2(10);  // �����а���10��ԭʼ����ʼ��Ϊ0
    std::cout << "capacity = " << vector_int2.capacity() << " size = " << vector_int2.size() << std::endl;

    vector<int>::const_iterator iterator_int;
    for (iterator_int = vector_int2.begin(); iterator_int != vector_int2.end(); ++iterator_int)
    {
        std::cout << *iterator_int << std::endl;
    }

    vector_int2.push_back(2);
    std::cout << "capacity = " << vector_int2.capacity() << " size = " << vector_int2.size() << std::endl;

    vector<int> vector_int3(10, -1);

    for (iterator_int = vector_int3.begin(); iterator_int != vector_int3.end(); ++iterator_int)
    {
        std::cout << *iterator_int << std::endl;
    }

    for (vector<int>::size_type i = 0; i != vector_int3.size(); ++i)
    {
        vector_int3[i] = i;
    }

    for (iterator_int = vector_int3.begin(); iterator_int != vector_int3.end(); ++iterator_int)
    {
        std::cout << *iterator_int << std::endl;
    }

    //vector<int> vector_int4;

    //for (vector<int>::size_type i = 0; i != 10; ++i)
    //{
    //    vector_int4[i] = i;
    //}

    return 0;
}
