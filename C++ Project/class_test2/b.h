
#ifndef B_H
#define B_H

class B
{
  public:
    B();

  public:
    B& SetHeight(int height);
    B& SetWidth(int width);

  private:
    int height;
    int width;
};

#endif  // B_H
