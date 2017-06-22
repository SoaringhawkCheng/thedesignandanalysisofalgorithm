//
//  p188.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/5.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int gcd(int m,int n){
        if(m==0|n==0) return -1;
        while(n){
            int tmp=m%n;
            m=n;
            n=tmp;
        }
        return abs(m);
    }
    int lcm(int m,int n){
        if(m==0|n==0) return -1;
        return abs(m*n/gcd(m,n));
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    cout<<s.gcd(60, -12)<<" "<<s.lcm(-60, 24)<<endl;
    return 0;
}
