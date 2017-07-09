// author£ºÁõ«|«|
// stlµü´úÆ÷
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char* argv[])
{
    list<char> coll;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        coll.push_back(c);
    }

    typedef list<char>::const_iterator Iter;
    for (Iter iter = coll.begin(); iter != coll.end(); ++iter)
    {
        cout << (*iter) << ' ';
    }
    cout << endl;
    return 0;
}
