//
//  p118.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/19.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    long long russiamultiply(long long left,long long right){
        if(right<left) return russiamultiply(right, left);
        if(left==1) return right;
        if(left%2) return russiamultiply((left-1)>>1, right<<1)+right;
        else return russiamultiply(left>>1, right<<1);
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    cout<<s.russiamultiply(50, 65)<<endl;
    return 0;
}
