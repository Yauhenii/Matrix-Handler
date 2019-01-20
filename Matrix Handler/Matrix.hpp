//
//  Matrix.hpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "BasicMatrix.hpp"

namespace matrixxx {
    
    class Matrix : public BasicMatrix{
    public:
        //constructors
        Matrix(int m,int n);
        Matrix(int m,int n, double val);
        Matrix(const Matrix &obj);
        //methods
        int getM();
        int getN();
        double getElem(int i, int j);
        double setElem(int i,int j, double val); //set 'val' to Aij, return previous value of Aij
        bool isSquare();
        bool isSymmetric();
        double getTrace(); //if matrix isn't square, return sum of diagonal elements, while i<=min(m,n)
        Matrix getSubMatrix(int m,int n);
    protected:
        
    };
    
}

#endif /* Matrix_hpp */
