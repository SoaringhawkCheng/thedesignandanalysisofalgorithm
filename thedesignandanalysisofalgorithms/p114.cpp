//
//  p114.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/19.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generatesubset(vector<int> nums){
        vector<vector<int>> result;
        if(nums.empty()) return result;
        vector<int> graycode=graycode1(nums.size());
        for(int i=0;i<graycode.size();++i){
            vector<int> subset;
            int bit=1;
            for(int j=0;j<nums.size();++j){
                if(graycode[i]&bit) subset.push_back(nums[j]);
                bit<<=1;
            }
            result.push_back(subset);
        }
        return result;
    }
private:
    vector<int> graycode1(int n){
        vector<int> graycode;
        int size=1<<n;
        graycode.reserve(size);
        for(int i=0;i<size;++i)
            graycode.push_back(i^(i>>1));
        return graycode;
    }
    vector<int> graycode2(int n){
        vector<int> graycode;
        graycode.reserve(1<<n);
        graycode.push_back(0);
        int highest_bit=1;
        for(int i=0;i<n;++i){
            for(int j=highest_bit-1;j>=0;--j)
                graycode.push_back(highest_bit|graycode[j]);
            highest_bit<<=1;
        }
//        for(auto code:graycode) cout<<code<<endl;
//        cout<<endl;
        return graycode;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7};
    Solution s;
    vector<vector<int>> result=s.generatesubset(nums);
    for(auto res:result){
        for(auto r:res) cout<<r<<" ";
        cout<<endl;
    }
    return 0;
}
