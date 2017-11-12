//
//  UniTest.cpp
//  MATRIX
//
//  Created by iMac on 11.11.17.
//  Copyright © 2017 MATRIX. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "Classimage.h"
template <typename T>
void RandomMatrix(Matrix<T>& m)
{
    for (int i=0;i<m.GetRows();++i)
    {
        for (int j=0;j<m.GetCols();++j)
        {
            m.Push(arc4random()%9+1);
        }
    }
}
template <typename T>
void ShowMatrix(Matrix<T>& m)
{
    for (int i=0;i<m.GetRows();++i)
    {
        for (int j=0;j<m.GetCols();++j)
        {
            std::cout<<m.Get(i, j)<<" ";
        }
        std::cout<<std::endl;
    }
}

