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
        //void fillWithRandomNumbers(int maxVal); //fill matrix with random whole numbers, |number| <= 'val'
        void fillWithRandomPositiveNumbers(int maxVal); //fill matrix with random whole numbers, number <= 'val', number>=0
        void fillWithRandomPositiveNumbersSymmetric(int maxVal); //fill matrix with random whole numbers, number <= 'val', number>=0. Matrix is symmetric
        bool multiplyBy(BasicMatrix obj); //multiply this by obj matrix. If it's impossible, return 0; else return 1
        bool transposeAsSquare(); //transpose square matrix
        bool transposeAsCommon(); //transpose common matrix
        //operators
        friend std::ostream& operator<<(std::ostream& os, const BasicMatrix& obj); //put matrix to the stream 'os' ?
    protected:
        //fields
        int m;
        int n;
        double** A;
        //methods
        void allocateMem(); //allocate mem for matrix 'A'
        void freeMem(); //free mem of matrix 'A'
        void fill(double val=0); //fill matrix 'A' with value 'val', def value = 0
        void copyMatrixArray(double** source, double** destination); //copy values from source array to destination array
        void swap(double& a,double& b); //swap double numbers
        void swap(int& a,int& b); //swap int numbers
    };
}

#endif /* BasicMatrix_hpp */
