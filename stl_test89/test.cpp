// Copyright 2017.刘珅珅
// author：刘珅珅
// 复数
#include <complex>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // complex number with real and imaginary parts
    // 4.0 + 3.0i
    complex<double> c1(4.0, 3.0);

    // 极坐标复数
    // create complex number from polar coordinates
    complex<float> c2(polar(5.0f, 0.75f));

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    // print complex numbers as polar coordinates
    cout << "c1: magnitude: " << abs(c1)
        << " (squared magnitude: " << norm(c1) << ") "
        << " phase angle: " << arg(c1) << endl;

    cout << "c2: magnitude: " << abs(c2)
        << " (squared magnitude: " << norm(c2) << ") "
        << " phase angle: " << arg(c2) << endl;

    // 共轭
    cout << "c1 conjugated:  " << conj(c1) << endl;
    cout << "c2 conjugated:  " << conj(c2) << endl;

    cout << "4.4 + c1 * 1.8 " << 4.4 + c1 * 1.8 << endl;

    cout << "c1 + c2:   "
        << c1 + complex<double>(c2.real(), c2.imag()) << endl;

    // real = c1.real * c2.real - c1.imag * c2.imag
    // imag = c1.real * c2.imag + c1.imag * c2.reals
    cout << "c1 * c2: "
        << c1 * complex<double>(c2.real(), c2.imag()) << endl;
    return 0;
}
