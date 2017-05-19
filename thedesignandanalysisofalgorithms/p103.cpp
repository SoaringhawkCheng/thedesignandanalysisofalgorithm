//
//  103.cpp
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
    void InsertionSort(vector<int> &nums){
        for(int i=1;i<nums.size();++i){
            int tmp=nums[i];
            int j;
            for(j=i-1;j>=0&&nums[j]>=tmp;--j)
                nums[j+1]=nums[j];
            nums[j+1]=tmp;
        }
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7,9,0,6,3};
    Solution s;
    s.InsertionSort(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
