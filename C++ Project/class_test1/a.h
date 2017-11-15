#ifndef A_H
#define A_H

#include <string>

class A
{
  public:
    A();
    ~A();

  private:
    typedef std::string::size_type Index;

  public:
    // typedef std::string::size_type Index;
    Index func();

  private:
    Index cursor_;
};

#endif
