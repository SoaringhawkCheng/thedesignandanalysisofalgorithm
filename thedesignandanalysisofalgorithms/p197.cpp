//
//  p197.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void comparisonCountingSort(vector<int> &nums){
        int size=nums.size();
        vector<int> count(size,0);
        for(int i=0;i<size-1;++i){
            for(int j=i+1;j<size;++j){
                if(nums[i]<=nums[j])
                    count[j]=count[j]+1;
                else
                    count[i]=count[i]+1;
            }
        }
        vector<int> sorted(size,0);
        for(int i=0;i<size;++i)
            sorted[count[i]]=nums[i];
        nums=sorted;
    }
    void distributionCountingSort(vector<int> &nums,int lowerbound,int upperbound){
        int size=nums.size();
        int bucketsize=upperbound-lowerbound+1;
        vector<int> count(bucketsize,0);
        for(int i=0;i<size;++i)
            ++count[nums[i]-lowerbound];
        for(int i=1;i<bucketsize;++i)
            count[i]+=count[i-1];
        vector<int> sorted(size,0);
        for(int i=size-1;i>=0;--i){
            int offset=nums[i]-lowerbound;
            sorted[count[offset]-1]=nums[i];
            --count[offset];
        }
        nums=sorted;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={4,2,8,5,7,1,5,1,7};
    Solution s;
    s.distributionCountingSort(nums, 0, 9);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
