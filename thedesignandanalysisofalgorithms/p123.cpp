//
//  123.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/1.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution{
//public:
//    typedef int (Solution::*pfun)(vector<int> &,int,int);
//    int quickSelect(vector<int> nums,int k,int choice){
//        if(nums.empty()||nums.size()<k||k<=0) return -1;
//        pfun partition[]={&Solution::lomutoPartition,&Solution::CLRSPartition,&Solution::hoarePartition};
//        int knum=quickSelect(partition[choice],nums,0,nums.size()-1, k);
//        return knum;
//    }
//private:
//    int quickSelect(pfun partition,vector<int> &nums,int left,int right,int k){
//        int knum;
//        int pivotpos=(this->*partition)(nums, left, right);
//        if(pivotpos==left+k-1) return nums[pivotpos];
//        if(pivotpos<left+k-1) knum=quickSelect(partition, nums, pivotpos+1, right, k+left-pivotpos-1);
//        else knum=quickSelect(partition, nums, left, pivotpos-1, k);
//        return knum;
//    }
//    //Partition函数只会出现left<=right的情况
//    int lomutoPartition(vector<int> &nums,int left,int right){
//        int pivot=nums[left];
//        int pre=left;
//        for(int cur=left+1;cur<=right;++cur)
//            if(nums[cur]<pivot) swap(nums[++pre],nums[cur]);
//        swap(nums[left],nums[pre]);
//        return pre;
//    }
//    int CLRSPartition(vector<int> &nums,int left,int right){
//        int pivot=nums[right];
//        int pre=left-1;
//        for(int cur=left;cur<right;++cur)
//            if(nums[cur]<pivot) swap(nums[++pre],nums[cur]);
//        swap(nums[++pre],nums[right]);
//        return pre;
//    }
//    int hoarePartition(vector<int> &nums,int left,int right){
//        int pivot=nums[left];
//        while(left<right){
//            while(left<right&&nums[right]>=pivot) --right;
//            if(left<right) nums[left++]=nums[right];
//            while(left<right&&nums[left]<=pivot) ++left;
//            if(left<right) nums[right--]=nums[left];
//        }
//        nums[left]=pivot;
//        return left;
//    }
//};
//
//int main(int argc,const char *argv[]){
//    vector<int> nums={1,4,2,8,5,7,9,0,6,3};
//    char *funname[]={"lomutoPartition","CLRSPartition","hoarePartition"};
//    Solution s;
//    for(int i=0;i<3;++i){
//        cout<<"via "<<funname[i]<<": "<<endl;;
//        for(int j=1;j<=10;++j)
//            cout<<"The "<<j<<"th minimum of vector is: "<<s.quickSelect(nums,j,i)<<endl;
//        cout<<endl;
//    }
//    return 0;
//}
