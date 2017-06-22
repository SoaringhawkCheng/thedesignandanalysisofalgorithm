//
//  p182.cpp
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
    int horner(vector<int> factor,int argument){
        int size=factor.size();
        int result=factor[size-1];
        for(int i=size-2;i>=0;--i)
            result=result*argument+factor[i];
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<int> factor={-5,1,-3,-1,2};
    int argument=3;
    Solution s;
    cout<<s.horner(factor, argument)<<endl;
    return 0;
}

