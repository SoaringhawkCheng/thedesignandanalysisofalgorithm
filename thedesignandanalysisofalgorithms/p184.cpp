//
//  p184.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/5.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    double binaryExponentiation(double base,int index){//
        if(index==0) return 1;
        if(base==0) return 0;
        double result=binaryExponentiation(base, index>>1)*binaryExponentiation(base, index>>1);
        if(index&0x1) result*=base;
        cout<<"index="<<index<<", result="<<result<<endl;
        return result;
    }
    double leftRightBinaryExponentiation(double base,int index){
        if(index==0) return 1;
        if(base==0) return 0;
        int count=0;
        int mask=1;
        int pre_index=index;
        while(index){
            ++count;
            index>>=1;
            mask<<=1;
        }
        index=pre_index;
        mask>>=1;
        double result=1;
        for(int i=0;i<count;++i){
            result*=result;
            if(index&mask) result*=base;
            mask>>=1;
        }
        return result;
    }
    double rightLeftBinaryExponentiation(double base,int index){
        if(index==0) return 1;
        if(base==0) return 0;
        double result=1,product=base;
        while(index){
            if(index&0x1) result*=product;
            product*=product;
            index>>=1;
        }
        return result;
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    cout<<s.leftRightBinaryExponentiation(2.5, 5)<<endl;
    cout<<s.rightLeftBinaryExponentiation(2.5, 5)<<endl;
    return 0;
}
