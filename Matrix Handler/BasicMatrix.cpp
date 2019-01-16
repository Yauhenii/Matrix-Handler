//
//  BasicMatrix.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include "BasicMatrix.hpp"
#include <ctime>
#include <cstdlib>

using namespace matrixxx;

//public
//constructors
BasicMatrix::BasicMatrix(int m,int n){
    this->m=m;
    this->n=n;
    allocateMem();
}
BasicMatrix::BasicMatrix(int m,int n, double val){
    this->m=m;
    this->n=n;
    allocateMem();
    fill();
}
BasicMatrix::BasicMatrix(const BasicMatrix &obj){
    m=obj.m;
    n=obj.n;
    allocateMem();
    copyMatrixArray(obj.A, A);
}
//destructor
BasicMatrix::~BasicMatrix(){
    freeMem();
}
//methods
//void BasicMatrix::fillWithRandomNumbers(int val){
//    int dVal=val*2;
//    srand(static_cast<unsigned int>(time(NULL)));
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            A[i][j]=(double)(rand() % dVal -val+1);
//        }
//    }
//}
void BasicMatrix::fillWithRandomPositiveNumbers(int val){
    srand(static_cast<unsigned int>(time(NULL)));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=(double)(rand() % val + 1);
        }
    }
}
void BasicMatrix::transpose(){
    if(m==n){
        transposeAsSquare();
    }
    else{
        transposeAsCommon();
    }
}
BasicMatrix BasicMatrix::getTransposedMatrix(){
    BasicMatrix matrix(*this);
    matrix.transpose();
    return matrix;
}
//operators

//private
//methods
void BasicMatrix::allocateMem(){
    A=new double*[m];
    for(int i=0;i<m;i++){
        A[i]=new double[n];
    }
}
void BasicMatrix::freeMem(){
    for(int i = 0; i < m; i++){
        delete [] A[i];
    }
    delete [] A;
}
void BasicMatrix::fill(double val){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=val;
        }
    }
}
void BasicMatrix::copyMatrixArray(double **source, double **destination){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            destination[i][j]=source[i][j];
        }
    }
}
void BasicMatrix::swap(double& a, double& b){
    double temp=a;
    a=b;
    b=temp;
}
void BasicMatrix::swap(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
void BasicMatrix::transposeAsSquare(){
    for(int i=0; i<m; i++){
        for(int j=0; j<i; j++){
            swap(A[i][j], A[j][i]);
        }
    }

}
void BasicMatrix::transposeAsCommon(){
    double** A = new double*[n];
    for(int i=0; i<n;i++){
        A[i]=new double[m];
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[j][i]=this->A[i][j];
        }
    }
    this->freeMem();
    this->A=A;
    swap(m,n);
}
