//
//  p136.cpp
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
    typedef int (Solution::*pfun)(vector<int> &,int,int);
    void quickSort(vector<int> &nums,int choice){
        int left=0,right=nums.size()-1;
        pfun fun[]={&Solution::lomutoPartition,&Solution::hoarePartition,&Solution::crlsPartition};
        quickSort(fun[choice], nums, left, right);
    }
private:
    void quickSort(pfun partition,vector<int> &nums,int left,int right){
        if(left<right){
            int pivotpos=(this->*partition)(nums,left,right);
            quickSort(partition, nums, left, pivotpos-1);
            quickSort(partition, nums, pivotpos+1, right);
        }
    }
    int lomutoPartition(vector<int> &nums,int left,int right){
        int pivot=nums[left];
        int pre=left;
        for(int cur=left+1;cur<=right;++cur)
            if(nums[cur]<pivot) swap(nums[++pre],nums[cur]);
        swap(nums[left],nums[pre]);
        return pre;
    }
    int hoarePartition(vector<int> &nums,int left,int right){
        int pivot=nums[left];
        while(left<right){
            while(left<right&&nums[right]>=pivot) --right;
            if(left<right) nums[left++]=nums[right];
            while(left<right&&nums[left]<=pivot) ++left;
            if(left<right) nums[right--]=nums[left];
        }
        nums[left]=pivot;
        return left;
    }
    int crlsPartition(vector<int> &nums,int left,int right){
        int pivot=nums[right];
        int pre=left-1;
        for(int cur=left;cur<right;++cur)
            if(nums[cur]<=pivot) swap(nums[++pre],nums[cur]);
        swap(nums[++pre],nums[right]);
        return pre;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7,9,0,3,6};
    vector<int> dup;
    Solution s;
    for(int i=0;i<3;++i){
        dup=nums;
        s.quickSort(dup, i);
        for(auto num:dup) cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
