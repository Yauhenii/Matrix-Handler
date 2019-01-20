//
//  BasicMatrix.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include "BasicMatrix.hpp"

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
    fill(val);
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
void BasicMatrix::fillWithRandomPositiveNumbers(int maxVal){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=(double)(rand() % maxVal + 1);
        }
    }
}
void BasicMatrix::fillWithRandomPositiveNumbersSymmetric(int maxVal){
    for(int i=0; i<m; i++){
        for(int j=0; j<i; j++){
            A[i][j]=A[j][i]=(double)(rand() % maxVal + 1);
        }
        A[i][i]=(double)(rand() % maxVal + 1);
    }
}
bool BasicMatrix::multiplyBy(BasicMatrix obj){
    if(n==obj.m){  //this:= m x n, obj:= obj.m X obj.n
        double** A = new double*[m];
        for(int i=0; i<m;i++){
            A[i]=new double[obj.n];
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<obj.n; j++){
                A[i][j]=0;
                for(int k=0;k<n;k++){
                    A[i][j]+=this->A[i][k]*obj.A[k][j];
                }
            }
        }
        
        this->freeMem();
        this->A=A;
        n=obj.n;
        
        return true;
    }
    else{
        return false;
    }
}
bool BasicMatrix::transposeAsSquare(){
    if(m==n){
        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                swap(A[i][j], A[j][i]);
            }
        }
        return true;
    }
    return false;
}
bool BasicMatrix::transposeAsCommon(){
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
    return true;
}
//operators

//protected
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
