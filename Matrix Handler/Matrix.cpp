//
//  Matrix.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include "Matrix.hpp"

using namespace matrixxx;

//public
//constructors
Matrix::Matrix(int m,int n) : BasicMatrix(m,n){
}
Matrix::Matrix(int m,int n, double val) : BasicMatrix(m,n){
}
Matrix::Matrix(const Matrix &obj) : BasicMatrix(obj){
}
//methods
int Matrix::getM(){
    return m;
}
int Matrix::getN(){
    return n;
}
double Matrix::getElem(int i, int j){
    return A[i][j];
}
double Matrix::setElem(int i,int j, double val){
    double prevValue=A[i][j];
    A[i][j]=val;
    return prevValue;
}
bool Matrix::isSquare(){
    return m==n;
}
bool Matrix::isSymmetric(){
    if(isSquare()){
        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                if(A[i][j]!=A[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
double Matrix::getTrace(){
    double trace=0;
    if(isSquare()){
        for(int i=0;i<n;i++){
            trace+=A[i][i];
        }
    }
    else{
        int i=0;
        while(i<m && i<n){
            trace+=A[i][i];
        }
    }
    return trace;
}
Matrix Matrix::getSubMatrix(int m, int n){
    Matrix subMatrix(m,n,0);
    if(m<this->m && n<this->n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                subMatrix.A[i][j]=this->A[i][j];
            }
        }
    }
    else if(m==this->m && n==this->n){
        return *this;
    }
    return subMatrix;
}
