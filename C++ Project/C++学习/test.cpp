// ∂‡œﬂ≥Ã≤‚ ‘

#include <iostream>
#include <Windows.h>
#include <string>
#include <process.h>

using namespace std;

bool flag = false;

void OtherThread(void* p)
{
    while (!flag)
    {
      Sleep(1000);
      cout << "exist other thread" << endl;
    }

    cout << "exit other thread " << endl;
}

int main(int argc, char* argv[])
{
    _beginthread(&OtherThread, NULL, NULL);

    while (1)
    {
        Sleep(10000);
        flag = true;
    }
    return 0;
}

