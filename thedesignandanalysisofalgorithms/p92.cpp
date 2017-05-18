//
//  p92.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> taskassignment(vector<vector<int>> &matrix){
        vector<int> seq={0,1,2,3};
        vector<vector<int>> result;
        int mincost=INT_MAX;
        do{
            int cost=computecost(matrix,seq);
            if(cost==mincost) result.push_back(seq);
            else if(cost<mincost){
                mincost=cost;
                result.clear();
                result.push_back(seq);
            }
        }while(next_permutation(seq));
        return result;
    }
private:
    int computecost(vector<vector<int>> &matrix,vector<int> &seq){
        int result=0;
        for(int i=0;i<seq.size();++i){
            result+=matrix[i][seq[i]];
        }
        return result;
    }
    bool next_permutation(vector<int> &seq){
        if(seq.empty()) return false;
        auto pos=next(seq.rbegin());
        while(pos!=seq.rend()&&*pos>=*prev(pos)) advance(pos, 1);
        if(pos==seq.rend()) return false;
        auto change=find_if(seq.rbegin(), pos, bind1st(less<int>(),*pos));
        iter_swap(pos, change);
        reverse(seq.rbegin(), pos);
        return true;
    }
};

int main(int argc,const char *argv[]){
    vector<vector<int>> matrix={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    vector<vector<int>> result;
    Solution s;
    result=s.taskassignment(matrix);
    for(auto res:result){
        for(auto r:res) cout<<r<<" ";
        cout<<endl;
    }
}
