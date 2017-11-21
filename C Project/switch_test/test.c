// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// switchÓï¾ä²âÊÔ
#include <stdio.h>

int func()
{
    int n = 1;
    return n;
}

int main(int argc, char* argv[])
{
    char grade = 'A';
    char* str = "NB";

    int f = 3.5;

    switch (grade)
    {
    case 'A':
        printf("85~100\n");
        break;
    case 'B':
        printf("70~84\n");
        break;
    default:
        printf("error\n");
    }

    switch (f)
    {
    case 3:
        printf("ok\n");
        break;
    }



    return 0;
}

