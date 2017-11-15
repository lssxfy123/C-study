#include <iostream>
using std::cout;
using std::endl;

typedef struct 
{
    int a;
    int b;
    int c;
}SC;

struct SD
{
    int a;
    int b;
    int c;
    int d;
};

int main(void)
{
    SC c1[] = {{3},{4},{5},{6}};

    cout << c1[0].a << c1[0].b << c1[0].c << endl;  // 300
    cout << c1[1].a << c1[1].b << c1[1].c << endl;  // 400
    cout << c1[2].a << c1[2].b << c1[2].c << endl;  // 500
    cout << c1[3].a << c1[3].b << c1[3].c << endl;  // 600

    struct SD *c2 = (struct SD*)c1 + 1;
    struct SD *c3 = (struct SD*)c1;

    // ���Ϊ0050
    // c1�洢��ֵΪ300400500600
    // (struct SD*)c1 + 1����c1���׵�ַƫ������SD�Ĵ�С
    cout << c2->a << " " << c2->b << " " << c2->c << " " << c2->d << endl;

    // ���Ϊ3004
    cout << c3->a << " " << c3->b << " " << c3->c << " " << c3->d << endl;

    return 0; 
}
