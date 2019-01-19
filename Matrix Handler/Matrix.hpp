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
        void setElem(int i,int j, double val);
        bool isSquare();
        bool isSymmetric();
    protected:
        
    };
    
}

#endif /* Matrix_hpp */
