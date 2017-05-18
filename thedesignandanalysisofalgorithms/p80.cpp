//
//  p80.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/17.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    bool sequentialsearch(vector<int> nums,int target){
        nums.push_back(target);
        int i=0;
        while(nums[i]!=target) ++i;
        return i!=(nums.size()-1);
    }
    bool bruteforcestringmatch(string text,string pattern){
        int size1=text.size();
        int size2=pattern.size();
        for(int i=0;i<=size1-size2;++i){
            bool flag=true;
            for(int j=0;j<size2;++j)
                if(text[i+j]!=pattern[j]){
                    flag=false;
                    break;
                }
            if(flag) return true;
        }
        return false;
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    
    vector<int> nums={4,2,8,5,7,1};
    cout<<s.sequentialsearch(nums, 6)<<
    " "<<s.sequentialsearch(nums, 1)<<endl;
    string text="自是人生长恨水长东";
    string pattern="长恨";
    cout<<s.bruteforcestringmatch(text, pattern)<<endl;
    return 0;
}
