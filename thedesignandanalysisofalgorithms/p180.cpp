//
//  p180.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/5.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    typedef void(Solution::*pFun)(vector<int>&);
public:
    void heapSort(vector<int> &nums,bool choice){
        vector<int> dup(nums);
        buildHeap(dup,choice);
        vector<int> result;
        for(int i=0;i<nums.size();++i)
            result.push_back(deleteRoot(dup));
        nums=result;
    }
private:
    void buildHeap(vector<int> &dup,bool choice){
        pFun fun[]={&Solution::heapBottomUp,&Solution::heapTopDown};
        (this->*fun[choice])(dup);
    }
    void heapBottomUp(vector<int> &nums){
        int size=nums.size();
        for(int pos=(size-1)/2;pos>=0;--pos)
            percDown(nums,pos);
    }
    void heapTopDown(vector<int> &nums){
        int size=nums.size();
        for(int pos=1;pos<size;++pos)
            percUp(nums,pos);
    }
    void percUp(vector<int> &nums,int pos){
        int tmp=nums[pos];
        int flag=true;
        while(flag&&pos){
            int parent=(pos-1)/2;
            if(tmp>nums[parent]){
                nums[pos]=nums[parent];
                pos=parent;
            }
            else flag=false;
        }
        nums[pos]=tmp;
    }
    void percDown(vector<int> &nums,int pos){
        int tmp=nums[pos];
        int flag=true;
        int size=nums.size();
        while(flag&&2*pos+1<size){
            int child=2*pos+1;
            if(child+1<size&&nums[child]<nums[child+1]) child=child+1;
            if(tmp<nums[child]){
                nums[pos]=nums[child];
                pos=child;
            }
            else flag=false;
        }
        nums[pos]=tmp;
    }
    int deleteRoot(vector<int> &nums){
        int result=nums[0];
        swap(nums[0],nums[nums.size()-1]);
        nums.pop_back();
        percDown(nums, 0);
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={4,2,8,5,7,1,0,3,6,9};
    vector<int> sorted(nums);
    Solution s;
    s.heapSort(sorted, 0);
    for(auto num:sorted) cout<<num<<" ";
    cout<<endl;
    sorted=nums;
    s.heapSort(sorted, 1);
    for(auto num:sorted) cout<<num<<" ";
    cout<<endl;
    return 0;
}
