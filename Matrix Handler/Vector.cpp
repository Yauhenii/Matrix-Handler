//
//  Vector.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include "Vector.hpp"

using namespace matrixxx;

//public
//constructors
Vector::Vector(int n) : BasicMatrix(1,n){
}
Vector::Vector(int n, double val) : BasicMatrix(1,n,val){
}
Vector::Vector(const Vector &obj) : BasicMatrix(obj){
}
//methods
int Vector::getN(){
    return n;
}
double Vector::getElem(int i){
    return A[0][i];
}
void Vector::setElem(int i, double val){
    A[0][i]=val;
}
