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
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size=nums.size();
        vector<int> graycode=graycode2(size);
        for(int i=0;i<graycode.size();++i){
            result.push_back(vector<int>());
            for(int j=0;j<size;++j)
                if(graycode[i]&(1<<j)) result[i].push_back(nums[j]);
        }
        return result;
    }
private:
    vector<int> graycode1(int n){
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        for(int i=0;i<n;++i){
            int highest_bit=1<<i;
            for(int j=result.size()-1;j>=0;--j)
                result.push_back(highest_bit|result[j]);
        }
        return result;
    }
    vector<int> graycode2(int n){
        vector<int> result;
        for(int i=0;i<1<<n;++i)
            result.push_back(i^(i/2));
        return result;
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
