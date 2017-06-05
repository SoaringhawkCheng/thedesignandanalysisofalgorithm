//
//  p116.cpp
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
    int binarysearch(vector<int> nums, int target){
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,4,2,8,5,7};
    sort(nums.begin(),nums.end());
    Solution s;
    cout<<s.binarysearch(nums, 9)<<endl;
    cout<<s.binarysearch(nums, 1)<<endl;
    cout<<s.binarysearch(nums, 2)<<endl;
    cout<<s.binarysearch(nums, 4)<<endl;
    cout<<s.binarysearch(nums, 5)<<endl;
    cout<<s.binarysearch(nums, 7)<<endl;
    cout<<s.binarysearch(nums, 8)<<endl;
    return 0;
}
