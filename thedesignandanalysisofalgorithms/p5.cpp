//
//  p5.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/16.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
//#include <algorithm>
using namespace std;

class Solution{
public:
    vector<int> sieve(int n){
        vector<int> nums(n+1,0);
        vector<int> result;
        for(int i=0;i<n+1;++i) nums[i]=i;
        for(int i=2;i<=n;++i){
            if(nums[i]){
                int num=nums[i];
                int j=num*num;
                while(j<=n){
                    nums[j]=0;
                    j=j+num;
                }
            }
        }
        for(int i=2;i<=n;++i)
            if(nums[i]) result.push_back(nums[i]);
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<int> result;
    Solution s;
    result=s.sieve(25);
    for(auto res:result) cout<<res<<" ";
    cout<<endl;
    return 0;
}
