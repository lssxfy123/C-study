// ÈÝÆ÷µÄ²âÊÔ

#include <iostream>
#include <vector>
using std::vector;

int main(int argc, char* argv[])
{
    int* p1 = new int;
    *p1 = 1;
    int* p2 = new int;
    *p2 = 2;
    int* p3 = new int;
    *p3 = 3;

    vector<int*> vector_p;
    vector_p.push_back(p1);
    vector_p.push_back(p2);
    vector_p.push_back(p3);

    std::cout << vector_p.size() << vector_p.capacity() << std::endl;

    vector<int*>::iterator iterator_p;

    for (iterator_p = vector_p.begin(); iterator_p != vector_p.end(); ++iterator_p)
    {
        std::cout << *iterator_p << std::endl;
        std::cout << *(*iterator_p) << std::endl;
    }

    // Çå¿ÕÈÝÆ÷
    for (iterator_p = vector_p.begin(); iterator_p != vector_p.end(); ++iterator_p)
    {
        if (*iterator_p != NULL)
        {
            delete [] *iterator_p;
            *iterator_p = NULL;
        }
    }
    vector_p.clear();

    return 0;
}
