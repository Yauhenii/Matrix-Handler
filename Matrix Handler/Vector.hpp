//
//  Vector.hpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include "BasicMatrix.hpp"

namespace matrixxx {
    
    class Vector : public BasicMatrix{
    public:
        //constructors
        Vector(int n);
        Vector(int n, double val);
        Vector(const Vector &obj);
        //methods
        int getN();
        double getElem(int i);
        void setElem(int i, double val);
    protected:
        
    };
    
}

#endif /* Vector_hpp */
