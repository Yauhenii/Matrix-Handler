//
//  BasicMatrix.hpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#ifndef BasicMatrix_hpp
#define BasicMatrix_hpp

#include <stdio.h>

namespace matrixxx {
    
    class BasicMatrix{
    public:
        //constructors
        BasicMatrix(int m,int n);
        BasicMatrix(int m,int n, double val);
        BasicMatrix(const BasicMatrix &obj);
        //methods
        //operators
    private:
        //fields
        int m;
        int n;
        double** A;
        //methods
        void allocateMem(); //allocate mem for matrix 'A'
        void fillMatrix(double val=0); //fill matrix 'A' whit value 'val' def value = 0
        
    };
}

#endif /* BasicMatrix_hpp */
