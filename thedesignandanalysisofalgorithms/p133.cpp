//
//  1_11.cpp
//  beautyofprogramming
//
//  Created by 追寻梦之碎片 on 2017/6/1.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void mergesort(vector<int> &nums){
        int left=0,right=nums.size()-1;
        mergesort(nums, left, right);
    }
private:
    void mergesort(vector<int> &nums,int left,int right){
        if(left<right){
            int mid=(left+right)/2;
            mergesort(nums, left, mid);
            mergesort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int> &nums,int left,int mid,int right){
        vector<int> buf;
        int i=left,j=mid+1,k=left;
        while(i<=mid&&j<=right){
            if(nums[i]<=nums[j]) buf.push_back(nums[i++]);
            else buf.push_back(nums[j++]);
        }
        while(i<=mid) buf.push_back(nums[i++]);
        while(j<=right) buf.push_back(nums[j++]);
        for(int k=0;k<buf.size();++k)
            nums[left+k]=buf[k];
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7,9,0,3,6};
    Solution s;
    s.mergesort(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
