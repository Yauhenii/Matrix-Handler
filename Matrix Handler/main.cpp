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

using namespace matrixxx;
using namespace std;

namespace matrixxx {
    
std::ostream& operator<<(std::ostream& os, const BasicMatrix& obj){
    for(int i=0;i<obj.m;i++){
        for(int j=0;j<obj.n;j++){
            os<<obj.A[i][j]<<std::setw(6); //setprecision(3)
        }
        os<<endl;
    }
    return os;
}
    
}

using namespace matrixxx;

int main(int argc, const char * argv[]) {
    BasicMatrix m(5,2);
    m.fillWithRandomPositiveNumbers(3);
    BasicMatrix n(m);
    cout<<m<<endl;
    cout<<n.getTransposedMatrix();
    return 0;
}
