//
//  MatrixHandler.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include "MatrixHandler.hpp"

using namespace matrixxx;

//public
//constructors
MatrixHandler::MatrixHandler(){
    //do nothing
}
//methods
bool MatrixHandler::toLUDecomposition(Matrix matrix, Matrix& L, Matrix& U){
    if(matrix.isSquare()){
        int n=matrix.getN();
        for(int k=0;k<n-1; k++){
            for(int i=k+1;i<n;i++){
                matrix.setElem(i, k, matrix.getElem(i, k)/matrix.getElem(k, k));
                for(int j=k+1; j<n; j++){
                    matrix.setElem(i, j, matrix.getElem(i, j)-matrix.getElem(i, k)*matrix.getElem(k, j));
                }
            }
        }
        //set L
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j){
                    L.setElem(i, j, matrix.getElem(i, j));
                }
                else if(i<j){
                    L.setElem(i, j, 0);
                }
                else{
                    L.setElem(i, j, 1);
                }
            }
        }
        //set U
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j){
                    U.setElem(i, j, 0);
                }
                else{
                    U.setElem(i, j, matrix.getElem(i, j));
                }
            }
        }
        return true;
    }
    return false;
}
bool MatrixHandler::toLDLTDecomposition(Matrix matrix, Matrix& L, Matrix& D){
    if(matrix.isSquare() && matrix.isSymmetric()){
        int n=matrix.getN();
        Vector T(n); 
        for(int k=0; k<n-1;k++){
            for(int i=k+1; i<n; i++){
                T.setElem(i, matrix.getElem(i, k));
                matrix.setElem(i, k, matrix.getElem(i, k)/matrix.getElem(k, k));
                for(int j=k+1; j<i; j++){
                    matrix.setElem(i, j, matrix.getElem(i, j)-matrix.getElem(i, k)*T.getElem(j));
                }
            }
        }
        //set L
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j){
                    L.setElem(i, j, matrix.getElem(i, j));
                }
                else if (i<j){
                    L.setElem(i, j, 0);
                }
                else{
                    L.setElem(i, j, 1);
                }
            }
        }
        //set D
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    D.setElem(i, j, matrix.getElem(i, j));
                }
                else{
                    D.setElem(i, j, 0);
                }
            }
        }
        return true;
    }
    return false;
}
bool MatrixHandler::transpose(Matrix& matrix){
    if(matrix.isSquare()){
        return matrix.transposeAsSquare();
    }
    else{
        return matrix.transposeAsCommon();
    }
}
Matrix MatrixHandler::getTransposed(Vector vec){
    int n=vec.getN();
    Matrix matrix(n,1);
    for(int i=0;i<n; i++){
        matrix.setElem(i, 0, vec.getElem(i));
    }
    return matrix;
}
Matrix MatrixHandler::getTransposed(Matrix matrix){
    transpose(matrix);
    return matrix;
}
//private

//methods
