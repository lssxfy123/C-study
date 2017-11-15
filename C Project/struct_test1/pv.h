
#ifndef PV_H
#define PV_H

struct PV {
    int i;
    int k;
    float f;
    char s[10];
};

extern struct PV pv1;

static int a = 0;
// const int b = 5;  // 在C语言中，会报出error，但在C++中却可以定义

#endif  // PV_H
