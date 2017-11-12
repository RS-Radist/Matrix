

#include <iostream>
#include "functionMatrix.cpp"
#include "Classimage.h"
#include "UniTest.cpp"

int main()
{
    Matrix m(2, 3);
    m.Push(12);
    m.Push(4);
    m.Push(25);
    m.Push(31);
    
    std::cout << m.Get(0, 1); // 4
    
    RandomMatrix(m);
    ShowMatrix(m);
  
    return 0;
}
