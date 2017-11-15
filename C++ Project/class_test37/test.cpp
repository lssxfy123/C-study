// 嵌套命名空间

#include <iostream>
using std::cout;  // using 声明
using std::endl;

namespace xxcig
{
    int n = 0;

    namespace sgcc
    {
        int n = 1;  // 屏蔽xxcig中的n
        int k = 2;
    }

    int func()
    {
        // return k;  // error，未声明的标识符
        return sgcc::k;  // ok
    }
}

int main(int argc, char* argv[])
{
    cout << xxcig::sgcc::n << endl;

    namespace X = xxcig::sgcc;  // 命名空间别名

    cout << X::n << endl;
    return 0;
}
