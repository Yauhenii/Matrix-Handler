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
#include <ostream> //?

namespace matrixxx {
    
    class BasicMatrix{
    public:
        //constructors
        BasicMatrix(int m,int n);
        BasicMatrix(int m,int n, double val);
        BasicMatrix(const BasicMatrix &obj);
        //destructor
        ~BasicMatrix();
        //methods
        void fillWithRandomNumbers(int val); //fill matrix with random whole numbers, |number| <= 'val'
        void fillWithRandomPositiveNumbers(int val); //fill matrix with random whole numbers, number <= 'val', number>=0
        void transpose(); //transpose matrix ?
        BasicMatrix getTransposedMatrix(); //return transposed matrix ?
        bool multiplyBy(BasicMatrix obj);
        //operators
        friend std::ostream& operator<<(std::ostream& os, const BasicMatrix& obj); //put matrix to the stream 'os' ?
    private:
        //fields
        int m;
        int n;
        double** A;
        //methods
        void allocateMem(); //allocate mem for matrix 'A'
        void freeMem(); //free mem of matrix 'A'
        void fill(double val=0); //fill matrix 'A' whit value 'val' def value = 0
        void copyMatrixArray(double** source, double** destination); //copy values from source array to destination array
        void swap(double& a,double& b);
        void swap(int& a,int& b);
        void transposeAsSquare(); //transpose square matrix
        void transposeAsCommon(); //transpose matrix
    };
}

#endif /* BasicMatrix_hpp */
