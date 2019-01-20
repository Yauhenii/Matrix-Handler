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
    
    Vector vec1(3),vec2(3, 3);
    vec1.fillWithRandomPositiveNumbers(5);
    Vector vec3(vec1);
    cout<<"1:"<<vec1<<endl<<"2:"<<vec2<<endl<<"3:"<<vec3<<endl;
    vec3.setElem(2, 100);
    cout<<"1:"<<vec1<<endl<<"2:"<<vec2<<endl<<"3:"<<vec3<<endl;
    MatrixHandler matrixHandler;
    cout<<matrixHandler.getTransposed(vec3)<<endl;
    return 0;
}


