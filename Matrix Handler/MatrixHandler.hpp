//
//  MatrixHandler.hpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#ifndef MatrixHandler_hpp
#define MatrixHandler_hpp

#include <stdio.h>
#include <tuple>
#include "Matrix.hpp"
#include "Vector.hpp"

namespace matrixxx {
    
    class MatrixHandler{
    public:
        //constructors
        MatrixHandler();
        //methods
        std::tuple<Matrix,Matrix> getLUDecomposition(Matrix matrix);
        std::tuple<Matrix,Matrix> getLDLTDecomposition(Matrix matrix);
        bool transpose(Matrix& matrix); //transpose matrix
        Matrix getTransposed(Matrix matrix); //return transposed matrix
        Matrix getTransposed(Vector vec); //return transposed vector
    private:
        //methods
    
    };
    
}

#endif /* MatrixHandler_hpp */
