#include "b.h"

B::B()
{

}

B& B::SetHeight(int height)
{
    this->height = height;

    return *this;
}

B& B::SetWidth(int width)
{
    this->width = width;

    return *this;
}
