

#ifndef Classimage_h
#define Classimage_h

#include <stdio.h>

template <typename T>
class Matrix
{
    T rows;
    T cols;
    size_t current_idx_rows;
    size_t current_idx_cols;
    T** dynamicMatrix = NULL;
public:
    Matrix();
    Matrix(T rows, T cols);
    
    void Push(const T x);
    size_t GetRows() const;
    size_t GetCols() const;
    T Get(T a,T b);
    void ErrorFunction();
    
};

#endif