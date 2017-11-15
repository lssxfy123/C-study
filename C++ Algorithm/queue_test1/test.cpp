// C++实现一个队列

#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    bool ok;

    Queue queue;
    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);


    // queue.ClearQueue();
    // queue.IsEmpty();


    while (!queue.IsEmpty())
    {
        cout << queue.DeQueue(ok) << endl;
    }

    queue.EnQueue(5);
    queue.EnQueue(6);

    while (!queue.IsEmpty())
    {
        cout << queue.DeQueue(ok) << endl;
    }

    return 0;
}
