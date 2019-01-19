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
void Matrix::setElem(int i,int j, double val){
    A[i][j]=val;
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
