#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    string content = "abcdefghijklmnopqrst";

    string first = content.substr(0, 6);

    cout << first.c_str() << endl;

    string second = content.substr(2, 6);
    cout << second.c_str() << endl;

    string test = "";
    cout << test.length() << endl;

    return 0;
}
