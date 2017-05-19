//
//  p104.cpp
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
    void shellsort(vector<int> &nums){
        for(int stepsize=nums.size()/2;stepsize>=1;stepsize/=2){
            for(int i=stepsize;i<=nums.size()-1;++i){
                int tmp=nums[i];
                int j=i-stepsize;
                while(j>=0&&nums[j]>=tmp){
                    nums[j+stepsize]=nums[j];
                    j-=stepsize;
                }
                nums[j+stepsize]=tmp;
            }
        }
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7,9,0,3,6};
    Solution s;
    s.shellsort(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
