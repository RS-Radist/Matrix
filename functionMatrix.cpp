#include "Classimage.h"
#include <iostream>
#include <stdio.h>


template <typename T>
Matrix <T>::Matrix(): rows(0), cols(0), current_idx_rows(0), current_idx_cols(0), dynamicMatrix(NULL)
{
    
}
template <typename T>
Matrix<T>::Matrix(T rows, T cols)
: rows (rows),cols(cols),current_idx_rows(0),current_idx_cols(0)
{
    dynamicMatrix = new T*[rows];
    for (int i=0;i<rows;++i)
    {
        dynamicMatrix[i]=new T[cols];
    }
}


template <typename T>
void Matrix<T>::Push(const T x)
{
    if(dynamicMatrix == NULL)
    {
        dynamicMatrix = new T*; // 0xAB
        *dynamicMatrix = new T; // 0xAF
        **dynamicMatrix = x; //*dynamicMatrix[cols]=x;
        // dynamicMatrix[rows][cols] = x
        rows = 1;
        cols = 1;
        current_idx_rows = 0;
        current_idx_cols = 0;
        return;
    }
    else if(rows != current_idx_rows + 1 && cols != current_idx_cols + 1)
    {
        if(current_idx_cols != cols - 1)
        {
            dynamicMatrix[current_idx_rows][current_idx_cols++] = x;
        }
        else
        {
            current_idx_cols = 0;
            dynamicMatrix[++current_idx_rows][current_idx_cols++] = x;
        }
        return;
    }
    T* temp = new T[cols + 1];
    memcpy(temp, *dynamicMatrix, sizeof(T) * cols);
    temp[cols] = x;
    cols++;
    current_idx_cols++;
    delete[] *dynamicMatrix;
    *dynamicMatrix = temp;
}
template <typename T>
size_t Matrix<T>::GetRows() const
{
    return current_idx_rows;
}
template <typename T>
size_t Matrix<T>::GetCols() const
{
    return current_idx_cols;
}

template <typename T>
T Matrix<T>::Get(T a,T b)
{
    if (current_idx_cols>=a&&current_idx_cols>=rows)
    {
        ErrorFunction();
    }
    return dynamicMatrix[a][b];
}

void ErrorFunction()
{
    std::cout<<"Error";
}


template class Matrix<size_t>;
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<char>;
