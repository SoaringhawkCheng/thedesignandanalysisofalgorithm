//
//  p76.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/17.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    void selectionsort(vector<int> &nums){
        for(int i=0;i<nums.size()-1;++i){
            int min=i;
            for(int j=i+1;j<nums.size();++j)
                if(nums[j]<nums[min]) min=j;
            swap(nums[i],nums[min]);
        }
    }
    void bubblesort(vector<int> &nums){
        for(int i=0;i<nums.size()-1;++i){
            bool flag=false;
            for(int j=nums.size()-1;j>i;--j)
                if(nums[j]<nums[j-1]){
                    swap(nums[j-1],nums[j]);
                    flag=true;
                }
            if(!flag) break;
        }
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7,9,0,3,6};
    Solution s;
    s.selectionsort(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    nums={1,4,2,8,5,7,9,0,3,6};
    s.bubblesort(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
