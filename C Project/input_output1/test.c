#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 123;
    int b = 12345;

    int c = -1;

    int d = -2;
    unsigned short e = 65535;

    float f = 44.5;
    float fval = 9.0;

    int num = 9;
    float* p = &num;

    double dval = 12.34;

    *p = 12.34;
    // *p1 = 12.34;

    printf("%4d, %4d\n", a, b);
    printf("%d, %o\n", c, c);
    printf("%d, %x\n", c, c);

    printf("%d, %u\n", d, d);
    printf("%d, %u\n", e, e);

    printf("%s, %7.2s\n", "CHINA", "CHINA");
    printf("%6.2f\n", 12.3456);
    printf("%.2e\n", 123.456);
    printf("%g\n", 123.23);

    printf("%d \n", f);  // 编译不会报错，但输出为0


    printf("%x\n", dval);
    printf("%x\n", num);
    printf("%d\n", fval);
    return 0;
}
