//
//  main.cpp
//  Matrix Handler
//
//  Created by Zhenya Mordan on 1/16/19.
//  Copyright © 2019 Matrixxx. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "MatrixHandler.hpp"

#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace matrixxx;
using namespace std;

namespace matrixxx {
    
std::ostream& operator<<(std::ostream& os, const BasicMatrix& obj){
    for(int i=0;i<obj.m;i++){
        for(int j=0;j<obj.n;j++){
            os<<std::setw(10)<<obj.A[i][j]; //setprecision(3)
        }
        os<<endl;
    }
    return os;
}
    
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    
    Matrix A(3,3);
    A.fillWithRandomPositiveNumbersSymmetric(3);
    MatrixHandler matrixHandler;
    cout<<A<<endl;
    int n=A.getM();
    Matrix L(n,n),U(n,n),L1(n,n),D(n,n);
    if(matrixHandler.toLUDecomposition(A, L, U)){
        cout<<L<<endl;
        cout<<U<<endl;
    }
    if(matrixHandler.toLDLTDecomposition(A, L1, D)){
        cout<<L1<<endl;
        cout<<D<<endl;
    }
    return 0;
}


